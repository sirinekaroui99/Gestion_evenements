default: main

main.o: main.c 
	gcc -c main.c -o main.o

program: main.o
	gcc main -o main

run : 
	./main

clean:
	-rm -f main.o
	-rm -f main
