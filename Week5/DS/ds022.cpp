#include <iostream>
#include <string>
using namespace std;

class EnglishScore {
private:
    string name;
    int lc;
    int rc;

    bool isValid(int score) const {
        return score >= 0 && score <= 495;
    }

    string getResult(int score) const {
        return (score >= 350) ? "Pass" : "Fail";
    }

public:
    EnglishScore() {
        name = "";
        lc = rc = 0;
    }

    EnglishScore(string n, int l, int r) {
        name = n;
        lc = l;
        rc = r;
    }

    void input() {
        getline(cin, name);

        do {
            cout << "LC> ";
            cin >> lc;
        } while (!isValid(lc));

        do {
            cout << "RC> ";
            cin >> rc;
        } while (!isValid(rc));
    }

    void printResult() const {
        cout << "[" << name << "]" << endl;
        cout << "LC - " << lc << " " << getResult(lc) << endl;
        cout << "RC - " << rc << " " << getResult(rc) << endl;
        cout << "Total - " << (lc + rc) << endl;
    }
};

int main() {
    EnglishScore student;
    student.input();
    student.printResult();

    return 0;
}