#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string name;
    int speed;

public:
    Car(string n = "", int s = 0) { // default constructor
        name = n;
        speed = s;
    }

    Car(const Car& other) { // copy constructor
        name = other.name;
        speed = other.speed;
    }

    Car& operator = (const Car& other) { // copy assignment operator
        if (this != &other) {
            name = other.name;
            speed = other.speed;
        }
        return *this;
    }

    ~Car() {} // destructor

    void print() const {
        cout << "Car: " << name << ", speed: " << speed << "km/h\n";
    }


};

int main() {
    Car a; // default constructor
    a.print();

    Car b("Hyundai", 100);
    b.print();

    Car c = b; // copy constructor
    c.print();

    a = c;
    a.print();

    return 0;
}