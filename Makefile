#MAKEFILE DU PROJET ALGO-PROG EI25 ---- PAUL CHIRON - GABRIEL CHATELAIN

main.o : main.c header.h 
	gcc -c main.c 

fonctions.o : fonctions.c header.h 
	gcc -c fonctions.c 

main : main.o fonctions.o
	gcc main.o fonctions.o -o main

