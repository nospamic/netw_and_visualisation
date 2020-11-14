#include "being.h"

Being::Being()
{

}

Being::Being(float x, float y): x{x}, y{y}, angle{0}
{
    seen.resize(50);
    hp = 100;

}

void Being::turnLeft()
{
    angle--;
    if(angle == -1) angle = 359;
}

void Being::turnRight()
{
    angle++;
    if(angle == 361) angle = 1;
}

void Being::moveForward()
{
    x = x + (cos((float(angle) * DEG_TO_RAD)) * 1.0f);
    y = y + (sin((float(angle) * DEG_TO_RAD)) * 1.0f);
}

int Being::getX()
{
    return int(round(x));
}

int Being::getY()
{
    return int(round(y));
}

int Being::getAngle()
{
    return angle;
}

void Being::setSeen()
{
    int seenPos = 0;
    for (int i = 5; i < 15; ++i) {
        for(int j = -40; j <= 40; j+=20){
            QPoint point;
            point.setX(int(round(x + (cos((float(angle + j) * DEG_TO_RAD)) * 2.0f * float(i)))));
            point.setY(int(round(y + (sin((float(angle + j) * DEG_TO_RAD)) * 2.0f * float(i)))));
            seen[seenPos] = point;
            ++seenPos;
        }
    }

}

QVector<QPoint> Being::getSeen()
{
    setSeen();
    return seen;
}

int Being::getHp()
{
    return hp;
}

void Being::takeHp(int take)
{
    hp = hp - take;
    if (hp < 0) hp = 0;
}

void Being::giveHp(int give)
{
    hp = hp + give;
    if (hp > 100) hp = 100;
}

QPoint Being::getSensorPoint()
{
    QPoint point;
    point.setX(int(round(x + (cos((float(angle) * DEG_TO_RAD)) * 6.0f ))));
    point.setY(int(round(y + (sin((float(angle) * DEG_TO_RAD)) * 6.0f ))));
    return point;
}
