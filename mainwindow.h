#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QDebug>
#include <engine.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QVector <QPoint> points;
    QPixmap *pic;
    Engine *engine;
    QTimer *timer;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *ev);
    void keyPressEvent(QKeyEvent *ev);



private slots:
    void onMouseClick();
    void onTimeOut();
};

#endif // MAINWINDOW_H
