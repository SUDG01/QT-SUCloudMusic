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
    QSlider *volum_slide;
    QLabel *yinliang;
    QSlider *musicslider;
    QPushButton *about;
    QLabel *MuCover;
    QTextEdit *usrInput;
    QPushButton *addMusic;
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
        font.setBold(false);
        font.setKerning(true);
        SUmusic->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/4SUmusic/arcticons_wynk-music.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        SUmusic->setWindowIcon(icon);
        SUmusic->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(212,212,212);\n"
"}"));
        centralwidget = new QWidget(SUmusic);
        centralwidget->setObjectName("centralwidget");
        Musiclist = new QListView(centralwidget);
        Musiclist->setObjectName("Musiclist");
        Musiclist->setGeometry(QRect(60, 210, 281, 441));
        Musiclist->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(370, 540, 611, 80));
        music_start = new QPushButton(widget);
        music_start->setObjectName("music_start");
        music_start->setGeometry(QRect(230, 20, 91, 51));
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
        music_previews->setGeometry(QRect(140, 20, 61, 51));
        music_previews->setStyleSheet(QString::fromUtf8("image: url(:/icon/4SUmusic/mi_previous.png);"));
        music_next = new QPushButton(widget);
        music_next->setObjectName("music_next");
        music_next->setGeometry(QRect(360, 20, 61, 51));
        music_next->setStyleSheet(QString::fromUtf8("image: url(:/icon/4SUmusic/mi_next.png);"));
        all_long = new QLabel(centralwidget);
        all_long->setObjectName("all_long");
        all_long->setGeometry(QRect(1120, 470, 91, 16));
        all_long->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        reload = new QPushButton(centralwidget);
        reload->setObjectName("reload");
        reload->setGeometry(QRect(1220, 650, 56, 20));
        now_long = new QLabel(centralwidget);
        now_long->setObjectName("now_long");
        now_long->setGeometry(QRect(420, 470, 76, 12));
        volum_slide = new QSlider(centralwidget);
        volum_slide->setObjectName("volum_slide");
        volum_slide->setGeometry(QRect(1000, 570, 221, 21));
        QFont font1;
        font1.setStyleStrategy(QFont::PreferAntialias);
        volum_slide->setFont(font1);
        volum_slide->setMaximum(100);
        volum_slide->setValue(50);
        volum_slide->setSliderPosition(50);
        volum_slide->setTracking(true);
        volum_slide->setOrientation(Qt::Orientation::Horizontal);
        yinliang = new QLabel(centralwidget);
        yinliang->setObjectName("yinliang");
        yinliang->setGeometry(QRect(1080, 610, 71, 21));
        yinliang->setAlignment(Qt::AlignmentFlag::AlignCenter);
        musicslider = new QSlider(centralwidget);
        musicslider->setObjectName("musicslider");
        musicslider->setGeometry(QRect(420, 510, 791, 41));
        musicslider->setMaximum(100);
        musicslider->setOrientation(Qt::Orientation::Horizontal);
        about = new QPushButton(centralwidget);
        about->setObjectName("about");
        about->setGeometry(QRect(0, 0, 61, 21));
        MuCover = new QLabel(centralwidget);
        MuCover->setObjectName("MuCover");
        MuCover->setGeometry(QRect(620, 120, 300, 300));
        MuCover->setStyleSheet(QString::fromUtf8(""));
        MuCover->setPixmap(QPixmap(QString::fromUtf8(":/icon/4SUmusic/default_cover.png")));
        MuCover->setScaledContents(true);
        usrInput = new QTextEdit(centralwidget);
        usrInput->setObjectName("usrInput");
        usrInput->setGeometry(QRect(380, 10, 681, 41));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        usrInput->setFont(font2);
        usrInput->setUndoRedoEnabled(true);
        usrInput->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);
        usrInput->setOverwriteMode(false);
        usrInput->setAcceptRichText(true);
        addMusic = new QPushButton(centralwidget);
        addMusic->setObjectName("addMusic");
        addMusic->setGeometry(QRect(1070, 10, 81, 41));
        QFont font3;
        font3.setPointSize(10);
        addMusic->setFont(font3);
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        addMusic->setIcon(icon2);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 160, 91, 41));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        pushButton->setIcon(icon3);
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
        reload->setText(QCoreApplication::translate("SUmusic", "Reload", nullptr));
        now_long->setText(QCoreApplication::translate("SUmusic", "00:00:00", nullptr));
        yinliang->setText(QCoreApplication::translate("SUmusic", "\351\237\263\351\207\217", nullptr));
        about->setText(QCoreApplication::translate("SUmusic", "About", nullptr));
        MuCover->setText(QString());
        addMusic->setText(QCoreApplication::translate("SUmusic", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
        pushButton->setText(QCoreApplication::translate("SUmusic", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SUmusic: public Ui_SUmusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMUSIC_H
