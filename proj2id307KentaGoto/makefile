#-------------
# makefile
#-----------
FLAGS = -g -Wall -std=c++11

run: poly.o main.o
	g++ $(FLAGS) -o run poly.o main.o
poly.o: poly.h poly.cpp
	g++ -c poly.cpp
main.o: main.cpp poly.h
	g++ -c main.cpp
clean:
	rm -f *.o run