#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QApplication"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "qtimer.h"
#include "QTime"
#include "QDate"
#include <QDateTime>
#include "addnew.h"
#include "QtDebug"
#include <QMainWindow>
#include <QTextEdit>
#include "addbook.h"
#include "addnew.h"
#include "get_giveback.h"
#include "queries.h"
#include "wtp.hpp"
#include "pubwrttrs.h"
#include "help.h"
#include "about.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private slots:
    void upclok();




    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_action_7_triggered();

    void on_action_8_triggered();



    void on_action_2_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
