#include "Car.h"

Car::Car(QObject *parent) : QObject(parent), position(0), speed(1), direction(1), name() {}

int Car::getPosition() const { return position; }
int Car::getSpeed() const { return speed; }
int Car::getDirection() const { return direction; }
QString Car::getName() const { return name; }

void Car::setPosition(int pos) {
    if (position == pos) return;
    position = pos;
    emit positionChanged(pos);
}
void Car::setSpeed(int sp) { speed = sp; }
void Car::setDirection(int dir) { direction = dir; }
void Car::setName(const QString &nme) { name = nme; }

void Car::move() {
    position += speed * direction;
    emit positionChanged(position);
}
