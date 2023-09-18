CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic
# CFLAGS = -std=c99

run: main.o
	$(CC) $(CFLAGS) -o run main.o ass1.o

main.o: main.c ass1.o
	$(CC) $(CFLAGS) -c main.c

ass1.o: ass1.c
	$(CC) $(CFLAGS) -c ass1.c

.PHONY: clean # solve the problem when you have a file named clean, no dependency!
clean:
	rm -rf *.o run