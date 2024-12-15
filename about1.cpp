#include "about1.h"
#include "ui_about1.h"

About1::About1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::About1)
{
    ui->setupUi(this);
}

About1::~About1()
{
    delete ui;
}
