
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <new>
#include <limits>
using namespace std;

class ClaimError : public runtime_error {
public:
    ClaimError(string msg) : runtime_error(msg) {}
};

double approve(double billed, double cover) {
    if (billed < 0 || cover < 0)
        throw invalid_argument("negative amount");

    if (billed > cover)
        throw ClaimError("exceeds cover");

    return billed;
}

double settle(double billed, double cover) {
    try {
        return approve(billed, cover);
    }
    catch (const ClaimError& e) {
        cout << "audit: " << e.what() << endl;
        throw;
    }
}

double packageAmount(int code) {
    if (code == 1)
        return 10000;

    if (code == 2)
        return 20000;

    throw runtime_error("unknown package");
}

int main() {

    double cases[][2] = {
        {40000, 50000},
        {60000, 50000},
        {-1, 50000}
    };

    for (int i = 0; i < 3; i++) {
        try {
            double paid = settle(cases[i][0], cases[i][1]);
            cout << "approved " << paid << endl;
        }
        catch (const ClaimError& e) {
            cout << "claim rejected: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "error: " << e.what() << endl;
        }
    }

    try {
        double package = packageAmount(5);
        cout << "Package: " << package << endl;
    }
    catch (const exception& e) {
        cout << "Package Error: " << e.what() << endl;
    }

    try {
        string value = "hello";
        stringstream ss(value);
        double amount;

        if (!(ss >> amount))
            throw invalid_argument("invalid number");

        cout << amount << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Invalid number: " << e.what() << endl;
    }

    try {
        char* memory = new char[numeric_limits<size_t>::max()];
        delete[] memory;
    }
    catch (const bad_alloc& e) {
        cout << "Memory allocation failed" << endl;
    }

    return 0;
}



