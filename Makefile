CC=/usr/local/bin/gcc-4.9
CARGS=-O3 -g -c -ansi -Wall -pedantic
LARGS=

blog: autoblogger.o html.o
	$(CC) -o blog autoblogger.o html.o $(LARGS)

autoblogger.o: src/autoblogger.c src src/html.h
	$(CC) -o autoblogger.o src/autoblogger.c $(CARGS)

html.o: src/html.c src/html.h
	$(CC) -o html.o src/html.c $(CARGS)

clean:
	rm -f blog && rm -f *.o
