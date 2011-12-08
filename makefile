#g++ main.cpp game.cpp mygame.cpp texture.cpp eps.cpp -o game_bin `sdl-config --cflags --libs` -lGL -lGLU
CC=g++
CFLAGS=-c -Wall
LDFLAGS=`sdl-config --cflags --libs` -lGL -lGLU

all: game_bin

game_bin: main.o game.o mygame.o texture.o eps.o
	$(CC) $(LDFLAGS) main.o game.o mygame.o texture.o eps.o -o game_bin

main.o: main.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) main.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) game.cpp

mygame.o: mygame.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) mygame.cpp

texture.o: texture.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) texture.cpp

eps.o: eps.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) eps.cpp
