#ifndef MYSTACK_H
#define MYSTACK_H

#include <string>
using namespace std;

class MyStack {
private:
    int maxsize;
    int top;
    string* list;

public:
    MyStack(int size = 10);
    ~MyStack();
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void push(string elem);
    string pop();
    void print() const;
};

#endif