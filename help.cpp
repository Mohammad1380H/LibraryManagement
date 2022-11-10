#include "help.h"
#include "ui_help.h"
#include "QFile"
Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);


}

Help::~Help()
{
    delete ui;
}
