#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>

#include "myitem.h"

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject *parent = nullptr);

signals:

public slots:
    void showMole();

    void startGame();

    void pauseGame(bool start);

    void stopGame();

private:
    MyItem * item[16];
    QTimer * pTimer;
};

#endif // MYSCENE_H
