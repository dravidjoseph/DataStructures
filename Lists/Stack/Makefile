Stack: main.o PreconditionViolationException.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o -o Stack
	
main.o: main.cpp Stack.h Stack.hpp SingleNode.h SingleNode.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp
	
clean:
	rm *.o Stack
	echo clean done