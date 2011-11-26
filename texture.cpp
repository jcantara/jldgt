#include "texture.h"
#include <iostream>

using namespace std;

cTexture::cTexture(string Filename) {
  SDL_Surface* Texture = SDL_LoadBMP(Filename.c_str());
  if (!Texture) {
    cout << "Unable to load bitmap: " << SDL_GetError() << endl;
    exit(1);
  }
  height = Texture->h;
  width = Texture->w;

  // the sdl surface was only temporary to construct the opengl texture, free it now
  SDL_FreeSurface(Texture);
}

cTexture::~cTexture() {
  
}
