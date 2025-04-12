#include <iostream>
#include <sstream>
#include "CouponStack.h"
using namespace std;

int main() {
    int size;
    cin >> size;
    cin.ignore(); 

    CouponStack stack(size);
    string line;

    while (getline(cin, line)) {
        if (line[0] == '+') {
            stringstream ss(line.substr(1));
            Coupon c;
            ss >> c.number;
            getline(ss, c.name);
            if (c.name[0] == ' ') c.name = c.name.substr(1);
            stack.push(c);
        } else if (line[0] == '-') {
            Coupon c = stack.pop();
            cout << c.number << " = " << c.name << endl;
        } else if (line[0] == 'q') {
            stack.printPopAll();
            break;
        }
    }
    return 0;
}