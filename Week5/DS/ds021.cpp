#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    double getAvg() const{
        return (score[0] + score[1] + score[2]) / 3.0;
    }

public:
    string name;
    string sid;
    int *score;

    Student() {
        score = new int[3];
    }

    void print() const {
        cout << "[" << sid << "] " << name << endl;
        cout << "The Average score is " << getAvg() << endl;
    }
};

int main() {
    Student s;

    cin >> s.sid >> s.score[0] >> s.score[1] >> s.score[2];
    cin.ignore(); 
    getline(cin, s.name);

    s.print();

    return 0;
};