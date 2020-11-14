#ifndef BEING_H
#define BEING_H

#define DEG_TO_RAD 0.01745f

#include <math.h>
#include <QDebug>
#include <QVector>
#include <QPoint>

class Being
{
public:
    Being();
    Being(float x, float y);
    void turnLeft();
    void turnRight();
    void moveForward();
    int getX();
    int getY();
    int getAngle();
    void setSeen();
    QVector<QPoint> getSeen();
    int getHp();
    void takeHp(int take);
    void giveHp(int give);
    QPoint getSensorPoint();


private:
    float x;
    float y;
    int angle;
    int hp;
    QVector<QPoint> seen;

};

#endif // BEING_H
