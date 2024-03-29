CC=gcc
CFLAGS=-g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -o
VALGRIND= valgrind --leak-check=full --track-origins=yes --show-reachable=yes
OBJET=pruebas
ARCH_C=main.c lista.c testing.c pruebas_alumno.c pila.c

all:valgrind
	
	echo
	notify-send "Compilado!" -t 1500

valgrind:compilar
	
	echo
	$(VALGRIND) ./$(OBJET)

compilar:
	
	echo
	$(CC) $(ARCH_C) $(CFLAGS) $(OBJET)
	
clean:

	rm $(OBJET)