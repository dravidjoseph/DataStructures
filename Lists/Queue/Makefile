Queue: main.o PreconditionViolationException.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o -o Queue
	
main.o: main.cpp Queue.h Queue.hpp SingleNode.h SingleNode.hpp PreconditionViolationException.h
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp
	
clean:
	rm *.o Queue
	echo clean done