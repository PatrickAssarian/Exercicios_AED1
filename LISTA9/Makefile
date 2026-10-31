CC = gcc
CFLAGS = -Wall -Wextra

all: build build/main.exe

build:
	mkdir build

build/main.exe: main.o rubro_negra.o
	$(CC) $(CFLAGS) -o build/main.exe main.o rubro_negra.o

main.o: main.c rubro_negra.h
	$(CC) $(CFLAGS) -c main.c

rubro_negra.o: rubro_negra.c rubro_negra.h
	$(CC) $(CFLAGS) -c rubro_negra.c

run: all
	./build/main.exe

clean:
	rm -f *.o build/*.exe
