
#include <iostream>
#include <ctime>
#include <stdexcept>
using namespace std;

class Bill {
public:
    virtual double total() = 0;
    virtual ~Bill() {}
};

class OutPatient : public Bill {
public:
    double amount;

    OutPatient(double a) {
        amount = a;
    }

    double total() {
        return amount;
    }
};

class InPatient : public Bill {
public:
    double amount;

    InPatient(double a) {
        amount = a;
    }

    double total() {
        return amount;
    }
};

void benchmark(int n) {
    OutPatient op(1000);
    InPatient ip(1000);

    Bill* b[2] = {&op, &ip};

    double sum1 = 0;
    double sum2 = 0;

    clock_t start = clock();

    for (int i = 0; i < n; i++) {
        double amount = 1000 + (i % 500);

        op.amount = amount;
        ip.amount = amount;

        sum1 += b[i % 2]->total();
    }

    clock_t end = clock();

    double time1 = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();

    for (int i = 0; i < n; i++) {
        int type = i % 2;
        double amount = 1000 + (i % 500);

        switch (type) {
            case 0:
                sum2 += amount;
                break;

            case 1:
                sum2 += amount;
                break;
        }
    }

    end = clock();

    double time2 = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "\nNumber of Bills: " << n << endl;
    cout << "Virtual Function Total: " << sum1 << endl;
    cout << "Switch Statement Total: " << sum2 << endl;
    cout << "Virtual Function Time: " << time1 << " seconds" << endl;
    cout << "Switch Statement Time: " << time2 << " seconds" << endl;
}

bool validate(double amount) {
    return amount >= 0;
}

void checkAmount(double amount) {
    if (amount < 0)
        throw invalid_argument("Invalid Amount");
}

void exceptionTest(int n, int percentage) {
    int errors = 0;

    clock_t start = clock();

    for (int i = 0; i < n; i++) {
        double amount = (i % 100 < percentage) ? -10 : 100;

        if (!validate(amount))
            errors++;
    }

    clock_t end = clock();

    double time1 = (double)(end - start) / CLOCKS_PER_SEC;

    int returnErrors = errors;
    errors = 0;

    start = clock();

    for (int i = 0; i < n; i++) {
        double amount = (i % 100 < percentage) ? -10 : 100;

        try {
            checkAmount(amount);
        }
        catch (invalid_argument& e) {
            errors++;
        }
    }

    end = clock();

    double time2 = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "\nInvalid Percentage: " << percentage << "%" << endl;
    cout << "Return Code Errors: " << returnErrors << endl;
    cout << "Exception Errors: " << errors << endl;
    cout << "Return Code Time: " << time1 << " seconds" << endl;
    cout << "Exception Time: " << time2 << " seconds" << endl;
}

int main() {
    cout << "B3 PERFORMANCE COMPARISON" << endl;

    benchmark(10);
    benchmark(1000);
    benchmark(10000);

    cout << "\nEXCEPTION PERFORMANCE TEST" << endl;

    exceptionTest(10000, 0);
    exceptionTest(10000, 1);
    exceptionTest(10000, 50);

    cout << "\nProgram Completed Successfully!" << endl;

    cin.get();

    return 0;
}

