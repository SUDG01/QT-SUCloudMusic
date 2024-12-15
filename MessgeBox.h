#ifndef MESSGEBOX_H
#define MESSGEBOX_H

#include <QWidget>

namespace Ui {
class MessgeBox;
}

class MessgeBox : public QWidget
{
    Q_OBJECT

public:
    explicit MessgeBox(QWidget *parent = nullptr);
    ~MessgeBox();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MessgeBox *ui;
};

#endif // MESSGEBOX_H
