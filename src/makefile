CC = gcc
CFLAGS = "-Ilib/include"
LIBS   = "-L./lib/lib"
SLIB   = "-l:libraylib.a"
all: main

main: main.c 
	$(CC) -Wall -std=c23 board.c layout.c main.c $(CFLAGS) $(LIBS) $(SLIB)   -lm -o main && main

clean:
	rm -f main
