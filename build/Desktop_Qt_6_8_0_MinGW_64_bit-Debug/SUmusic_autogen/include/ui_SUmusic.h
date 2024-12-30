/********************************************************************************
** Form generated from reading UI file 'SUmusic.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMUSIC_H
#define UI_SUMUSIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SUmusic
{
public:
    QWidget *centralwidget;
    QListView *Musiclist;
    QWidget *widget;
    QPushButton *music_start;
    QPushButton *music_previews;
    QPushButton *music_next;
    QLabel *all_long;
    QPushButton *reload;
    QLabel *now_long;
    QLabel *yinliang;
    QSlider *musicslider;
    QPushButton *about;
    QLabel *MuCover;
    QTextEdit *usrInput;
    QPushButton *addMusic;
    QPushButton *open_file;
    QPushButton *del_music;
    QSlider *volum_slide;
    QLabel *headBar;
    QPushButton *closeWindow;
    QPushButton *minWindow;
    QLabel *Introduction;
    QComboBox *songMode;
    QPushButton *pushButton;

    void setupUi(QMainWindow *SUmusic)
    {
        if (SUmusic->objectName().isEmpty())
            SUmusic->setObjectName("SUmusic");
        SUmusic->setEnabled(true);
        SUmusic->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SUmusic->sizePolicy().hasHeightForWidth());
        SUmusic->setSizePolicy(sizePolicy);
        SUmusic->setMinimumSize(QSize(1280, 720));
        SUmusic->setMaximumSize(QSize(1280, 720));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(11);
        font.setBold(true);
        font.setKerning(true);
        SUmusic->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/4SUmusic/rainy_headicon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        SUmusic->setWindowIcon(icon);
        SUmusic->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(212,212,212);\n"
"}\n"
"\n"
"\n"
"QMainWindow{         /*\347\261\273\345\220\215*/\n"
"    background-color:rgb(243,244,246); \n"
"    border-radius: 10px;             /*\345\233\233\350\247\222\345\234\206\350\247\222\347\232\204\347\233\264\345\276\204*/\n"
"    border-style:solid;             /*\350\276\271\346\241\206\346\240\267\345\274\217\357\274\210\345\256\236\347\272\277\357\274\211*/\n"
"    border-width:2px;             /*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:rgb(213, 213, 213);\n"
"}\n"
"\n"
"QPushButton#closeWindow:hover{\n"
"	background-color:red;\n"
"}"));
        centralwidget = new QWidget(SUmusic);
        centralwidget->setObjectName("centralwidget");
        Musiclist = new QListView(centralwidget);
        Musiclist->setObjectName("Musiclist");
        Musiclist->setGeometry(QRect(70, 210, 281, 441));
        Musiclist->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(480, 560, 611, 80));
        music_start = new QPushButton(widget);
        music_start->setObjectName("music_start");
        music_start->setGeometry(QRect(260, 20, 91, 51));
        music_start->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/4SUmusic/codicon_debug-start.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon1.addFile(QString::fromUtf8(":/icon/4SUmusic/ic_baseline-pause.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        music_start->setIcon(icon1);
        music_start->setIconSize(QSize(50, 50));
        music_start->setCheckable(true);
        music_start->setAutoDefault(false);
        music_previews = new QPushButton(widget);
        music_previews->setObjectName("music_previews");
        music_previews->setGeometry(QRect(160, 20, 61, 51));
        music_previews->setStyleSheet(QString::fromUtf8("image: url(:/icon/4SUmusic/mi_previous.png);"));
        music_next = new QPushButton(widget);
        music_next->setObjectName("music_next");
        music_next->setGeometry(QRect(390, 20, 61, 51));
        music_next->setStyleSheet(QString::fromUtf8("image: url(:/icon/4SUmusic/mi_next.png);"));
        all_long = new QLabel(centralwidget);
        all_long->setObjectName("all_long");
        all_long->setGeometry(QRect(1120, 470, 91, 16));
        all_long->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        reload = new QPushButton(centralwidget);
        reload->setObjectName("reload");
        reload->setGeometry(QRect(180, 160, 81, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(11);
        reload->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/4SUmusic/material-symbols_refresh-rounded.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        reload->setIcon(icon2);
        now_long = new QLabel(centralwidget);
        now_long->setObjectName("now_long");
        now_long->setGeometry(QRect(420, 470, 76, 12));
        yinliang = new QLabel(centralwidget);
        yinliang->setObjectName("yinliang");
        yinliang->setGeometry(QRect(1140, 620, 81, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        yinliang->setFont(font2);
        yinliang->setAlignment(Qt::AlignmentFlag::AlignCenter);
        musicslider = new QSlider(centralwidget);
        musicslider->setObjectName("musicslider");
        musicslider->setGeometry(QRect(420, 510, 791, 41));
        musicslider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #e9dff0; /* \346\233\264\344\272\256\347\232\204\346\265\205\347\264\253\350\276\271\346\241\206 */\n"
"    background: #f8f6fc; /* \346\233\264\344\272\256\347\232\204\346\265\205\347\201\260\347\264\253\350\211\262\346\247\275\351\201\223 */\n"
"    height: 8px; /* \346\247\275\351\201\223\351\253\230\345\272\246 */\n"
"    border-radius: 4px; /* \345\234\206\350\247\222\346\247\275\351\201\223 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #f0c8dd, /* \346\233\264\344\272\256\347\232\204\346\265\205\347\262\211\347\264\253 */\n"
"        stop:1 #e6b2d1  /* \346\233\264\344\272\256\347\232\204\347\264\253\347\262\211\350\211\262 */\n"
"    ); /* \345\267\262\346\222\255\346\224\276\351\203\250\345\210\206\346\270\220\345\217\230 */\n"
"    border: 1px solid #e6b2d1; /* \350\276\203\344\272\256\347\232\204\346\270\220\345\217\230\350\276\271"
                        "\346\241\206 */\n"
"    height: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #fefcff; /* \346\233\264\344\272\256\347\232\204\346\234\252\346\222\255\346\224\276\351\203\250\345\210\206\346\265\205\347\201\260\347\262\211\350\211\262 */\n"
"    border: 1px solid #e9dff0; /* \346\233\264\344\272\256\347\232\204\346\265\205\347\264\253\350\276\271\346\241\206 */\n"
"    height: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qradialgradient(\n"
"        cx:0.5, cy:0.5, radius:0.5,\n"
"        fx:0.5, fy:0.5,\n"
"        stop:0 #fff, /* \347\231\275\350\211\262\344\270\255\345\277\203 */\n"
"        stop:1 #f6c4d3 /* \346\233\264\344\272\256\347\232\204\346\265\205\347\262\211\345\244\226\345\234\210 */\n"
"    ); /* \346\273\221\345\235\227\346\270\220\345\217\230\351\242\234\350\211\262 */\n"
"    border: 1px solid #f0a3b8; /* \346\233\264\344\272\256\347\232\204\347\262\211\350\211\262\350\276\271\346\241\206"
                        " */\n"
"    width: 14px; /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 14px; /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: -3px 0; /* \350\260\203\346\225\264\345\236\202\347\233\264\344\275\215\347\275\256 */\n"
"    border-radius: 7px; /* \345\234\206\345\275\242\346\273\221\345\235\227 */\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"    background: qradialgradient(\n"
"        cx:0.5, cy:0.5, radius:0.5,\n"
"        fx:0.5, fy:0.5,\n"
"        stop:0 #fff8fa, /* \346\202\254\346\265\256\346\227\266\346\233\264\344\272\256\347\232\204\344\270\255\345\277\203 */\n"
"        stop:1 #f89ab6  /* \346\233\264\344\272\256\347\232\204\345\244\226\345\234\210\344\272\256\347\262\211\350\211\262 */\n"
"    ); /* \351\274\240\346\240\207\346\202\254\346\265\256\346\273\221\345\235\227\346\270\220\345\217\230 */\n"
"    border: 1px solid #f48ca2; /* \350\276\271\346\241\206\346\233\264\344\272\256 */\n"
"}\n"
"\n"
"QSlider::groove:horizontal:hover {\n"
"    bac"
                        "kground: #f9f3f9; /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\346\233\264\344\272\256\347\232\204\346\265\205\347\264\253\350\211\262 */\n"
"}\n"
""));
        musicslider->setMaximum(100);
        musicslider->setOrientation(Qt::Orientation::Horizontal);
        about = new QPushButton(centralwidget);
        about->setObjectName("about");
        about->setGeometry(QRect(40, 40, 61, 31));
        about->setFont(font2);
        MuCover = new QLabel(centralwidget);
        MuCover->setObjectName("MuCover");
        MuCover->setGeometry(QRect(640, 120, 300, 300));
        MuCover->setStyleSheet(QString::fromUtf8(""));
        MuCover->setPixmap(QPixmap(QString::fromUtf8(":/icon/4SUmusic/default_cover.png")));
        MuCover->setScaledContents(true);
        usrInput = new QTextEdit(centralwidget);
        usrInput->setObjectName("usrInput");
        usrInput->setGeometry(QRect(380, 40, 711, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(14);
        font3.setBold(false);
        usrInput->setFont(font3);
        usrInput->setUndoRedoEnabled(true);
        usrInput->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);
        usrInput->setOverwriteMode(false);
        usrInput->setAcceptRichText(true);
        addMusic = new QPushButton(centralwidget);
        addMusic->setObjectName("addMusic");
        addMusic->setGeometry(QRect(1100, 40, 81, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(10);
        addMusic->setFont(font4);
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        addMusic->setIcon(icon3);
        open_file = new QPushButton(centralwidget);
        open_file->setObjectName("open_file");
        open_file->setGeometry(QRect(70, 160, 101, 41));
        open_file->setFont(font1);
        open_file->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/4SUmusic/mdi-light_file.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        open_file->setIcon(icon4);
        del_music = new QPushButton(centralwidget);
        del_music->setObjectName("del_music");
        del_music->setGeometry(QRect(270, 160, 81, 41));
        del_music->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/4SUmusic/material-symbols_delete-outline-rounded.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        del_music->setIcon(icon5);
        volum_slide = new QSlider(centralwidget);
        volum_slide->setObjectName("volum_slide");
        volum_slide->setGeometry(QRect(1170, 550, 20, 71));
        volum_slide->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {\n"
"    border: 1px solid #e9dff0; /* \350\276\271\346\241\206\346\265\205\347\264\253\350\211\262 */\n"
"    background: #f8f6fc; /* \346\265\205\347\201\260\347\264\253\350\211\262\346\247\275\351\201\223 */\n"
"    width: 8px; /* \346\247\275\351\201\223\345\256\275\345\272\246 */\n"
"    border-radius: 4px; /* \345\234\206\350\247\222\346\247\275\351\201\223 */\n"
"}\n"
"\n"
"QSlider::sub-page:vertical {\n"
"    background: #fefcff; /* \345\267\262\350\260\203\346\225\264\351\203\250\345\210\206\346\265\205\347\201\260\347\262\211\350\211\262 */\n"
"    border: 1px solid #e9dff0; /* \350\276\271\346\241\206\346\265\205\347\264\253\350\211\262 */\n"
"    width: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:vertical {\n"
"    background: qlineargradient(\n"
"        spread:pad,\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f0c8dd, /* \346\233\264\344\272\256\347\232\204\346\265\205\347\262\211\347\264\253 */\n"
"        stop:1 #e6b2d1  /* \346\233\264\344"
                        "\272\256\347\232\204\347\264\253\347\262\211\350\211\262 */\n"
"    ); /* \346\234\252\350\260\203\346\225\264\351\203\250\345\210\206\346\270\220\345\217\230 */\n"
"    border: 1px solid #e6b2d1; /* \346\270\220\345\217\230\350\276\271\346\241\206 */\n"
"    width: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: qradialgradient(\n"
"        cx:0.5, cy:0.5, radius:0.5,\n"
"        fx:0.5, fy:0.5,\n"
"        stop:0 #fff, /* \347\231\275\350\211\262\344\270\255\345\277\203 */\n"
"        stop:1 #f6c4d3 /* \346\233\264\344\272\256\347\232\204\346\265\205\347\262\211\345\244\226\345\234\210 */\n"
"    ); /* \346\273\221\345\235\227\346\270\220\345\217\230\351\242\234\350\211\262 */\n"
"    border: 1px solid #f0a3b8; /* \350\276\271\346\241\206\346\265\205\347\262\211\350\211\262 */\n"
"    width: 14px; /* \346\273\221\345\235\227\345\256\275\345\272\246 */\n"
"    height: 14px; /* \346\273\221\345\235\227\351\253\230\345\272\246 */\n"
"    margin: 0 -3px; /* \350\260"
                        "\203\346\225\264\346\260\264\345\271\263\344\275\215\347\275\256 */\n"
"    border-radius: 7px; /* \345\234\206\345\275\242\346\273\221\345\235\227 */\n"
"}\n"
"\n"
"QSlider::handle:vertical:hover {\n"
"    background: qradialgradient(\n"
"        cx:0.5, cy:0.5, radius:0.5,\n"
"        fx:0.5, fy:0.5,\n"
"        stop:0 #fff8fa, /* \346\202\254\346\265\256\346\227\266\346\233\264\344\272\256\347\232\204\344\270\255\345\277\203 */\n"
"        stop:1 #f89ab6  /* \346\233\264\344\272\256\347\232\204\345\244\226\345\234\210\344\272\256\347\262\211\350\211\262 */\n"
"    ); /* \351\274\240\346\240\207\346\202\254\346\265\256\346\273\221\345\235\227\346\270\220\345\217\230 */\n"
"    border: 1px solid #f48ca2; /* \350\276\271\346\241\206\346\233\264\344\272\256 */\n"
"}\n"
"\n"
"QSlider::groove:vertical:hover {\n"
"    background: #f9f3f9; /* \351\274\240\346\240\207\346\202\254\346\265\256\346\227\266\346\233\264\344\272\256\347\232\204\346\265\205\347\264\253\350\211\262 */\n"
"}\n"
""));
        volum_slide->setOrientation(Qt::Orientation::Vertical);
        headBar = new QLabel(centralwidget);
        headBar->setObjectName("headBar");
        headBar->setGeometry(QRect(0, 0, 1281, 31));
        headBar->setStyleSheet(QString::fromUtf8("background-color:rgb(255,204,229);\n"
"border-radius: 10px;             /*\345\233\233\350\247\222\345\234\206\350\247\222\347\232\204\347\233\264\345\276\204*/\n"
"border-width:2px;             /*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"border-color:rgb(213, 213, 213);\n"
"border-style:solid"));
        closeWindow = new QPushButton(centralwidget);
        closeWindow->setObjectName("closeWindow");
        closeWindow->setGeometry(QRect(1240, 0, 31, 31));
        closeWindow->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
""));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        closeWindow->setIcon(icon6);
        minWindow = new QPushButton(centralwidget);
        minWindow->setObjectName("minWindow");
        minWindow->setGeometry(QRect(1200, 0, 31, 31));
        minWindow->setStyleSheet(QString::fromUtf8("border-radius: 15px;"));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove));
        minWindow->setIcon(icon7);
        Introduction = new QLabel(centralwidget);
        Introduction->setObjectName("Introduction");
        Introduction->setGeometry(QRect(10, 0, 91, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setItalic(false);
        Introduction->setFont(font5);
        songMode = new QComboBox(centralwidget);
        songMode->setObjectName("songMode");
        songMode->setGeometry(QRect(1040, 560, 111, 31));
        songMode->setFont(font4);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 130, 101, 31));
        pushButton->setFont(font1);
        SUmusic->setCentralWidget(centralwidget);

        retranslateUi(SUmusic);

        QMetaObject::connectSlotsByName(SUmusic);
    } // setupUi

    void retranslateUi(QMainWindow *SUmusic)
    {
        SUmusic->setWindowTitle(QCoreApplication::translate("SUmusic", "SU\344\272\221\351\237\263\344\271\220", nullptr));
        music_start->setText(QString());
        music_previews->setText(QString());
        music_next->setText(QString());
        all_long->setText(QCoreApplication::translate("SUmusic", "00:00:00", nullptr));
        reload->setText(QCoreApplication::translate("SUmusic", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
        now_long->setText(QCoreApplication::translate("SUmusic", "00:00:00", nullptr));
        yinliang->setText(QCoreApplication::translate("SUmusic", "\351\237\263\351\207\217", nullptr));
        about->setText(QCoreApplication::translate("SUmusic", "About", nullptr));
        MuCover->setText(QString());
        addMusic->setText(QCoreApplication::translate("SUmusic", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
        open_file->setText(QCoreApplication::translate("SUmusic", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        del_music->setText(QCoreApplication::translate("SUmusic", "\345\210\240\351\231\244\351\237\263\344\271\220", nullptr));
        headBar->setText(QString());
        closeWindow->setText(QString());
        minWindow->setText(QString());
        Introduction->setText(QCoreApplication::translate("SUmusic", "SU\344\272\221\351\237\263\344\271\220", nullptr));
        songMode->setCurrentText(QString());
        pushButton->setText(QCoreApplication::translate("SUmusic", "\345\215\240\347\224\250\346\270\205\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SUmusic: public Ui_SUmusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMUSIC_H
