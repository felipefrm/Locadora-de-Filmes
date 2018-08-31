########## Makefile ############

all: main.o locadora.o
	gcc locadora.o main.o -o tp -lm

main.o: main.c locadora.h
	gcc -g -c main.c
locadora.o: locadora.h locadora.c
	gcc -g -c locadora.c -lm
