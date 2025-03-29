#include <iostream>
using namespace std;

struct Product {
    char name[100];
    int price;
    char company[100];
};

void toLowerCase(char* str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 32;
        }
        str++;
    }
}

bool isSameStringIgnoreCase(char* a, char* b) {
    char tempA[100], tempB[100];
    int i = 0;
    while (*(a + i)) {
        tempA[i] = *(a + i);
        i++;
    }
    tempA[i] = '\0';

    i = 0;
    while (*(b + i)) {
        tempB[i] = *(b + i);
        i++;
    }
    tempB[i] = '\0';

    toLowerCase(tempA);
    toLowerCase(tempB);

    i = 0;
    while (tempA[i] && tempB[i]) {
        if (tempA[i] != tempB[i]) return false;
        i++;
    }

    return tempA[i] == '\0' && tempB[i] == '\0';
}

bool isEqual(Product* p1, Product* p2) {
    return (isSameStringIgnoreCase(p1->name, p2->name) && p1->price == p2->price);
}

int main() {
    Product p1, p2;

    cin >> p1.name >> p1.price >> p1.company;
    cin >> p2.name >> p2.price >> p2.company;

    if (isEqual(&p1, &p2)) {
        cout << p1.name << " is equal" << endl;
    } else {
        cout << p1.name << " and " << p2.name << " is not equal" << endl;
    }

    return 0;
}