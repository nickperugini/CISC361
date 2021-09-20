CC=gcc

mp3: mp3.c mp3.h
        gcc mp3.c mp3.h -o mp3
run: mp3.o
        ./mp3.o
clean:
        rm -f mp3.o
        rm -f mp3
