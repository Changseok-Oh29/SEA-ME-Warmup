#include "SportsCar.h"
#include <iostream>

SportsCar::SportsCar(string mk, string mdl, int yr, int speed)
    : Car(mk, mdl, yr), top_speed(speed) {}

int SportsCar::getTopSpeed() const {
    return top_speed;
}
void SportsCar::setTopSpeed(int speed) {
    top_speed = speed;
}

void SportsCar::drive() const {
    printBasicInfo();
    cout << "Top speed is " << top_speed << " km/h." << endl;
}