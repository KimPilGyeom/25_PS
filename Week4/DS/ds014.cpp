#include <iostream>
#include <string>
using namespace std;

void ltrim(string &s) {
    int i = 0;
    while (i < s.length() && (s[i] == ' ' || s[i] == '\t')) i++;
    s = s.substr(i);
}

void rtrim(string &s) {
    int i = s.length() - 1;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) i--;
    s = s.substr(0, i + 1);
}

int main() {
    string input;
    getline(cin, input);

    ltrim(input);
    rtrim(input);

    cout << input << endl;
    return 0;
}