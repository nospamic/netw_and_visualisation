#include "engine.h"

Engine::Engine()
{
    being = new Being(200, 200);
    network = new Network(50, 20, 3);
    map.load("D:\\code\\map.png");
    moveBlock = false;
}

void Engine::processing()
{
    moveControl();
    hpControl();



}

void Engine::moveControl()
{
    fillToReceive();
    network->activate(toReceive);
    QVector<float>recoil = network->getRecoil();
    if(recoil[0]>0.6f) being->turnLeft();
    if(recoil[1]>0.6f && moveBlock == false) being->moveForward();
    if(recoil[2]>0.6f) being->turnRight();

    QPoint sensor = being->getSensorPoint();
    if(map.pixelIndex(sensor) == 0){
        moveBlock = true;
    }else{
        moveBlock = false;
    }
}

void Engine::hpControl()
{
    QPoint sensor = being->getSensorPoint();
    if(map.pixelIndex(sensor) == 2){
        being->giveHp(20);
        removeFood(sensor);
        qDebug()<<"HP: "<<being->getHp();
    }else{
        being->takeHp(1);
    }
}

void Engine::fillToReceive()
{
    toReceive.clear();
    for(auto point : being->getSeen()){
        int maxPixelIndex = 2;
        toReceive.push_back(map.pixelIndex(point)/float(maxPixelIndex));

        //qDebug()<<map.pixelIndex(point);
    }
}

void Engine::removeFood(QPoint point)
{
    for(int x = - 10; x < 10; ++x){
        for(int y = - 10; y < 10; ++y){
            map.setPixel(point.x() + x, point.y() + y, 1);
        }
    }
}
