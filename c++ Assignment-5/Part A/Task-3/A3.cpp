
#include <iostream>
#include <string>
using namespace std;

class Bill {
public:
    double amount;

    Bill(double a) {
        amount = a;
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
        return b.amount;
    }
};

class Insurance : public Payer {
    double coverLimit;
    double copayment;

public:
    Insurance(double limit, double percent) {
        coverLimit = limit;
        copayment = percent;
    }

    double amountCovered(const Bill& b) const override {
        double covered = b.amount;

        if (covered > coverLimit)
            covered = coverLimit;

        return covered * (1 - copayment / 100);
    }
};

class GovernmentScheme : public Payer {
    double packageRate;

public:
    GovernmentScheme(double rate) {
        packageRate = rate;
    }

    double amountCovered(const Bill& b) const override {
        return b.amount < packageRate ? b.amount : packageRate;
    }
};

class CorporatePayer : public Payer {
    double percentage;

public:
    CorporatePayer(double p) {
        percentage = p;
    }

    double amountCovered(const Bill& b) const override {
        return b.amount * percentage / 100;
    }
};

int main() {
    Bill b(50000);

    SelfPay s;
    Insurance i(40000, 20);
    GovernmentScheme g(30000);
    CorporatePayer c(90);

    cout << "Self Pay: " << s.amountCovered(b) << endl;
    cout << "Insurance: " << i.amountCovered(b) << endl;
    cout << "Government: " << g.amountCovered(b) << endl;
    cout << "Corporate: " << c.amountCovered(b) << endl;

    return 0;
}

