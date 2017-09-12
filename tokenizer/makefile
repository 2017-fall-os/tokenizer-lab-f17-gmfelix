
all: test
test: mytoc.o test.o
	cc -o test test.o mytoc.o

clean:
	rm -f *.o *.exe

mytoc:  mytoc.o
	cc -o mytoc mytoc.o

run: all
	./test
