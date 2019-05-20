all: multifile.c mystuff.o
	gcc -Wall -ansi -pedantic multifile.c mystuff.o

mystuff.o: mystuff.c
	gcc -Wall -ansi -pedantic -c mystuff.c

clean:
	rm -rf *.o *~ *.exe *.out
