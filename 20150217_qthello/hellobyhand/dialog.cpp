#include "dialog.h"
#include <QGridLayout>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    pushbtn = new QPushButton(this);
    label = new QLabel(this);
    edit1 = new QLineEdit(this);
    edit2 = new QLineEdit(this);

    pushbtn->setText(tr("求和"));
    label->setText("0");

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(edit1, 0, 0);
    layout->addWidget(edit2, 0, 1);
    layout->addWidget(pushbtn, 1, 0);
    layout->addWidget(label, 1, 1);

    connect(pushbtn, SIGNAL(clicked()), this, SLOT(add()));
}

Dialog::~Dialog()
{

}

void Dialog::add()
{
    bool conv = false;
    QString astr = edit1->text();

    int a = astr.toInt(&conv, 16);

    if(conv == false)
    {
        label->setText(tr("输入有误"));
        return ;
    }

    int b = edit2->text().toInt(&conv, 16);
    if(conv == false)
    {
        label->setText(tr("输入有误"));
        return ;
    }

    label->setText(QString::number(a+b, 16));

}
