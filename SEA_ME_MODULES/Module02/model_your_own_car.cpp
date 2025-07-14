#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Part {
protected:
    string name;
    double weight;

public:
    Part(const string& name, double weight) : name(name), weight(weight) {}
    virtual void print() const = 0;
    virtual ~Part() {}
};

class Engine : public Part {
public:
    Engine(const string& name, double weight) : Part(name, weight) {}

    void print() const override {
        cout << "[Engine] Name: " << name << ", Weight: " << weight << " kg" << endl;
    }
};

class Wheel : public Part {
public:
    Wheel(const string& name, double weight) : Part(name, weight) {}

    void print() const override {
        cout << "[Wheel] Name: " << name << ", Weight: " << weight << " kg" << endl;
    }
};

class Brake : public Part {
public:
    Brake(const string& name, double weight) : Part(name, weight) {}

    void print() const override {
        cout << "[Brake] Name: " << name << ", Weight: " << weight << " kg" << endl;
    }
};

class Transmission : public Part {
public:
    Transmission(const string& name, double weight) : Part(name, weight) {}

    void print() const override {
        cout << "[Transmission] Name: " << name << ", Weight: " << weight << " kg" << endl;
    }
};

class Car {
private:
    vector<unique_ptr<Part>> parts;
    /*
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
    */

public:
    Car() {
        parts.push_back(make_unique<Engine>("V8 Twin Turbo", 350.0));
        parts.push_back(make_unique<Transmission>("8-Speed Auto", 150.0));

        for (int i=1;i<=4;i++) {
            parts.push_back(make_unique<Wheel>("Wheel " + to_string(i), 25.0));
            parts.push_back(make_unique<Brake>("Brake " + to_string(i), 10.0));
        }
        /*
        engine_ = new Engine();
        wheels_ = new Wheel[4];
        brakes_ = new Brake[4];
        transmission_ = new Transmission();
        */
    }

    void printParts() const {
        cout << "--- Car Parts ---" << endl;
        for (const auto& part : parts) {
            part -> print();
        }
    }

    /*
    void printParts() {
        engine_->print();
        for (int i=0;i<4;i++) {
            wheels_[i].print();
            brakes_[i].print();
        }
        transmission_->print();
    }

    ~Car() {
        delete engine_;
        delete[] wheels_;
        delete[] brakes_;
        delete transmission_;
    }
    */


};

int main() {
    Car myCar;
    myCar.printParts();
    return 0;
}