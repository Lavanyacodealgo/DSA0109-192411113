#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    return abs(first - second);
}
inline bool earlier(const Time& a, const Time& b) {
    return a.h < b.h || (a.h == b.h && a.m < b.m);
}

int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';
    Time noonBefore(11, 59), noonAfter(12, 1), same(12, 1);
    cout << minutesBetween(noonBefore, noonAfter) << ' '
         << earlier(noonBefore, noonAfter) << ' '
         << earlier(same, noonAfter) << '\n';
}