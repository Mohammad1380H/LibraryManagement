#include "jalalidatepicker.h"
#include "utility.h"
#include <ctime>
#include "newlable.h"

JalaliDatepicker::JalaliDatepicker(QWidget *parent) :
    QWidget(parent)
{
    resize(250,250);
     //qDebug()<<miladi_to_jalali(2012,1,1).y;
    _initialize();
    vlay    = new QVBoxLayout(this);
    hlay = new QHBoxLayout();
    gridLayout = new QGridLayout();
    titel   = new QLabel("",this);
    titel->setLayoutDirection(Qt::RightToLeft);
    titel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    previousbtn = new QPushButton("<",this);
    nextbtn     = new QPushButton(">",this);
    connect(previousbtn,SIGNAL(clicked()),this,SLOT(on_previousbtn_clicked()));
    connect(nextbtn,SIGNAL(clicked()),this,SLOT(on_nextbtn_clicked()));
    previousbtn->setMaximumSize(20,20);
    nextbtn->setMaximumSize(20,20);
    vlay->setSpacing(2);
    hlay->setSpacing(0);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0,0,0,0);
    hlay->addWidget(previousbtn);
    hlay->addWidget(titel);
    hlay->addWidget(nextbtn);
    vlay->addLayout(hlay);
    QLabel* label;
    int x(0),y(0);
    for (int i = 0 ;i <49 ;i++,x++)
    {
        label = new newLable();
        connect(label,SIGNAL(selected(int)),this,SLOT(setSelected(int)));
        label->setStyleSheet(cellStyleSheet);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignCenter);

        gridLayout->addWidget(label,y,x);
        if (x==6)
        {
            x=-1;
            y++;
        }
    }
    for (int i = 0 ;i< 7 ;i++)
    {
        switch (i)
        {
        case 0:
            label = (newLable*)gridLayout->itemAt(0)->widget();
            label->setText(QString::fromUtf8("آدینه"));
            label->setStyleSheet(titelStyleSheet);
        case 1:
            label = (newLable*)gridLayout->itemAt(1)->widget();
            label->setText(QString::fromUtf8("پنج.."));
            label->setStyleSheet(titelStyleSheet);
        case 2:
            label = (newLable*)gridLayout->itemAt(2)->widget();
            label->setText(QString::fromUtf8("چهار.."));
            label->setStyleSheet(titelStyleSheet);
        case 3:
            label = (newLable*)gridLayout->itemAt(3)->widget();
            label->setText(QString::fromUtf8("سه.."));
            label->setStyleSheet(titelStyleSheet);
        case 4:
            label = (newLable*)gridLayout->itemAt(4)->widget();
            label->setText(QString::fromUtf8("دو.."));
            label->setStyleSheet(titelStyleSheet);
        case 5:
            label = (newLable*)gridLayout->itemAt(5)->widget();
            label->setText(QString::fromUtf8("یک.."));
            label->setStyleSheet(titelStyleSheet);
        case 6:
            label = (newLable*)gridLayout->itemAt(6)->widget();
            label->setText(QString::fromUtf8("شنبه"));
            label->setStyleSheet(titelStyleSheet);

        }
    }
    vlay->addLayout(gridLayout);
    setLayout(vlay);
    time_t rawtime;
    time ( &rawtime );
    year = convert_to_jalali(rawtime).y;
    month = convert_to_jalali(rawtime).m;
    day     =   convert_to_jalali(rawtime).d;

    updateCal();
    updateTitle();
}

