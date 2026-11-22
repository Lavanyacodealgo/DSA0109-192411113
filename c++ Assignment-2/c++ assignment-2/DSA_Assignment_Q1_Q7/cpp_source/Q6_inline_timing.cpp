#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

volatile long long sinkValue = 0;
inline int fastAdd(int a, int b) { return a + b; }
#if defined(_MSC_VER)
#define NOINLINE __declspec(noinline)
#else
#define NOINLINE __attribute__((noinline))
#endif
NOINLINE int normalAdd(int a, int b) { return a + b; }

int main() {
    const int N = 10000000;
    auto start1 = steady_clock::now();
    long long s1 = 0;
    for (int i = 0; i < N; ++i) s1 += fastAdd(i % 100, 3);
    sinkValue = s1;
    auto end1 = steady_clock::now();

    auto start2 = steady_clock::now();
    long long s2 = 0;
    for (int i = 0; i < N; ++i) s2 += normalAdd(i % 100, 3);
    sinkValue = s2;
    auto end2 = steady_clock::now();

    cout << "inline loop ms: "
         << duration<double, milli>(end1 - start1).count() << '\n';
    cout << "noinline loop ms: "
         << duration<double, milli>(end2 - start2).count() << '\n';
    cout << "checksum: " << sinkValue << '\n';
}