#ifndef COUPONSTACK_H
#define COUPONSTACK_H

#include <string>
using namespace std;

struct Coupon {
    int number;
    string name;
};

class CouponStack {
private:
    int maxsize;
    int top;
    Coupon* list;

public:
    CouponStack(int size = 10);
    ~CouponStack();
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void push(Coupon elem);
    Coupon pop();
    void print() const;
    void printPopAll(); 
};

#endif