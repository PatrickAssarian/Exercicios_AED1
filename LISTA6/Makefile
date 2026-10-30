CC = gcc
CFLAGS = -Wall -Wextra

all: build build/main.exe

build:
	mkdir build

build/main.exe: main.o fila.o
	$(CC) $(CFLAGS) -o build/main.exe main.o fila.o

main.o: main.c fila.h
	$(CC) $(CFLAGS) -c main.c

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

run: all
	./build/main.exe

clean:
	rm -f *.o build/*.exe
