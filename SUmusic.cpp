#include "SUmusic.h"
#include "./ui_SUmusic.h"
#include <QFileDialog>
#include <QDirIterator>
#include <QDir>
#include <QList>
#include <string.h>
#include <QModelIndex>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QImage>
#include <QClipboard>
#include <QProcess>
#include <QTimer>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QMainWindow>
#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>
#include <QRandomGenerator>








QString SUmusic::formatTime(qint64 timeMs)
{
    int seconds = static_cast<int>(timeMs / 1000);
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    seconds = seconds % 60;

    return QString("%1:%2:%3")
        .arg(hours, 2, 10, QChar('0'))
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));
}

SUmusic::SUmusic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SUmusic)
    ,m_Listmodel(new QStandardItemModel(this))
    ,m_mediaPlayer(new QMediaPlayer(this))
    ,m_audioOutput(new QAudioOutput(this))
    ,m_timer(new QTimer(this))
    ,isDragging(false)
{

    ui->setupUi(this);


    ui->songMode->addItem("列表循环");
    ui->songMode->addItem("单曲循环(beta)");
    ui->songMode->addItem("随机播放(beta)");


    ui->Musiclist->setModel(m_Listmodel);
    setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);

    titleLabel = ui->headBar;

    m_mediaPlayer->setAudioOutput(m_audioOutput);
    connect(m_mediaPlayer, &QMediaPlayer::metaDataChanged, this, &SUmusic::updateCoverArt);
    connect(m_timer, &QTimer::timeout, this, &SUmusic::onTimerTimeout);
    m_timer->start(1000);
    m_audioOutput->setVolume(0.5);
    ui->volum_slide->setRange(0,100);
    ui->volum_slide->setValue(50);
    connect(ui->volum_slide, &QSlider::valueChanged, this, &SUmusic::on_volum_slide_valueChanged);

    ui->musicslider->setRange(0,0);

    connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, [=](qint64 duration) {
        ui->all_long->setText(formatTime(duration));  // 更新总长度标签
        ui->musicslider->setRange(0, static_cast<int>(duration));
    });

    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, [=](qint64 position) {
        ui->now_long->setText(formatTime(position));  // 更新当前时间标签
        ui->musicslider->setValue(static_cast<int>(position));
    });

    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, [=](qint64 position) {
        ui->musicslider->setValue(static_cast<int>(position));
    });

    connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, [=](qint64 duration) {
        ui->musicslider->setRange(0, static_cast<int>(duration));
    });

    connect(ui->musicslider, &QSlider::sliderMoved, this, &SUmusic::on_musicslider_sliderMoved);

    connect(m_mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status) {
        int ListViewNums = m_itemList.count();
        auto nowIndex = ui->songMode->currentIndex();
        int randomIndex = QRandomGenerator::global()->bounded(ListViewNums);
        if(nowIndex==0){
            if (status == QMediaPlayer::EndOfMedia) {
                on_music_next_clicked();
            }
        }
        else if(nowIndex==1){
            if(status == QMediaPlayer::EndOfMedia){
                on_music_start_clicked();
            }
        }
        else if(nowIndex==2){
            qDebug() << "随机数为" << randomIndex;
            if(status == QMediaPlayer::EndOfMedia){
                SUmusic::playMusicAtIndex(randomIndex);
            }
        }
    });


    auto path1 = "Music";
    QDirIterator it(path1,{"*.mp3","*.wav","*.ogg","*.m4a","*.flac","*aac"});
    while(it.hasNext()){
        auto info = it.nextFileInfo();
        QString fullName = info.fileName();

        int lastDotIndex = fullName.lastIndexOf('.');
        QString musicName = (lastDotIndex != -1) ? fullName.left(lastDotIndex) : fullName;
        auto item = new QStandardItem(musicName);
        item->setData(info.canonicalFilePath());   //路径

        m_Listmodel->appendRow(item);
        m_itemList.append(item);
    }

}

SUmusic::~SUmusic()
{
    delete ui;
}



