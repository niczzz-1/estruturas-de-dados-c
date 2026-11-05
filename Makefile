# -*- Makefile -*-

#target: dependencies 
#	action
CC = gcc

CFLAGS = -Wall -Wextra -g -Isrc

.PHONY: all test clean 

all: test

test: src/lista.c src/pilha.c src/fila.c tests/main.c
	$(CC) $(CFLAGS) -o teste $^ 

clean:
	rm -f *.o teste teste.exe