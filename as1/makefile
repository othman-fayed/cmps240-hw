run: main.o
	gcc -o run main.o ass1.o

main.o: main.c ass1.o
	gcc -c main.c

ass1.o: ass1.c
	gcc -c ass1.c

.PHONY: clean # solve the problem when you have a file named clean, no dependency!
clean:
	rm -rf *.o run