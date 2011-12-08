# NOTE: this is obviously not a real makefile, I don't know anything about those yet, but this will eventually be one.
#g++ main.cpp game.cpp mygame.cpp texture.cpp eps.cpp -o game_bin `sdl-config --cflags --libs` -lGL -lGLU
CC=g++
CFLAGS=-c `sdl-config --cflags --libs` -lGL -lGLU

all: game_bin

game_bin: main.o game.o mygame.o texture.o eps.o
	$(CC) main.o game.o mygame.o texture.o eps.o -o game_bin

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

mygame.o: mygame.cpp
	$(CC) $(CFLAGS) mygame.cpp

texture.o: texture.cpp
	$(CC) $(CFLAGS) texture.cpp

eps.o: eps.cpp
	$(CC) $(CFLAGS) eps.cpp
