all: isort txtfind

isort: isort.o
	gcc -Wall -g -o isort isort.o

isort.o: isort.c
	gcc -Wall -g -c isort.c

txtfind: txtfind.o
	gcc -Wall -g -o txtfind txtfind.o

txtfind.o: txtfind.c
	gcc -Wall -g -c txtfind.c

clean:
	rm -f *.o
