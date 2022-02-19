
all:	x

x:	Queue.o main.o
	g++ -g -o x Queue.o main.o

Queue.o:	Queue.cpp Queue.h
	g++ -g -c Queue.cpp

main.o:	main.cpp Queue.h
	g++ -g -c main.cpp

clean:	
	rm -f x *.o

