#include "edit.h"
#include "ui_edit.h"
#include "mainwindow.h"
QString curr;
edit::edit(QWidget *parent,QString cur) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
    ui->label_2->setText("Current : "+cur);
    connect(this,SIGNAL(send_edit(QString,int)),parent,SLOT(rec_edit(QString,int)));
    curr = cur;
}

edit::~edit()
{
    delete ui;
}

void edit::on_pushButton_clicked()
{
    int x=0;
    if(ui->checkBox->isChecked())
    {
        x=1;
    }
    QString s;
    if(ui->lineEdit->text()=="")
    {
        s = curr;
    }
    else
    {
        s = ui->lineEdit->text();
    }
    emit send_edit(s,x);
    close();
}
