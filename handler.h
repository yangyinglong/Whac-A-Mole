#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>

class Handler : public QObject
{
    Q_OBJECT

public:
    static Handler * getInstance();

    void addScore();

private:
    explicit Handler(QObject *parent = nullptr);

signals:
    void beatMole();

public slots:

private:
    static Handler * hand;
};

#endif // HANDLER_H
