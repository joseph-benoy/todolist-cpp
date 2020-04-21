#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "edit.h"
#include<QMessageBox>
#include<QFile>
#include<QDataStream>
#include<QList>
#include<string>
#include<fstream>
#include<QTextStream>
#include "item.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*reading data*/
    task item;



   /*--------------------*/
}

MainWindow::~MainWindow()
{
   /*Saving the end data*/
   QString name;
   QString flag;
   int count = ui->listWidget->count();
   task item;
    for(int i=0;i<count;i++)
    {
        name = ui->listWidget->item(i)->text();
        if(ui->listWidget->item(i)->background()==Qt::red)
        {
            flag="red";
        }
        else
        {
            flag="green";
        }
        item = task(name.toStdString(),flag.toStdString());
     }



    /*-------------------*/
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int count = ui->listWidget->count();
    count++;
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->setText("");
    ui->listWidget->item(count-1)->setBackground(Qt::red);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->listWidget->selectedItems().size()==0)
    {
        QMessageBox::warning(this,"Selection failed","Select a task!");
    }
    else
    {
        ui->listWidget->currentItem()->setBackground(Qt::green);

    }
}
void MainWindow::on_pushButton_3_clicked()
{
    if(ui->listWidget->selectedItems().size()==0)
    {
        QMessageBox::warning(this,"Selection failed","Select a task!");
    }
    else
    {
        edit edit_win(this,ui->listWidget->currentItem()->text());
        edit_win.setModal(true);
        edit_win.exec();
    }
}
void MainWindow::rec_edit(QString str,int flag)
{
    QString new_task;
    if(str==ui->listWidget->currentItem()->text())
    {
        new_task = ui->listWidget->currentItem()->text();
    }
    else
    {
        new_task = str;
    }
    ui->listWidget->currentItem()->setText(new_task);
    if(flag==1)
    {
        ui->listWidget->currentItem()->setBackground(Qt::green);
    }
    else
    {
        ui->listWidget->currentItem()->setBackground(Qt::red);

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->listWidget->selectedItems().size()==0)
    {
        QMessageBox::warning(this,"Selection failed","Select a task!");
    }
    else
    {
        delete ui->listWidget->currentItem();
    }
}
