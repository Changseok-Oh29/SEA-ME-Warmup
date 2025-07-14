#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car {
private:
    string make;
    string model;
    int year;

protected:
    void printBasicInfo() const;

public:
    Car(string mk, string mdl, int yr);

    string getMake() const;
    string getModel() const;
    int getYear() const;

    void setMake(const string& mk);
    void setModel(const string& mdl);
    void setYear(int yr);

    virtual void drive() const = 0;
    virtual ~Car() {}
};

#endif