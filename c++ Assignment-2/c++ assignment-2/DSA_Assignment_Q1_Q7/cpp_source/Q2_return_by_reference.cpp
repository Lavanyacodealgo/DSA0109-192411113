#include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int best = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}

// Deliberately unsafe: compile only to observe the compiler warning.
// Never call this function.
int& danglingReference() {
    int local = 75;
    return local;
}

int highestIndex(const int marks[], int size) {
    int best = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[best]) best = i;
    return best;
}
int* highestPointer(int marks[], int size) {
    return &marks[highestIndex(marks, size)];
}

int main() {
    int marks[] = {78, 91, 86, 95, 88};
    int n = sizeof(marks) / sizeof(marks[0]);
    cout << "Highest before moderation: " << highestMark(marks, n) << '\n';
    highestMark(marks, n) += 2;
    cout << "Highest after moderation: " << highestMark(marks, n) << '\n';

    int idx = highestIndex(marks, n);
    cout << "Index result: " << idx << ", mark: " << marks[idx] << '\n';
    int* p = highestPointer(marks, n);
    cout << "Pointer result: " << *p << '\n';
}