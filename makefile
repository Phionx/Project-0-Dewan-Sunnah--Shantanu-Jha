GCC = gcc -c

compile: playlist.c nodeSong.c playlist.h nodeSong.h main.c playlist.o nodeSong.o
	$(GCC) nodeSong.c playlist.c
	gcc -o MUSIC main.c playlist.o nodeSong.o
	./MUSIC

clean:
	rm *.o
