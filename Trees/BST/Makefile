BinarySearchTree: main.o Test.o
	g++ -g -std=c++11 -Wall main.o Test.o -o BinarySearchTree
	
main.o: main.cpp BinarySearchTree.h BinarySearchTree.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp
	
Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp
	
clean:
	rm *.o BinarySearchTree
	echo clean done