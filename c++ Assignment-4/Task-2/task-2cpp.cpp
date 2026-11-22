
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int id;
    string phone;

    Person(string n, int i, string p) {
        name = n;
        id = i;
        phone = p;
    }
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p, string pr, double c)
        : Person(n, i, p) {
        programme = pr;
        cgpa = c;
    }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p) {
        department = d;
        salary = s;
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p, string pr,
                      double c, string d, double s)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {}

    void display() {
        cout << name << endl;
        cout << id << endl;
        cout << phone << endl;
        cout << programme << endl;
        cout << department << endl;
    }
};

class ResearchScholar : public Student {
    double fellowship;

public:
    ResearchScholar(string n, int i, string p, string pr,
                    double c, double f)
        : Person(n, i, p), Student(n, i, p, pr, c) {
        fellowship = f;
    }

    void display() {
        cout << name << endl;
        cout << programme << endl;
        cout << fellowship << endl;
    }
};

int main() {
    TeachingAssistant t("Lavanya", 101, "9876543210",
                        "CSE", 8.5, "Computer Science", 30000);

    ResearchScholar r("Kavya", 102, "9876543211",
                      "CSE", 9.0, 15000);

    cout << "Teaching Assistant:" << endl;
    t.display();

    cout << "\nResearch Scholar:" << endl;
    r.display();

    return 0;
}

