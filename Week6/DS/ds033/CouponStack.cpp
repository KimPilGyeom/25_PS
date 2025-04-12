#include "CouponStack.h"
#include <iostream>
using namespace std;

CouponStack::CouponStack(int size) {
    maxsize = size;
    top = -1;
    list = new Coupon[maxsize];
}

CouponStack::~CouponStack() {
    delete[] list;
}

void CouponStack::initialize() {
    top = -1;
}

bool CouponStack::isEmpty() const {
    return top == -1;
}

bool CouponStack::isFull() const {
    return top == maxsize - 1;
}

void CouponStack::push(Coupon elem) {
    if (!isFull()) list[++top] = elem;
}

Coupon CouponStack::pop() {
    if (!isEmpty()) return list[top--];

    Coupon c;
    c.number = -1;
    c.name = "스택이 비었습니다";
    return c;
}

void CouponStack::print() const {
    for (int i = top; i >= 0; i--)
        cout << list[i].number << " = " << list[i].name << endl;
}

void CouponStack::printPopAll() {
    while (!isEmpty()) {
        Coupon c = pop();
        cout << c.number << " = " << c.name << endl;
    }
}