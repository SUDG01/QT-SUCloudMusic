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
    , m_timer(new QTimer(this))
{
    ui->setupUi(this);
    ui->Musiclist->setModel(m_Listmodel);

    m_mediaPlayer->setAudioOutput(m_audioOutput);
    connect(ui->addMusic, &QPushButton::clicked, this, &SUmusic::on_addMusic_clicked);
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
        if (status == QMediaPlayer::EndOfMedia) {
            on_music_next_clicked();
        }
    });


    auto path1 = "Music";
    QDirIterator it(path1,{"*.mp3","*.wav","*.ogg"});
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
    QDirIterator it(path,{"*.mp3","*.wav","*.ogg"});
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


void SUmusic::on_volum_slide_sliderMoved(int position)
{

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
    qDebug() << "正在播放：" << item->text();
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

void SUmusic::on_pushButton_clicked()
{
    QString folderPath = "Music"; // 替换为你要打开的文件夹路径
    QDesktopServices::openUrl(QUrl::fromLocalFile(folderPath));
}


void SUmusic::on_addMusic_clicked()
{
    QString currentPath = QDir::currentPath();
    QString exePath = currentPath + "/dlmusic.exe";
    QString text = ui->usrInput->toPlainText();
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(text);
    QProcess *process = new QProcess(this);
    process->start(exePath);
    if (!process->waitForStarted()) {
        delete process; // 释放进程对象
    } else {
        qDebug() << "dlmusic.exe 启动成功！";
        QMessageBox::information(this,"提示","添加成功！请等待一段时间后点击reload按钮刷新列表");
        }
}


void SUmusic::onTimerTimeout()
{

}



