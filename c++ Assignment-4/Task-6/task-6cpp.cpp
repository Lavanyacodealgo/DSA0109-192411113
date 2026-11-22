
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double rate;
    bool rented;

public:
    Vehicle(string r, double d) {
        regNo = r;
        rate = d;
        rented = false;
    }

    virtual double charge(int days) = 0;

    void rent() {
        rented = true;
        cout << regNo << " rented successfully" << endl;
    }

    void returnVehicle(int lateDays) {
        rented = false;
        cout << regNo << " returned successfully" << endl;
        cout << "Late charge: " << lateDays * 200 << endl;
    }

    virtual void display() {
        cout << "Registration: " << regNo << endl;
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double d) : Vehicle(r, d) {}

    double charge(int days) {
        return rate * days;
    }
};

class TwoWheeler : public Vehicle {
public:
    TwoWheeler(string r, double d) : Vehicle(r, d) {}

    double charge(int days) {
        return rate * days;
    }
};

class Car : public Vehicle {
    int seats;

public:
    Car(string r, double d, int s) : Vehicle(r, d) {
        seats = s;
    }

    double charge(int days) {
        return rate * days;
    }

    void display() {
        Vehicle::display();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Vehicle {
    double battery;

public:
    ElectricCar(string r, double d, double b)
        : Vehicle(r, d) {
        battery = b;
    }

    double charge(int days) {
        return rate * days + battery * 10;
    }

    void display() {
        Vehicle::display();
        cout << "Battery: " << battery << " kWh" << endl;
    }
};

class ElectricBus : public Vehicle {
public:
    ElectricBus(string r, double d) : Vehicle(r, d) {}

    double charge(int days) {
        return rate * days + 500;
    }
};

int main() {
    Bicycle b("B101", 100);
    TwoWheeler t("T102", 200);
    Car c("C103", 1000, 5);
    ElectricCar e("E104", 1500, 50);

    Vehicle* v[4] = {&b, &t, &c, &e};

    cout << "VEHICLE RENTAL SYSTEM" << endl;

    for (int i = 0; i < 4; i++) {
        v[i]->display();
        cout << "Rental Charge: " << v[i]->charge(2) << endl;
        cout << endl;
    }

    cout << "RENTING VEHICLES" << endl;

    for (int i = 0; i < 4; i++) {
        v[i]->rent();
    }

    cout << "\nRETURNING VEHICLES" << endl;

    for (int i = 0; i < 4; i++) {
        v[i]->returnVehicle(i);
    }

    cout << "\nADDING ELECTRIC BUS" << endl;

    ElectricBus bus("EB105", 2000);

    Vehicle* newVehicle = &bus;

    newVehicle->display();
    cout << "Rental Charge: " << newVehicle->charge(2) << endl;

    return 0;
}

