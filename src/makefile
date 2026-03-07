CC = gcc
CFLAGS = "-I./lib/include" 
LIBS   = "-L./lib/lib" 
SLIB   = "-l:libraylib.a"
all: main

main: main.c
	$(CC) -Wall main.c $(CFLAGS) $(LIBS) $(SLIB) -lm -o main && main

clean:
	rm -f main