void SUmusic::on_reload_clicked()
{
    m_Listmodel->clear();
    m_itemList.clear();
    auto path = "Music";
    QDirIterator it(path,{"*.mp3","*.wav","*.ogg","*.m4a","*.flac","*aac"});
    while(it.hasNext()){
        auto info = it.nextFileInfo();
        QString fullName = info.fileName();

        int lastDotIndex = fullName.lastIndexOf('.');
        QString musicName = (lastDotIndex != -1) ? fullName.left(lastDotIndex) : fullName;
        auto item = new QStandardItem(musicName);
        item->setData(info.canonicalFilePath());   //路径

        m_Listmodel->appendRow(item);
        m_itemList.append(item);
    }
}


void SUmusic::on_Musiclist_doubleClicked(const QModelIndex &index)
{
    playMusicAtIndex(index.row());
    auto item = m_itemList.at(index.row());
    auto url1 = index.data(Qt::UserRole+1).toUrl();

    m_mediaPlayer->setSource(url1);
    m_mediaPlayer->play();

    ui->all_long->setText("00:00:00");
    ui->now_long->setText("00:00:00");
    ui->musicslider->setValue(0);
}


void SUmusic::on_music_start_clicked()
{
    QModelIndexList selectIndexes = ui->Musiclist->selectionModel()->selectedIndexes();

    if (selectIndexes.isEmpty()) {
        // 如果没有选中任何音乐
        if (m_Listmodel->rowCount() > 0) {
            // 默认播放第一首音乐
            auto firstItem = m_Listmodel->item(0);
            auto url1 = firstItem->data(Qt::UserRole + 1).toUrl();
            m_mediaPlayer->setSource(url1);
            ui->Musiclist->setCurrentIndex(m_Listmodel->index(0, 0));  // 设置选中状态
            ui->musicslider->setValue(0);  // 初始化进度条
            ui->now_long->setText("00:00:00");  // 初始化当前时间显示
            m_mediaPlayer->play();
            return;
        } else {
            return;
        }
    }

    // 正常播放选中的音乐
    auto selectedItem = selectIndexes.first();
    auto url1 = m_Listmodel->item(selectedItem.row())->data(Qt::UserRole + 1).toUrl();

    if (m_mediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        m_mediaPlayer->pause();
    } else {
        if (m_mediaPlayer->source() != url1) {
            m_mediaPlayer->setSource(url1);
            ui->musicslider->setValue(0);
            ui->now_long->setText("00:00:00");
        }
        m_mediaPlayer->play();
    }
}





void SUmusic::on_volum_slide_valueChanged(int value)
{
    float volume = value / 100.0f;
    m_audioOutput->setVolume(volume);
}


void SUmusic::on_musicslider_sliderMoved(int position)
{
    m_mediaPlayer->setPosition(static_cast<qint64>(position));
}


void SUmusic::on_musicslider_valueChanged(int value)
{
    ui->music_start->setChecked(true);
    if(value == ui->musicslider->maximum()){
        ui->music_start->setChecked(false);
    }
}


void SUmusic::on_about_clicked()
{
    aboutWidget.show();
}





void SUmusic::on_music_next_clicked()
{
    if (m_itemList.isEmpty()) {
        return;
    }

    int nextIndex = (m_currentIndex + 1) % m_itemList.size();
    playMusicAtIndex(nextIndex);
}

void SUmusic::playMusicAtIndex(int index)
{
    if (index < 0 || index >= m_itemList.size()) {
        return;
    }

    auto item = m_itemList.at(index);
    auto url = item->data(Qt::UserRole + 1).toUrl();

    m_mediaPlayer->setSource(url);
    m_mediaPlayer->play();

    m_currentIndex = index;
    ui->Musiclist->setCurrentIndex(m_Listmodel->index(index, 0));
}



void SUmusic::on_music_previews_clicked()
{
    if (m_itemList.isEmpty()) {
        return;
    }
    int prevIndex = (m_currentIndex - 1 + m_itemList.size()) % m_itemList.size();
    playMusicAtIndex(prevIndex);
}


