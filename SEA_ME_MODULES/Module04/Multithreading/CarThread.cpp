#include "CarThread.h"
#include <QMutex>

QMutex CarThread::mutex;

CarThread::CarThread(Car* car, RaceTrack* track) : car(car), raceTrack(track) {}

void CarThread::run() {
    while (car->getPosition() < raceTrack->getFinishLine()) {
        mutex.lock();
        car->move();
        mutex.unlock();
        msleep(10);
    }
}
