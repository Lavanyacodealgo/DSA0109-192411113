#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class ShiftHistory {
    int data[10]{};
    int count = 0;
public:
    void add(int x) {
        if (count < 10) data[count++] = x;
        else {
            for (int i = 1; i < 10; ++i) data[i - 1] = data[i];
            data[9] = x;
        }
    }
    int newest() const { return data[(count == 0 ? 0 : count - 1)]; }
};

class CircularHistory {
    int data[10]{};
    int start = 0;
    int count = 0;
public:
    void add(int x) {
        if (count < 10) {
            data[(start + count) % 10] = x;
            ++count;
        } else {
            data[start] = x;
            start = (start + 1) % 10;
        }
    }
    int newest() const { return data[(start + count - 1) % 10]; }
};

int main() {
    ShiftHistory oldDesign;
    CircularHistory newDesign;
    const int N = 1000000;
    auto a = steady_clock::now();
    for (int i = 0; i < N; ++i) oldDesign.add(i);
    auto b = steady_clock::now();
    for (int i = 0; i < N; ++i) newDesign.add(i);
    auto c = steady_clock::now();

    cout << "Original shift newest: " << oldDesign.newest() << '\n';
    cout << "Redesigned circular newest: " << newDesign.newest() << '\n';
    cout << "Original shift ms: " << duration<double, milli>(b-a).count() << '\n';
    cout << "Circular buffer ms: " << duration<double, milli>(c-b).count() << '\n';
}