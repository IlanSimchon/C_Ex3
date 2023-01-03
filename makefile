flags = -g -Wall

all: isort txtfind

isort: main.o Arrays.o
	gcc $(flags) main.o Arrays.o -o isort
txtfind: Strings.o
	gcc $(flags) Strings.o -o txtfind

Arrays.o: Arrays.c Arrays.h
	gcc $(flags) -c Arrays.c -o Arrays.o
Strings.o: Strings.c Strings.h
	gcc $(flags) -c Strings.c -o Strings.o
main.o: main.c
	gcc $(flags) -c main.c -o main.o

.PHONY: all clean

clean:
		rm -f *.o isort txtfind