CC = gcc
CFLAGS = -Wall -Wextra

all: build build/main.exe

build:
	mkdir build

build/main.exe: main.o lista.o
	$(CC) $(CFLAGS) -o build/main.exe main.o lista.o

main.o: main.c lista.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

run: all
	./build/main.exe

clean:
	rm -f *.o build/*.exe
