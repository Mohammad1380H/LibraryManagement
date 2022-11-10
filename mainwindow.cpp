#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "open_database.hpp"
#include "qdateconvertor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer* timer= new QTimer();//time of system
    timer->setInterval(1000);//1 s
    timer->start();
    connect(timer,SIGNAL(timeout()), SLOT(upclok()));//connect ot system

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::upclok()
{

   QString time= QTime::currentTime().toString("hh:mm:ss");
   ui->label_4->setText(time);


}

void MainWindow::on_pushButton_2_clicked()
{
    addnew * form2= new addnew();
    form2->show();





}


void MainWindow::on_pushButton_clicked()
{
    addbook * form= new addbook();
    form->show();
}


void MainWindow::on_pushButton_3_clicked()
{

    get_giveback * obj = new get_giveback();

    obj->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    queries * form= new queries("");
    form->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    pubwrttrs * form= new pubwrttrs();
    form->show();
}


void MainWindow::on_pushButton_5_clicked()
{
   this->close();
}


void MainWindow::on_action_7_triggered()
{
    Help * form= new Help();
    form->show();
}


void MainWindow::on_action_8_triggered()
{
    about * form = new about();
    form->show();
}





void MainWindow::on_action_2_triggered()
{
    about * form = new about();
    form->show();
}

