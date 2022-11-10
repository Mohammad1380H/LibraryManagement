#ifndef NEWLABLE_H
#define NEWLABLE_H

#include <QLabel>

class newLable : public QLabel
{
    Q_OBJECT
public:
    explicit newLable(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *e);

signals:
    void selected(int);
public slots:

};

#endif // NEWLABLE_H
