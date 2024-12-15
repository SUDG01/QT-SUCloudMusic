/********************************************************************************
** Form generated from reading UI file 'MessgeBox.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSGEBOX_H
#define UI_MESSGEBOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessgeBox
{
public:
    QWidget *widget;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *widget_2;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MessgeBox)
    {
        if (MessgeBox->objectName().isEmpty())
            MessgeBox->setObjectName("MessgeBox");
        MessgeBox->setEnabled(true);
        MessgeBox->resize(292, 163);
        QFont font;
        font.setBold(false);
        MessgeBox->setFont(font);
        MessgeBox->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border:none\357\274\233\n"
"}\n"
""));
        widget = new QWidget(MessgeBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 30, 301, 141));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 10, 301, 101));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 90, 51, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(212,212,212);\n"
""));
        widget_2 = new QWidget(MessgeBox);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 301, 31));
        widget_2->setStyleSheet(QString::fromUtf8("background:rgb(51,153,255);"));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 41, 31));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(260, 0, 31, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color:red;"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        pushButton_2->setIcon(icon);

        retranslateUi(MessgeBox);

        QMetaObject::connectSlotsByName(MessgeBox);
    } // setupUi

    void retranslateUi(QWidget *MessgeBox)
    {
        MessgeBox->setWindowTitle(QCoreApplication::translate("MessgeBox", "\346\217\220\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("MessgeBox", "\346\226\207\344\273\266\345\244\271\345\210\233\345\273\272\345\244\261\350\264\245\357\274\201\350\257\267\346\243\200\346\237\245\346\235\203\351\231\220\357\274\201\357\274\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MessgeBox", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("MessgeBox", "\346\217\220\347\244\272", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MessgeBox: public Ui_MessgeBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSGEBOX_H
