#-------------------------------------
# makefile
#-------------------------------------

FLAGS = -g -Wall -std=c++11

run: main.o item.o
	g++ $(FLAGS) -o run main.o item.o
	./run
main.o: main.cpp item.h
	g++ $(FLAGS) -c main.cpp
item.o: item.cpp item.h
	g++ $(FLAGS) -c item.cpp
clean:
	rm *.o run

