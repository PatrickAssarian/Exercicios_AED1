CC = gcc
CFLAGS = -Wall -Wextra

all: build build/main.exe

build:
	mkdir build

build/main.exe: main.o avl.o
	$(CC) $(CFLAGS) -o build/main.exe main.o avl.o

main.o: main.c avl.h
	$(CC) $(CFLAGS) -c main.c

avl.o: avl.c avl.h
	$(CC) $(CFLAGS) -c avl.c

run: all
	./build/main.exe

clean:
	rm -f *.o build/*.exe
