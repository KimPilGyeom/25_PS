#include <iostream>
#include <string>
using namespace std;

string getCommonPrefix(string* a, string* b, string* c) {
    string result = "";
    int i = 0;

    while ((*a)[i] && (*b)[i] && (*c)[i]) {
        if ((*a)[i] == (*b)[i] && (*b)[i] == (*c)[i]) {
            result += (*a)[i];
            i++;
        } else {
            break;
        }
    }

    if (result == "") return "?";
    return result;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    string res = getCommonPrefix(&s1, &s2, &s3);
    cout << res << endl;

    return 0;
}