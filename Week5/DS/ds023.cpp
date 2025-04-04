#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int price;
    int discount;
    string size;
    string company;

public:
    Product() {
        name = "";
        price = 0;
        discount = 0;
        size = "";
        company = "";
    }

    void input() {
        cin.ignore(); 
        getline(cin, name);
        cin >> price >> discount >> size;
        cin.ignore(); 
        getline(cin, company);
    }

    int getDiscountedPrice() const {
        return price * (100 - discount) / 100;
    }

    void print() const {
        cout << getDiscountedPrice() << " ";
        cout << "(" << (-discount) << "%) ";
        cout << name << " " << size << " " << company << endl;
    }
};

int main() {
    Product* products[100]; 
    int count = 0;
    int command;

    while (true) {
        cout << "1. Add 2. List 3. Quit > ";
        cin >> command;

        if (command == 1) {
            products[count] = new Product();
            products[count]->input();
            count++;
        } else if (command == 2) {
            for (int i = 0; i < count; i++) {
                products[i]->print();
            }
        } else if (command == 3) {
            break;
        } else {
            cout << "Invalid command." << endl;
        }
    }

    for (int i = 0; i < count; i++) {
        delete products[i];
    }

    return 0;
}