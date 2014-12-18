CC=/usr/local/bin/gcc-4.9

blog: src/autoblogger.c
	$(CC) -o blog src/autoblogger.c

clean:
	rm -f blog
