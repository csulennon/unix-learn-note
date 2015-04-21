#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QPushButton* pushbtn;
    QLabel* label;
    QLineEdit* edit1;
    QLineEdit* edit2;
private slots:
    void add();
};

#endif // DIALOG_H
