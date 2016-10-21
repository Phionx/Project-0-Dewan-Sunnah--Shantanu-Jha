GCC = gcc -g

all: nodeSong.o playlist.o main.o
	$(GCC) playlist.o main.o nodeSong.o -o MUSIC

nodeSong.o: nodeSong.c nodeSong.h
	$(GCC) -c nodeSong.c

playlist.o: playlist.c playlist.h
	$(GCC) -c main.c

clean:
	rm *.o
	rm *~

run: all
	./MUSIC
