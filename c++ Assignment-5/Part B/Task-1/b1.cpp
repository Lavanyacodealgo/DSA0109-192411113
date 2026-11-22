
#include <iostream>
#include <string>
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

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(string p, double c, double t) : Bill(p) {
        consultation = c;
        tests = t;
    }

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OP";
    }
};

class InPatient : public Bill {
    int days;
    double perDay, surgery;

public:
    InPatient(string p, int d, double r, double s) : Bill(p) {
        days = d;
        perDay = r;
        surgery = s;
    }

    double total() const override {
        return days * perDay + surgery;
    }

    string type() const override {
        return "IP";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual ~Payer() {}
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total();
    }
};

class Insurance : public Payer {
    double limit, copay;

public:
    Insurance(double l, double c) {
        limit = l;
        copay = c;
    }

    double amountCovered(const Bill& b) const override {
        double amount = b.total();

        if (amount > limit)
            amount = limit;

        return amount * (1 - copay / 100);
    }
};

class GovernmentScheme : public Payer {
    double rate;

public:
    GovernmentScheme(double r) {
        rate = r;
    }

    double amountCovered(const Bill& b) const override {
        return b.total() < rate ? b.total() : rate;
    }
};

int main() {
    OutPatient op("Ravi", 500, 1200);
    InPatient ip("Meena", 3, 2500, 40000);

    SelfPay s;
    Insurance i(40000, 20);
    GovernmentScheme g(30000);

    Bill* bills[2] = {&op, &ip};

    for (int j = 0; j < 2; j++) {
        bills[j]->print();

        cout << "Self Pay: " << s.amountCovered(*bills[j]) << endl;
        cout << "Insurance: " << i.amountCovered(*bills[j]) << endl;
        cout << "Government: " << g.amountCovered(*bills[j]) << endl;
        cout << endl;
    }

    return 0;
}

