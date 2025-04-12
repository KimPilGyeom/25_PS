#include <iostream>
#include <string>
#include "MyStack.h"
using namespace std;

int main() {
    int size;
    cin >> size;
    MyStack s(size);

    string cmd;
    int value;
    while (cin >> cmd) {
        if (cmd == "push") {
            cin >> value;
            s.push(value);
        } else if (cmd == "pop") {
            s.pop();
        } else if (cmd == "print") {
            s.print();
            break;
        }
    }

    return 0;
}