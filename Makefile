thing.o: thing.cpp thing.h
	g++ -c thing.cpp

compience: main.cpp thing.o
	g++ -o compience main.cpp thing.o
