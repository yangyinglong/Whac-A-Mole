#include "handler.h"

Handler *Handler::getInstance()
{
    return hand;
}

void Handler::addScore()
{
    emit beatMole();
}

Handler::Handler(QObject *parent) : QObject(parent)
{

}

Handler *Handler::hand = new Handler;


