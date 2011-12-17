#g++ main.cpp game.cpp mygame.cpp texture.cpp eps.cpp -o game_bin `sdl-config --cflags --libs` -lGL -lGLU
CC=g++
CFLAGS=-c -Wall
LDFLAGS=`sdl-config --cflags --libs` -lGL -lGLU

all: game_bin

game_bin: main.o game.o mygame.o texture.o eps.o drawable.o
	$(CC) $(LDFLAGS) main.o game.o mygame.o texture.o eps.o -o game_bin

main.o: main.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) main.cpp

game.o: game.cpp game.h
	$(CC) $(CFLAGS) $(LDFLAGS) game.cpp

mygame.o: mygame.cpp mygame.h
	$(CC) $(CFLAGS) $(LDFLAGS) mygame.cpp

texture.o: texture.cpp texture.h
	$(CC) $(CFLAGS) $(LDFLAGS) texture.cpp

eps.o: eps.cpp eps.h
	$(CC) $(CFLAGS) $(LDFLAGS) eps.cpp

drawable.o: drawable.cpp drawable.h
	$(CC) $(CFLAGS) $(LDFLAGS) drawable.cpp

clean:
	rm *.o
	rm game_bin
