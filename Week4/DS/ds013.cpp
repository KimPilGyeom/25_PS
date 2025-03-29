#include <iostream>
using namespace std;

struct Menu {
    char name[100];
    int price;
};

struct Cafe {
    char name[100];
    int menuCount;
    Menu* menus;
};

void addCafe(Cafe& r1) {
    cin.getline(r1.name, 100); 
    cin >> r1.menuCount;
    r1.menus = new Menu[r1.menuCount];
}

void addMenu(Menu& m1) {
    cin >> m1.name >> m1.price;
}

void displayMenus(Cafe& r1) {
    cout << "===== " << r1.name << " =====" << endl;
    for (int i = 0; i < r1.menuCount; i++) {
        cout << r1.menus[i].name << " " << r1.menus[i].price << endl;
    }
    cout << "===================" << endl;
}

int main() {
    Cafe c;
    addCafe(c);
    for (int i = 0; i < c.menuCount; i++) {
        addMenu(c.menus[i]);
    }
    displayMenus(c);
    delete[] c.menus;
    return 0;
}