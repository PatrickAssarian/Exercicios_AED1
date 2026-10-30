CC = gcc
CFLAGS = -Wall -Wextra

all: build build/main.exe

build:
	mkdir build

build/main.exe: main.o pilha.o
	$(CC) $(CFLAGS) -o build/main.exe main.o pilha.o

main.o: main.c pilha.h
	$(CC) $(CFLAGS) -c main.c

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

run: all
	./build/main.exe

clean:
	rm -f *.o build/*.exe
