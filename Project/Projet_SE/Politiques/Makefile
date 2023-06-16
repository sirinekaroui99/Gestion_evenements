name := ""

myapp: menuAlgo.c main.c AjouterProcesseur.c FIFO.c Priority.c RoundRobin.c SJF.c SRT.c
	gcc menuAlgo.c main.c AjouterProcesseur.c FIFO.c Priority.c RoundRobin.c SJF.c SRT.c `pkg-config --cflags --libs` -o myapp
run:
	./myapp $(name) 
