#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr,QString cur="Current");
    ~edit();

private slots:
    void on_pushButton_clicked();

signals:
    void send_edit(QString str,int flag);
private:
    Ui::edit *ui;
};

#endif // EDIT_H
