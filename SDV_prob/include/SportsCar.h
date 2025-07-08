#ifndef SPORTSCAR_H
#define SPORTSCAR_H

#include "Car.h"

class SportsCar : public Car {
private:
    int top_speed;

public:
    SportsCar(string mk, string mdl, int yr, int speed);

    int getTopSpeed() const;
    void setTopSpeed(int speed);

    void drive() const override;
};

#endif