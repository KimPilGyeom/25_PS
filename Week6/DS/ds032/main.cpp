#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MyStack.h"
using namespace std;

int main() {
    ifstream infile("input.txt");
    if (!infile) {
        cerr << "파일을 열 수 없습니다.\n";
        return 1;
    }

    MyStack stack(1000);  
    double maxGPA = -1;
    string line;

    while (getline(infile, line)) {
        stringstream ss(line);
        double gpa;
        string name;
        ss >> gpa >> name;

        if (gpa > maxGPA) {
            stack.initialize();
            stack.push(name);
            maxGPA = gpa;
        } else if (gpa == maxGPA) {
            stack.push(name);
        }
    }

    cout << "Top GPA: " << maxGPA << endl;
    stack.print();
    return 0;
}