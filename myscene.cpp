#include "myscene.h"
#include <stdlib.h>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    for (int i = 0; i < 16; i++)
    {
        this->item[i] = new MyItem;
        this->item[i]->setPos(i/4 * this->item[i]->boundingRect().width(),
                              i%4 * this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }
    this->pTimer = new QTimer;
    connect(this->pTimer, SIGNAL(timeout()), this, SLOT(showMole()));
}

void MyScene::showMole()
{
    for (int i = 0; i < 16; i++)
    {
        this->item[i]->setPig(":/bg/img/bg1.png");
        this->item[i]->setMole(false);
//        this->item[i]->setStart(false);
    }
//     a number between 0 to 15;
    int count =  rand()%3 + 1;
    for (int i = 0; i < count; i++)
    {
        int index = rand()%16;
        this->item[index]->setPig(":/bg/img/mouse.png");
        this->item[index]->setMole(true);
//        this->item[index]->setStart(true);
    }
}

void MyScene::startGame()
{
    this->pTimer->start(1000);
    for (int i = 0; i < 16; i++)
    {
        this->item[i]->setStart(true);
    }
}

void MyScene::pauseGame(bool start)
{
    if (start)
    {
        this->pTimer->stop();
        for (int i = 0; i < 16; i++)
        {
            this->item[i]->setStart(false);
        }
    }
    else
    {
        this->startGame();
    }
}

void MyScene::stopGame()
{
    this->pTimer->stop();
    for (int i = 0; i < 16; i++)
    {
        this->item[i]->setPig(":/bg/img/bg1.png");
        this->item[i]->setMole(false);
        this->item[i]->setStart(false);
    }
}
