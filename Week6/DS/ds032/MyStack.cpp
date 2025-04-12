#include "MyStack.h"
#include <iostream>
using namespace std;

MyStack::MyStack(int size) {
    maxsize = size;
    top = -1;
    list = new string[maxsize];
}

MyStack::~MyStack() {
    delete[] list;
}

void MyStack::initialize() {
    top = -1;
}

bool MyStack::isEmpty() const {
    return top == -1;
}

bool MyStack::isFull() const {
    return top == maxsize - 1;
}

void MyStack::push(string elem) {
    if (!isFull()) {
        list[++top] = elem;
    }
}

string MyStack::pop() {
    if (!isEmpty()) {
        return list[top--];
    }
    return "";
}

void MyStack::print() const {
    for (int i = top; i >= 0; --i) {
        cout << list[i] << endl;
    }
}