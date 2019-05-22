#include "myitem.h"
#include <QDebug>

MyItem::MyItem()
{
    this->setPixmap(QPixmap(":/bg/img/bg1.png"));
    this->mole = false;
    this->start = false;
    this->setCursor(QCursor(QPixmap(":/bg/img/pictureUp.png")));
}

void MyItem::setPig(QString path)
{
    this->setPixmap(QPixmap(path));
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/bg/img/picturedown.png")));
    if (this->isStart())
    {
        Handler * handler = Handler::getInstance();
        if (this->isMole())
        {
            handler->addScore();
            this->setPig(":/bg/img/bg1.png");
            this->setMole(false);
        }
        else
        {
            qDebug() << "not a mole";
        }
    }

}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/bg/img/pictureUp.png")));
}

void MyItem::setMole(bool mole)
{
    this->mole = mole;
}

bool MyItem::isMole()
{
    return this->mole;
}

void MyItem::setStart(bool start)
{
    this->start = start;
}

bool MyItem::isStart()
{
    return this->start;
}
