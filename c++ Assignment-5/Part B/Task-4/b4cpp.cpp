
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

    virtual double total() const = 0;

    virtual string type() const = 0;

    virtual ~Bill() {}
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(string p, double c, double t) : Bill(p) {
        consultation = c;
        tests = t;
    }

    double total() const {
        return consultation + tests;
    }

    string type() const {
        return "OutPatient";
    }
};

class InPatient : public Bill {
    int days;
    double rate, surgery;

public:
    InPatient(string p, int d, double r, double s) : Bill(p) {
        days = d;
        rate = r;
        surgery = s;
    }

    double total() const {
        return days * rate + surgery;
    }

    string type() const {
        return "InPatient";
    }
};

class EmergencyBill : public Bill {
    double emergencyCharge, treatmentCharge;

public:
    EmergencyBill(string p, double e, double t) : Bill(p) {
        emergencyCharge = e;
        treatmentCharge = t;
    }

    double total() const {
        return emergencyCharge + treatmentCharge;
    }

    string type() const {
        return "Emergency";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;

    virtual ~Payer() {}
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const {
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

    double amountCovered(const Bill& b) const {
        double amount = b.total();

        if (amount > limit)
            amount = limit;

        return amount * (1 - copay / 100);
    }
};

class CorporatePayer : public Payer {
    double percentage;

public:
    CorporatePayer(double p) {
        percentage = p;
    }

    double amountCovered(const Bill& b) const {
        return b.total() * percentage / 100;
    }
};

int main() {

    OutPatient op("Ravi", 500, 1200);
    InPatient ip("Meena", 3, 2500, 40000);
    EmergencyBill em("Arun", 5000, 15000);

    Bill* bills[3];

    bills[0] = &op;
    bills[1] = &ip;
    bills[2] = &em;

    SelfPay self;
    Insurance insurance(40000, 20);
    CorporatePayer corporate(90);

    for (int i = 0; i < 3; i++) {

        cout << bills[i]->type() << endl;

        cout << "Bill Total: "
             << bills[i]->total() << endl;

        cout << "Self Pay: "
             << self.amountCovered(*bills[i]) << endl;

        cout << "Insurance: "
             << insurance.amountCovered(*bills[i]) << endl;

        cout << "Corporate: "
             << corporate.amountCovered(*bills[i]) << endl;

        cout << endl;
    }

    return 0;
}


