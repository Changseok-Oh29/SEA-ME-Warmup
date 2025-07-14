#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QHBoxLayout>
#include <QApplication>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this)), raceTrack(new RaceTrack(800, 780)) {

    ui->setupUi(this);

    ui->view->setScene(scene);

    QPixmap bg("/home/chang/Pictures/track.png");
    scene->setSceneRect(0, 0, bg.width(), bg.height());
    auto backgroundItem = scene->addPixmap(bg);
    backgroundItem->setZValue(-1);

    QStringList carImgs = {"/home/chang/Pictures/blue_car.png", "/home/chang/Pictures/red_car.png"};
    QVector<QPointF> startPositions = { {0, 30}, {0, 120} };
    for (int i=0;i<carImgs.size();i++) {
        Car *car = new Car(this);
        int spd = 4 + i;
        car->setSpeed(spd);
        originalSpeeds.append(spd);
        car->setDirection(1);
        carList.append(car);

        QPixmap orig(carImgs[i]);
        QPixmap scaled = orig.scaledToHeight(50, Qt::SmoothTransformation);

        auto item = scene->addPixmap(scaled);
        item->setPos(startPositions[i]);
        carItems.append(item);

        connect(car, &Car::positionChanged, this, [item](int pos){ item->setX(pos); });
    }

    connect(ui->btnStart, &QPushButton::clicked, this, &MainWindow::startRace);
    connect(ui->btnPause, &QPushButton::clicked, this, &MainWindow::pauseRace);
    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::exitGame);

    ui->btnPause->setEnabled(false);
}

MainWindow::~MainWindow() {
    qDeleteAll(threadList);
    qDeleteAll(carList);
    delete ui;
}

void MainWindow::startRace() {
    ui->btnStart->setEnabled(false);
    ui->btnPause->setEnabled(true);

    for (int i=0;i<carList.size();i++) {
        CarThread *t = new CarThread(carList[i], raceTrack);
        threadList.append(t);
        connect(t, &QThread::finished, t, &QObject::deleteLater);
        t->start();
    }
}

void MainWindow::pauseRace() {
    isPaused = !isPaused;
    ui->btnPause->setText(isPaused ? "Resume" : "Pause");
    for (int i=0;i<carList.size();i++) {
        carList[i]->setSpeed(isPaused ? 0 : originalSpeeds[i]);
    }
}

void MainWindow::exitGame() {
    QApplication::quit();
}
