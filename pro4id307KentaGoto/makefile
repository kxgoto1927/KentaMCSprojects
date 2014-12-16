#------------------------
# makefile for hashchain
#------------------------

CFLAGS = -g -Wall -ansi -pedantic -std=c89
OBJS = main.o hashchain.o hashfuncs.o randwords.o

run: $(OBJS)
	gcc $(CFLAGS) -o run $(OBJS) -lm
main.o: main.c hashchain.h
	gcc $(CFLAGS) -c -o main.o main.c
hashchain.o: hashchain.c hashchain.h
	gcc $(CFLAGS) -c -o hashchain.o hashchain.c
hashfuncs.o: hashfuncs.c hashchain.h
	gcc $(CFLAGS) -c -o hashfuncs.o hashfuncs.c
randwords.o: randwords.c
	gcc $(CFLAGS) -c -o randwords.o randwords.c
clean:
	rm -f run bugs randwords.txt $(OBJS)
