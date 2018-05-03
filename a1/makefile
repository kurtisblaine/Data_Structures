# To build your program simply type make from the command line

main: ll.o main.cpp
	g++ -o a1.out main.cpp ll.o

ll.o: ll.h ll.cpp
	g++ -o ll.o -c ll.cpp

clean:
	rm *.o
