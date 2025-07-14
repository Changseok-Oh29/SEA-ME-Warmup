#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include "Car.h"
#include "RaceTrack.h"
#include "CarThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startRace();
    void pauseRace();
    void exitGame();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    RaceTrack *raceTrack;
    QList<Car*> carList;
    QList<int> originalSpeeds;
    QList<CarThread*> threadList;
    QList<QGraphicsPixmapItem*> carItems;
    QGraphicsPixmapItem *backgroundItem;

    bool isPaused{false};
    void on_btnStart_clicked();
};

#endif // RACINGGAME_H
