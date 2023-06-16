app : app.c
	gcc `pkg-config --cflags gtk+-3.0` -o app app.c `pkg-config --libs gtk+-3.0`

run : 
	./app

clean:
	-rm -f main.o
	-rm -f main
