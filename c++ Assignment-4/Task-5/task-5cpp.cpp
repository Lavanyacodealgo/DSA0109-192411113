
#include <iostream>
using namespace std;

class Account {
public:
    virtual double rate() {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account destroyed" << endl;
    }
};

class SeniorAccount : public Account {
    double* history;

public:
    SeniorAccount() {
        history = new double[100];
    }

    double rate() {
        return 4.0;
    }

    ~SeniorAccount() {
        delete[] history;
        cout << "SeniorAccount destroyed" << endl;
    }
};

int main() {
    Account* a[2];

    a[0] = new Account();
    a[1] = new SeniorAccount();

    for (int i = 0; i < 2; i++) {
        cout << a[i]->rate() << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete a[i];
    }

    return 0;
}

