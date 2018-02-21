#Makefile
CC=gcc
CFLAGS = -g -Wall -O2 
OUT_EXE = Pendu

#Generate optimized code on a Linux machine. 
#	gcc -O main.c -o generateurNbAleatoire 
#To compile with more error checking using the -Wall tag:
#	gcc -Wall -o generateurNbAleatoire main.c
#Generate symbolic information for gdb
#	gcc -g main.c -o generateurNbAleatoire
#Compilation de base
#	gcc -o generateurNbAleatoire main.c
#Name of the target
#	@
#Name of the dependencies
#	^
#Name of the first dependency
#       <
# -lm is for maths library

all: main
main: fichier.o fonctions.o main.c
	$(CC) $(CFLAGS) $^ -o $(OUT_EXE) #-lm

fonctions.o: fonctions.c fonctions.h 
	$(CC) $(CFLAGS) -c $< -o $@

fichier.o: fichier.c fichier.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -vf *.o $(OUT_EXE)

rebuild: clean main