void JalaliDatepicker::updateCal()
{
    _clearLabel();
    int i(0),y(1),counter(0);
    int dayinmonth;
    if (month<=6)
    {
        dayinmonth = 31;
    }else if(month>6 & month <12)
    {
        dayinmonth = 30;
    }
    else if (month ==12)
    {

        if (year % 33== 1|year % 33== 5|year % 33== 9|year % 33== 13|year % 33== 17|year % 33== 22|year % 33== 26|year % 33== 30)
        {
            dayinmonth = 30;
        }
        else
        {
             dayinmonth = 29;
        }
    }
    newLable* child;
    switch (DayInWeek(year,month,1))
    {
    case 0:
        i=6;
        break;
    case 1:
        i=5;
        break;
    case 2:
        i=4;
        break;
    case 3:
        i=3;
        break;
    case 4:
        i=2;
        break;
    case 5:
        i=1;
        break;
    case 6:
        i=0;
        break;
    }
    for(int ii = 0 ; ii< i ;ii++)
    {

    }
    for (counter=0;counter<dayinmonth;counter++ ,i--)
    {

        child = (newLable*)gridLayout->itemAtPosition(y,i)->widget();
        child->setText(QString::number(counter+1));
        if ((counter+1) == day)
        {
            child->setStyleSheet(selectedCellStyleSeet);
        }

        if (i==0 )
        {
            y++;
            i=7;
        }
    }
}

void JalaliDatepicker::updateTitle()
{
    titel->setText(monthNames[month]+"     "+QString::number(month)+" / "+QString::number(year));
}

void JalaliDatepicker::on_nextbtn_clicked()
{
    if (month ==12)
    {
        month =1;
        year++;
    }else
    {
        month++;
    }
    updateTitle();
    updateCal();
}

void JalaliDatepicker::on_previousbtn_clicked()
{
    if(month ==1)
    {
        month =12;
        year--;
    }
    else
    {
        month--;
    }
    updateTitle();
    updateCal();
}

void JalaliDatepicker::_clearLabel()
{
    newLable* label=0x0;
    for (int i=8 ;i < 49 ;i++)
    {
        label = (newLable*)gridLayout->itemAt(i)->widget();
        label->setText("");
        label->setStyleSheet(cellStyleSheet);

    }
}

void JalaliDatepicker::_initialize()
{
    titelStyleSheet= "background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(205, 165, 2, 255), stop:1 rgba(255, 231, 37, 255));color: rgb(109, 51, 4)";
    cellStyleSheet  = "background-color:rgb(255, 254, 230)";
    selectedCellStyleSeet   = cellStyleSheet+";border-width: 1px;border-style: solid;border-color: rgb(99, 175, 255);";
    monthNames.append(QString::fromUtf8(""));
    monthNames.append(QString::fromUtf8("فروردین"));
    monthNames.append(QString::fromUtf8("اردیبهشت"));
    monthNames.append(QString::fromUtf8("خرداد"));
    monthNames.append(QString::fromUtf8("تیر"));
    monthNames.append(QString::fromUtf8("مرداد"));
    monthNames.append(QString::fromUtf8("شهریور"));
    monthNames.append(QString::fromUtf8("مهر"));
    monthNames.append(QString::fromUtf8("آبان"));
    monthNames.append(QString::fromUtf8("آذر"));
    monthNames.append(QString::fromUtf8("دی"));
    monthNames.append(QString::fromUtf8("بهمن"));
    monthNames.append(QString::fromUtf8("اسفند"));
}

void JalaliDatepicker::setSelected(int i)
{

    day = i;
    updateCal();
}

Date JalaliDatepicker::selectedDate(ToDate t)
{
    Date d;
    if (t == Jalali)
    {
        d.day=day;
        d.year=year;
        d.month=month;
    }
    else if(t == Miladi)
    {
        D d2;
        d2  =   jalali_to_milady(year,month,day);
        d.year  =   d2.y;
        d.month =   d2.m;
        d.day   =   d2.d;

    }

    return d;
}

void JalaliDatepicker::selectDate(int _year, int _month, int _day, JalaliDatepicker::ToDate t)
{
    if(t == Jalali)
    {
        year = _year;
        month = _month;
        day =  _day;
    }
    else if( t == Miladi)
    {
       D d = miladi_to_jalali(_year,_month,_day);
       year = d.y;
       month = d.m;
       day = d.d;



    }

    updateTitle();
    updateCal();
}
