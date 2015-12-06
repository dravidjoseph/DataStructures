DLL: main.o
	g++ -g -std=c++11 -Wall main.o -o DLL
	
main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp DoubleNode.h DoubleNode.hpp
	g++ -g -std=c++11 -Wall -c main.cpp
	
clean:
	rm *.o DLL
	echo clean done