CC = gcc
CFLAGS = -Wall

all: programa

programa: main.o personagem.o
	$(CC) $(CFLAGS) -o programa main.o personagem.o

main.o: main.c personagem.h
	$(CC) $(CFLAGS) -c main.c

personagem.o: personagem.c personagem.h
	$(CC) $(CFLAGS) -c personagem.c

clean:
	rm -f *.o programa      