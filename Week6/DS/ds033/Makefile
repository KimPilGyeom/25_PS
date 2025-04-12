all: coupon

coupon: main.o CouponStack.o
	g++ -o coupon main.o CouponStack.o

main.o: main.cpp CouponStack.h
	g++ -c main.cpp

CouponStack.o: CouponStack.cpp CouponStack.h
	g++ -c CouponStack.cpp

clean:
	rm -f *.o coupon