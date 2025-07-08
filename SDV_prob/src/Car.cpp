#include "Car.h"
#include <iostream>

using namespace std;

Car::Car(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr) {}

string Car::getMake() const {
    return make;
}
string Car::getModel() const {
    return model;
}
int Car::getYear() const {
    return year;
}

void Car::setMake(const string& mk) {
    make = mk;
}
void Car::setModel(const string& mdl) {
    model = mdl;
}
void Car::setYear(int yr) {
    year = yr;
}

void Car::printBasicInfo() const {
    cout << "Driving " << make << " " << model << " " << year << " edition." << endl;
}