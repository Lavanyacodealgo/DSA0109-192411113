
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bill {
protected:
    string patient;

public:
    Bill(string p) {
        patient = p;
    }

    virtual ~Bill() {}

    virtual double total() const = 0;

    virtual string type() const = 0;

    void print() const {
        cout << type() << " " << patient << ": " << total() << endl;
    }
};

class OutPatientBill : public Bill {
    double consultation, tests;

public:
    OutPatientBill(string p, double c, double t) : Bill(p) {
        consultation = c;
        tests = t;
    }

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OutPatient";
    }
};

class InPatientBill : public Bill {
    int days;
    double perDay, surgery;

public:
    InPatientBill(string p, int d, double r, double s) : Bill(p) {
        days = d;
        perDay = r;
        surgery = s;
    }

    double total() const override {
        return days * perDay + surgery;
    }

    string type() const override {
        return "InPatient";
    }
};

int main() {
    Bill* bills[2];

    bills[0] = new OutPatientBill("Ravi", 500, 1200);
    bills[1] = new InPatientBill("Meena", 3, 2500, 40000);

    double sum = 0;

    for (int i = 0; i < 2; i++) {
        bills[i]->print();
        sum += bills[i]->total();
    }

    cout << "Day Total: " << sum << endl;

    for (int i = 0; i < 2; i++) {
        delete bills[i];
    }

    return 0;
}

