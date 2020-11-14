#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pic = new QPixmap("D:\\liteShop\\next.bmp");
    engine = new Engine();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
    timer->start(100);

    //ui->
    //QPainter * painter = new QPainter;
    //scene->render(painter);

//    QPixmap pic("D:\\liteShop\\next.bmp");

//    scene->setSceneRect(0,0,100,100);
//    scene->addLine(0,0,50,50);
//    QFont font("Arial",20);
//    scene->addText("Hello",font);
//    scene->addPixmap(pic);


//    QPen pen;
//    QPainter painter(ui->graphicsView);
//    painter.save();
//    painter.translate(50, 50);
//    painter.setPen(palette().dark().color());
//    QRect rect(10, 20, 80, 60);
//    painter.drawEllipse(rect);
//    painter.drawEllipse(rect);
//    painter.restore();
//    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete engine;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

        QPainter painter(this);
        QPen pen;
        pen.setWidth(3);
        pen.setStyle(Qt::PenStyle::SolidLine);
        pen.setColor(Qt::blue);
        painter.setPen(pen);
        painter.drawImage(0, 0, engine->map);




        for(auto point : engine->being->getSeen())
            painter.drawPoint(point);

        pen.setColor(Qt::gray);
        painter.setPen(pen);
        painter.drawPoint(engine->being->getSensorPoint());
        pen.setColor(Qt::green);
        painter.setPen(pen);



        QPoint point(engine->being->getX(), engine->being->getY());
        painter.translate(point);
        painter.rotate(engine->being->getAngle());
        QRect rect(-5, -5, 10, 10);
        painter.drawRect(rect);
        pen.setColor(Qt::red);
        painter.setPen(pen);
        //painter.translate(point);
        painter.drawPoint(0,0);
//        QBrush brush;
//        brush.setStyle(Qt::BrushStyle::HorPattern);
//        brush.setColor(Qt::red);
//        painter.setBrush(brush);


//        //painter.save();
//        //painter.translate(50, 50);
//        //painter.setPen(palette().dark().color());
//        QRect rect(10, 20, 80, 60);
//        painter.drawEllipse(rect);
//        painter.translate(0, 0);
//        painter.drawEllipse(rect);
//        painter.drawRect(rect);

//        //painter.drawLines(points);
//        for(int i = 1; i < points.size(); ++i){
//            painter.drawLine(points[i-1], points[i]);
//        }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    QPoint point(ev->x(), ev->y());

    qDebug()<<ev->x()<<"  "<<ev->y();
    points.push_back(point);
    this->repaint();

}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Right) {
        engine->being->turnRight();
        repaint();
    }
    if(ev->key() == Qt::Key_Left) {
        engine->being->turnLeft();
        repaint();
    }
    if(ev->key() == Qt::Key_Up) {
        engine->being->moveForward();
        //engine->processing();
        repaint();
    }
}



void MainWindow::onMouseClick()
{

}

void MainWindow::onTimeOut()
{
    engine->processing();
    repaint();
    timer->start(20);
}
