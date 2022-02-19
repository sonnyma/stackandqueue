#compile and link the application
all: StkTest

#run the application
run: StkTest
	./StkTest

#link StkTest.o and Stack.o to executable StkTest
StkTest: StkTest.o Stack.o
	g++ -g -o StkTest StkTest.o Stack.o

#compile the StkTest.cpp to StkTest.o
StkTest.o: StkTest.cpp
	g++ -g -c StkTest.cpp

#compile the Stack.cpp to Stack.o
Stack.o: Stack.cpp
	g++ -g -c Stack.cpp

#remove built files
clean:
	rm -rf StkTest StkTest.o Stack.o *~