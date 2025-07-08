#include <string>
#include <iostream>

using namespace std;

class Car {
private:
    string make;
    string model;
    int year;

public:
    Car(string mk, string mdl, int yr) : make(mk), model(mdl), year(yr) {}

    void drive() {
        cout << "Driving " << make << " " << model << " " << year << "edition" << endl;
    }
};

class SportsCar : public Car {
private:
    int top_speed;

public:
    SportsCar(string mk, string mdl, int yr, int speed) : Car(mk, mdl, yr), top_speed(speed) {}

    void drive() {
        Car::drive();
        cout << "Top speed is " << top_speed << endl;
    }
};

int main() {
    SportsCar sc("Porsche", "911", 2022, 330);
    sc.drive();
    return 0;
}