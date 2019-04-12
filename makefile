LFLAG= -Wall
CFLAGS= -Wall -std=c++14 -g -O0 -pedantic-errors


main: main.cpp BinaryTree.o ItemType.o
	g++ $(LFLAG) -o main main.cpp BinaryTree.o ItemType.o -g
run: main.cpp BinaryTree.o ItemType.o
	g++ -std=c++14 -g -o run main.cpp BinaryTree.o ItemType.o -g

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ $(CFLAGS) -c BinaryTree.cpp

ItemType.o: ItemType.cpp ItemType.h
	g++ $(CFLAGS) -c ItemType.cpp

clean:
	rm *.o main