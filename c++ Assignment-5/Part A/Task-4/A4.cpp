
#include <iostream>
#include <stdexcept>
#include <string>
#include <new>
using namespace std;

class BillingError : public runtime_error {
public:
    BillingError(string msg) : runtime_error(msg) {}
};

class ClaimError : public BillingError {
public:
    ClaimError(string msg) : BillingError(msg) {}
};

class NegativeChargeError : public BillingError {
public:
    NegativeChargeError() : BillingError("Negative charge") {}
};

class UnknownPackageError : public BillingError {
public:
    UnknownPackageError() : BillingError("Unknown package") {}
};

class MissingPatientError : public BillingError {
public:
    MissingPatientError() : BillingError("Missing patient record") {}
};

double calculateBill(double charge) {
    if (charge < 0)
        throw NegativeChargeError();

    if (charge > 50000)
        throw ClaimError("Claim exceeds cover");

    return charge;
}

double packageAmount(int code) {
    if (code == 1)
        return 10000;

    if (code == 2)
        return 20000;

    throw UnknownPackageError();
}

void checkPatient(bool found) {
    if (!found)
        throw MissingPatientError();
}

int main() {
    try {
        cout << "Bill: " << calculateBill(15000) << endl;
        cout << "Package: " << packageAmount(1) << endl;

        checkPatient(true);

        cout << "Patient record found" << endl;
    }
    catch (const BillingError& e) {
        cout << "Billing Error: " << e.what() << endl;
    }
    catch (const bad_alloc& e) {
        cout << "Memory Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

