#include <iostream>
#include <string>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

double charge(int grams) {
    cout << "int grams overload: ";
    return 30.0 + grams * 0.02;
}
double charge(double weightKg, bool express = false, bool insured = false) {
    cout << "double kg overload: ";
    double total = 40.0 + weightKg * 20.0;
    if (express) total += 25.0;
    if (insured) total += 15.0;
    return total;
}
double charge(const Parcel& p) {
    cout << "Parcel overload: ";
    return charge(p.weightKg, p.express, p.insured);
}

int main() {
    Parcel p{2.5, true, false};
    cout << charge(2) << '\n';
    cout << charge(2.0) << '\n';
    cout << charge(2.0f) << '\n';
    cout << charge(2.0, true) << '\n';
    cout << charge(2.0, true, true) << '\n';
    cout << charge(p) << '\n';
}