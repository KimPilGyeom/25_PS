all: stack

stack: main.o MyStack.o
	g++ -o stack main.o MyStack.o

main.o: main.cpp MyStack.h
	g++ -c main.cpp

MyStack.o: MyStack.cpp MyStack.h
	g++ -c MyStack.cpp

clean:
	rm -f *.o stack