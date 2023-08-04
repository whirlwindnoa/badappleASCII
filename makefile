CC = cc
CFLAGS = -lncurses -lSDL2
SOURCES = ./main.c

all: badapple run clean

badapple:
	$(CC) $(SOURCES) $(CFLAGS) -o main
run:
	./main
clean:
	rm ./main