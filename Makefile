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

libisort.a: myisort.o
	ar rcs libisort.a myisort.o

libtxtfind.a: myfind.o
	ar rcs libtxtfind.a myfind.o
	
myisorts: libisort.a

mytxtfinds: libtxtfind.a	
	
isort: mainisort.o libisort.a
	$(CC) -o isort mainisort.o libisort.a

txtfind: maintxtfind.o libtxtfind.a
	$(CC) -o txtfind maintxtfind.o libtxtfind.a

.PHONY: clean
clean:
	-rm -f isort txtfind *.o *.a *.so
