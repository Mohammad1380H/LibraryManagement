#ifndef JALALICAL_H
#define JALALICAL_H

#include <QWidget>
#include <QtGui>
struct Date{
    int year;
    int month;
    int day;
};

class JalaliDatepicker : public QWidget
{
    Q_OBJECT
public:
    enum ToDate{
        Jalali = 1,
        Miladi = 2
    };
    explicit JalaliDatepicker(QWidget *parent = 0);
    void setTitelStyleSheet(QString s){titelStyleSheet =s ;}
    void setCellStyleSheet(QString s){cellStyleSheet =s ;}
    void setSelectedCellStyleSeet(QString s){selectedCellStyleSeet =s;}
    Date selectedDate(ToDate);
    void selectDate(int year ,int month , int day,ToDate t);

signals:

public slots:
    void updateCal();
    void updateTitle();
    void on_nextbtn_clicked();
    void on_previousbtn_clicked();
    void _clearLabel();
    void _initialize();
    void setSelected(int);

private:
    QGridLayout *gridLayout;
    QHBoxLayout*    hlay;
    QVBoxLayout* vlay;
    int year;
    int month;
    int day;
    QPushButton *nextbtn;
    QPushButton *previousbtn;
    QLabel *titel;
    QStringList monthNames;
    QString titelStyleSheet;
    QString cellStyleSheet;
    QString selectedCellStyleSeet;

};

#endif // JALALICAL_H
