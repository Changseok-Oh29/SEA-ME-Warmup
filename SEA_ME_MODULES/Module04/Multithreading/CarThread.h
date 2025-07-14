#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include "Car.h"
#include "RaceTrack.h"

class CarThread : public QThread {
    Q_OBJECT

private:
    Car* car;
    RaceTrack* raceTrack;
    static QMutex mutex;

public:
    CarThread(Car* car, RaceTrack* track);

protected:
    void run() override;

};

#endif // CARTHREAD_H
