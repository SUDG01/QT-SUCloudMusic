#ifndef SUMUSIC_H
#define SUMUSIC_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <qlabel.h>
#include "about1.h"
#include <QMediaMetaData>
#include <QImage>
#include <QTimer>
#include <QMouseEvent>
#include <QApplication>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class SUmusic;
}
QT_END_NAMESPACE

class SUmusic : public QMainWindow
{
    Q_OBJECT



public:
    SUmusic(QWidget *parent = nullptr);
    ~SUmusic();


    void playMusicAtIndex(int index);
    void updateCoverArt();




private slots:

    void onTimerTimeout();

    virtual void paintEvent(QPaintEvent *event) override;

    void on_reload_clicked();

    void on_Musiclist_doubleClicked(const QModelIndex &index);

    void on_music_start_clicked();

    void on_volum_slide_valueChanged(int value);

    void on_musicslider_sliderMoved(int position);

    void on_musicslider_valueChanged(int value);

    void on_about_clicked();

    void on_music_next_clicked();

    void on_music_previews_clicked();

    void on_addMusic_clicked();

    void on_open_file_clicked();

    void on_del_music_clicked();

    void on_closeWindow_clicked();

    void on_minWindow_clicked();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);



    void on_pushButton_clicked();

private:
    Ui::SUmusic *ui;
    QStandardItemModel *m_Listmodel;
    QMediaPlayer *m_mediaPlayer{};
    QAudioOutput *m_audioOutput{};
    QList<QStandardItem*> m_itemList;
    QString formatTime(qint64 timeMs);
    About1 aboutWidget;
    int m_currentIndex = -1;
    QLabel *coverLabel;
    QTimer *m_timer;
    QStringList m_fileList;
    QLabel *titleLabel;       // 用于拖动窗口的 QLabel
    bool isDragging;          // 是否正在拖动窗口
    QPoint dragStartPosition; // 鼠标拖动的起始位置

};
#endif // SUMUSIC_H
