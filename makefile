all: bin

bin:  
	gcc bf.c struct.c stack.c -o bcc

profile:
	gcc -pg bf.c struct.c stack.c

clean:
	rm -f bcc

install: all
	cp -f bcc /bin/bcc

uninstall:
	rm -f /bin/bcc






