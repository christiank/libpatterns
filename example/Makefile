.PHONY: clean

example: main.o
	$(CC) -L../ -static -o $(.TARGET) $(.ALLSRC) -lpatterns

main.o: main.c
	$(CC) -std=c11 -I../ -c -Wall -o $(.TARGET) $(.ALLSRC)

clean:
	rm -f example *.o *.core
