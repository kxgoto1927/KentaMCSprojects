#-------------
# makefile
#stack.o: stack.h stack.cpp
#	g++ $(FLAGS) -c stack.cpp
#-------------

FLAGS = -g -Wall -std=c++11

run: main.o infix.o postfix.o
	g++ $(FLAGS) -o run main.o infix.o postfix.o
main.o: main.cpp stack.h infix.h postfix.h
	g++ $(FLAGS) -c main.cpp
infix.o: infix.cpp infix.h
	g++ $(FLAGS) -c infix.cpp
postfix.o: postfix.cpp postfix.h
	g++ $(FLAGS) -c postfix.cpp
clean:
	rm -f *.o run