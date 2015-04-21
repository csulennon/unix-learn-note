#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int a = ui->lineEdit->text().toInt();
    int b = ui->lineEdit_2->text().toInt();
    ui->label->setText(QString::number(a+b));
}
