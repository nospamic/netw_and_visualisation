#ifndef ENGINE_H
#define ENGINE_H

#include <QImage>
#include <QVector>
#include <being.h>
#include <QDebug>
#include <network.h>

class Engine
{
public:
    Engine();
    Being * being;
    Network * network;
    QImage map;
    QVector<float>toReceive;
    void processing();

private:
    bool moveBlock;
    void moveControl();
    void hpControl();
    void fillToReceive();
    void removeFood(QPoint point);




};

#endif // ENGINE_H
