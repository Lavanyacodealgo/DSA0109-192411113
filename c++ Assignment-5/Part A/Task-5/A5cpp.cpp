
#include <iostream>
#include <string>
using namespace std;

class Guard {
    string name;

public:
    Guard(string s) {
        name = s;
    }

    ~Guard() {
        cout << "~" << name << " ";
    }
};

void f() {
    Guard g("f");

    throw 42;
}

void process() {
    try {
        f();
    }
    catch (int x) {
        cout << "Log: " << x << " ";
        throw;
    }
}

int main() {
    Guard m("main");

    try {
        process();

        cout << "Not printed ";
    }
    catch (int x) {
        cout << "Caught " << x;
    }
    catch (...) {
        cout << "Other error";
    }

    cout << endl;

    return 0;
}

