#ifndef ABOUT1_H
#define ABOUT1_H

#include <QWidget>

namespace Ui {
class About1;
}

class About1 : public QWidget
{
    Q_OBJECT

public:
    explicit About1(QWidget *parent = nullptr);
    ~About1();

private:
    Ui::About1 *ui;
};

#endif // ABOUT1_H
