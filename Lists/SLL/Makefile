SLL: main.o 
	g++ -g -std=c++11 main.o -o SLL
	
main.o: main.cpp SingleNode.h SingleNode.hpp LinkedList.h LinkedList.hpp
	g++ -g -std=c++11 -c main.cpp
	
clean:
	rm *.o SLL
	echo clean done