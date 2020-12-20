CC=gcc
CFLAGS=-Wall -I.
# DEPS=myBank.h
# SLFLAGS=-lmyBank

.PHONY: all
all: isort txtfind

mainisort.o: mainisort.c
	$(CC) $(CFLAGS) -c mainisort.c -o mainisort.o

maintxtfind.o: maintxtfind.c
	$(CC) $(CFLAGS) -c maintxtfind.c -o maintxtfind.o

libisort.a: myBank.o
	ar rcs libisort.a myBank.o

libtxtfind.a: myBank.o
	ar rcs libtxtfind.a myBank.o
	
myisorts: libisort.a

mytxtfinds: libtxtfind.a	
	
isort: main.o libisort.a
	$(CC) -o isort main.o libisort.a

txtfind: main.o libtxtfind.a
	$(CC) -o txtfind main.o libtxtfind.a

.PHONY: clean
clean:
	-rm -f isort txtfind *.o *.a *.so
