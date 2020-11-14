#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QVector>
#include <iostream>
#include <time.h>
#include <QDebug>
#include <iostream>
#include <math.h>


class Neuron
{
public:
    Neuron(QString name, QVector<float>slots_){
        this->name = name;
        this->slots_ = slots_;
        this->signal = 0;
        setMaxSumm();
    }
    Neuron(){}
    QString getName(){return name;}
    float getSignal(){return signal;}
    QVector<float> slots_;

    void activate(QVector<float>signals_){
        if(signals_.size()==slots_.size()){
            this->signal = 0;
            for(int i = 0; i < signals_.size(); ++i){
                this->signal = this->signal + signals_[i] * slots_[i];
            }
            this->signal = 1.0f / (1.0f + exp(-this->signal));
            if(this->signal < 0.3f) this->signal = this->signal * 0.001f;
        }else{
            //throw "Different number of slots and signals";
            std::cout<<this->name.toLocal8Bit().constData()<<": Different number of slots="<< slots_.size()<< "and signals="<<signals_.size();

        }
    }

    void setSlots(QVector<float>slots_){
        this->slots_ = slots_;
        setMaxSumm();
    }
    QVector <float> getSlots(){return slots_;}

private:
    QString name;
    float signal;
    void setMaxSumm(){
        this->maxSumm = 0;
        for(auto weight : slots_) maxSumm+=weight;
    }
    float maxSumm;
};





class Network
{
    class Sample{
    public:
        Sample(QVector<float>input, QVector<float>expected){
            this->input = input;
            this->expected = expected;
        }
        Sample(){}
        QVector<float>input;
        QVector<float>expected;
    };

    enum {RECEIVE, HIDDEN_1, HIDDEN_2, RECOIL};

public:
    Network(int receiveCount, int hiddenCount, int recoilCont);
    void activate(QVector<float>signals_);
    QVector<float> getRecoil();
    void showData();
    static QVector<float> getRandVec(int size, int min, int max);
    int minWeight, maxWeight;
    float getError(QVector<float>expected);
    void setRandomWeights();
    void addSamle(QVector<float>input, QVector<float>expected);
    void bruteTraining(float maxError = 0.01f);
    void smartTraining(float maxError = 0.01f);


private:
    int receiveCount;
    int recoilCount;
    int hiddenCount;
    QVector<Neuron>receive;
    QVector<Neuron>recoil;
    QVector<Neuron>hidden1;
    QVector<Neuron>hidden2;
    QVector<float>inputData;
    QVector<Sample>samples;
    QVector<float> prepearData(QVector<float>input);
    float getAverageError();

    QVector<float> getSignals(QVector<Neuron>neurons);


};

#endif // NETWORK_H
