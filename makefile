# NOTE: this is obviously not a real makefile, I don't know anything about those yet, but this will eventually be one.
g++ main.cpp game.cpp mygame.cpp texture.cpp eps.cpp -o game_bin `sdl-config --cflags --libs` -lGL -lGLU
