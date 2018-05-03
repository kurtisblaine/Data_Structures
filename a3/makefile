main: pqueue.o main.cpp
	g++ -o a3.out main.cpp pqueue.o

pqueue.o: pqueue.h pqueue.cpp
	g++ -o pqueue.o -c pqueue.cpp

clean:
	rm *.o
