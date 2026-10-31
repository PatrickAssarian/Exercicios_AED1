CC = gcc
CFLAGS = -Wall -Wextra

all: build build/main.exe

build:
	mkdir build

build/main.exe: main.o arvore.o
	$(CC) $(CFLAGS) -o build/main.exe main.o arvore.o

main.o: main.c arvore.h
	$(CC) $(CFLAGS) -c main.c

arvore.o: arvore.c arvore.h
	$(CC) $(CFLAGS) -c arvore.c

run: all
	./build/main.exe

clean:
	rm -f *.o build/*.exe