void SUmusic::updateCoverArt()
{

    QMediaMetaData metaData = m_mediaPlayer->metaData();
    QVariant coverVariant = metaData.value(QMediaMetaData::CoverArtImage);

    if (coverVariant.isValid()) {
        QImage coverImage = coverVariant.value<QImage>();
        if (!coverImage.isNull()) {
            ui->MuCover->setPixmap(QPixmap::fromImage(coverImage).scaled(ui->MuCover->size(), Qt::KeepAspectRatio));
            qDebug() << "Cover image loaded successfully.";
        } else {
            qDebug() << "Cover image is null.";
        }
    } else {
        qDebug() << "No cover image found in metadata.";
        // 设置默认封面
        ui->MuCover->setPixmap(QPixmap(":/icon/4SUmusic/default_cover.png").scaled(ui->MuCover->size(), Qt::KeepAspectRatio));
    }
}

void SUmusic::on_open_file_clicked()
{
    QString folderPath = "Music";
    QDesktopServices::openUrl(QUrl::fromLocalFile(folderPath));
}


void SUmusic::on_addMusic_clicked()
{
    QString currentPath = QDir::currentPath();
    QString exePath = currentPath + "/dlmusic.exe";
    QString text = ui->usrInput->toPlainText();
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString anti_Clipboard = clipboard->text();
    clipboard->setText(text);
    QProcess *process = new QProcess(this);

    process->start(exePath);
    if (!process->waitForStarted()) {
        delete process;
        QMessageBox::critical(this,"Error","启动下载进程出错");
    }else{
        QMessageBox::information(this,"提示","添加成功，请点击刷新以更新列表");
    }
    connect(process, &QProcess::finished, process, &QObject::deleteLater);
    clipboard->setText(anti_Clipboard);
}


void SUmusic::onTimerTimeout()
{

}





void SUmusic::on_del_music_clicked()
{
    QModelIndexList selectIndexes = ui->Musiclist->selectionModel()->selectedIndexes();
    if(selectIndexes.isEmpty()){
        QMessageBox::information(this,"提示","请选中要删除的音乐");
        return;
    }
    else{
        auto selectedItem = selectIndexes.first();
        auto url1 = m_Listmodel->item(selectedItem.row())->data(Qt::UserRole + 1).toUrl();
        QString url2 = url1.toString();
        if(QFile::exists(url2)){
            QFile::remove(url2);
            if(QFile::exists(url2)){
                QMessageBox::warning(this,"错误","音乐删除失败,请切换歌曲释放占用后再进行删除");
            }
            else{
                QMessageBox::information(this,"提示","音乐删除成功");
            }
        }
        else{
            QMessageBox::warning(this,"错误","删除失败，请确认文件是否存在");
        }
        m_Listmodel->clear();
        m_itemList.clear();
        auto path = "Music";
        QDirIterator it(path,{"*.mp3","*.wav","*.ogg","*.m4a","*.flac","*aac"});
        while(it.hasNext()){
            auto info = it.nextFileInfo();
            QString fullName = info.fileName();

            int lastDotIndex = fullName.lastIndexOf('.');
            QString musicName = (lastDotIndex != -1) ? fullName.left(lastDotIndex) : fullName;
            auto item = new QStandardItem(musicName);
            item->setData(info.canonicalFilePath());   //路径

            m_Listmodel->appendRow(item);
            m_itemList.append(item);
        }
    }
    }



void SUmusic::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}


void SUmusic::on_closeWindow_clicked()
{
    auto choose = QMessageBox::question(this,"SU云音乐","确认退出？",QMessageBox::Yes,QMessageBox::No);
    if(choose == QMessageBox::Yes){
        QApplication::exit();
    }
}


void SUmusic::on_minWindow_clicked()
{
    this->showMinimized();
}

void SUmusic::mousePressEvent(QMouseEvent *event)
{
    // 检查鼠标是否按下在标题栏区域
    if (event->button() == Qt::LeftButton && titleLabel->geometry().contains(event->pos())) {
        isDragging = true; // 开始拖动
        dragStartPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept(); // 接受事件
    }
}

void SUmusic::mouseMoveEvent(QMouseEvent *event)
{
    if (isDragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPosition().toPoint() - dragStartPosition);
        event->accept(); // 接受事件
    }
}

void SUmusic::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = false; // 停止拖动
        event->accept(); // 接受事件
    }
}





void SUmusic::on_pushButton_clicked()
{
    ui->now_long->setText("00:00:00");
    ui->all_long->setText("00:00:00");
    ui->musicslider->setValue(0);
    sender()->deleteLater();
}

