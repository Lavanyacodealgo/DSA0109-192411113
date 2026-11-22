
#include <iostream>
using namespace std;

class Bill {
public:
    virtual ~Bill() {
        cout << "~Bill ";
    }

    virtual double total() const = 0;

    void show() const {
        cout << total() << " ";
    }
};

class OutPatientBill : public Bill {
public:
    ~OutPatientBill() override {
        cout << "~OPBill ";
    }

    double total() const override {
        return 500;
    }
};

class InPatientBill : public Bill {
public:
    ~InPatientBill() override {
        cout << "~IPBill ";
    }

    double total() const override {
        return 1000;
    }
};

int main() {
    Bill* b = new OutPatientBill();

    b->show();

    delete b;

    cout << endl;

    return 0;
}

