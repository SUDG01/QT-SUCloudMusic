/********************************************************************************
** Form generated from reading UI file 'about1.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT1_H
#define UI_ABOUT1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About1
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *About1)
    {
        if (About1->objectName().isEmpty())
            About1->setObjectName("About1");
        About1->resize(339, 163);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/4SUmusic/mdi_about.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        About1->setWindowIcon(icon);
        label = new QLabel(About1);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 121, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(About1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 331, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(About1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 101, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(10);
        label_3->setFont(font2);
        label_4 = new QLabel(About1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 100, 211, 21));
        label_4->setFont(font2);

        retranslateUi(About1);

        QMetaObject::connectSlotsByName(About1);
    } // setupUi

    void retranslateUi(QWidget *About1)
    {
        About1->setWindowTitle(QCoreApplication::translate("About1", "\345\205\263\344\272\216", nullptr));
        label->setText(QCoreApplication::translate("About1", "\345\205\263\344\272\216\346\210\221\344\273\254", nullptr));
        label_2->setText(QCoreApplication::translate("About1", "Version: SUCloudMusic Beta 0.2.1", nullptr));
        label_3->setText(QCoreApplication::translate("About1", "Dev: SUX1NG", nullptr));
        label_4->setText(QCoreApplication::translate("About1", "Supporter: DNF1sreal,Chatgpt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About1: public Ui_About1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT1_H
