#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include "handler.h"

class MyItem : public QGraphicsPixmapItem
{
public:
    MyItem();

    void setPig(QString path);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void setMole(bool mole);

    bool isMole();

    void setStart(bool start);

    bool isStart();

private:
    bool mole;
    bool start;

};

#endif // MYITEM_H
