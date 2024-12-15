#include "MessgeBox.h"
#include "ui_MessgeBox.h"


MessgeBox::MessgeBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MessgeBox)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
}

MessgeBox::~MessgeBox()
{
    delete ui;
}

void MessgeBox::on_pushButton_clicked()
{
    this->close();
}


void MessgeBox::on_pushButton_2_clicked()
{
    this->close();
}

