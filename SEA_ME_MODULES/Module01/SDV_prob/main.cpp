#include "SportsCar.h"
#include <memory>

using namespace std;

int main() {
    //Car* car = new SportsCar("Hyundai", "Avante", 2020, 500);
    unique_ptr<Car> car = make_unique<SportsCar>("Hyundai", "Avante", 2020, 300);
    car->drive();
    //delete car;
    return 0;
}