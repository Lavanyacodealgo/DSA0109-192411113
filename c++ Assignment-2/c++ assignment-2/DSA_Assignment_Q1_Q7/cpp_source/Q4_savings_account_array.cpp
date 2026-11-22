#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
    string accountNumber;
    long long balance;
    long long transactions[10];
    int count;

    void record(long long amount) {
        if (count < 10) {
            transactions[count++] = amount;
        } else {
            for (int i = 1; i < 10; ++i)
                transactions[i - 1] = transactions[i];
            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(const string& number, long long openingBalance)
        : accountNumber(number), balance(openingBalance), count(0) {}

    void deposit(long long amount) {
        if (amount <= 0) return;
        balance += amount;
        record(amount);
    }

    void withdraw(long long amount);

    void miniStatement() const {
        cout << "Account: " << accountNumber << "\nBalance: " << balance << '\n';
        cout << "Recent transactions (oldest to newest):\n";
        for (int i = 0; i < count; ++i)
            cout << transactions[i] << '\n';
    }
};

void SavingsAccount::withdraw(long long amount) {
    if (amount <= 0 || amount > balance) return;
    balance -= amount;
    record(-amount);
}

int main() {
    SavingsAccount account("SIMATS1001", 5000);
    account.deposit(500);
    account.withdraw(200);
    for (int i = 1; i <= 10; ++i) account.deposit(i * 10);
    account.miniStatement();
}