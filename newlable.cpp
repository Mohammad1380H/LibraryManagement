#include "newlable.h"
#include <QDebug>
newLable::newLable(QWidget *parent) :
    QLabel(parent)
{
}

void newLable::mousePressEvent(QMouseEvent *e)
{
    bool ok;
    int t = text().toInt(&ok);
    if (ok)
    {
        emit selected(t);
    }

}
