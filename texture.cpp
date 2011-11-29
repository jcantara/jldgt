/*
This file includes both the cTexture class and the cTextureManager class.
Textures can be loaded manually with the cTexture class, but if you use the cTextureManager, it handles duplicate textures efficiently
*/

#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

#include "texture.h"
#include <iostream>

using namespace std;

void cTexture::cTexture(string Filename) {
  SDL_Surface* surface = SDL_LoadBMP(Filename.c_str());
  if (!surface) {
    cout << "Unable to load bitmap: " << SDL_GetError() << endl;
    exit(1);
  }
  height = surface->h;
  width = surface->w;
  if (((width & (width - 1)) != 0) || ((height & (height - 1)) != 0)) {
    cout << "Warning: texture dimensions are not power of 2: " << Filename << endl;
    //exit(1); // may or may not be an issue, not sure if quitting needs to happen
  }

  GLenum texture_format;
  GLint numcolors;

  numcolors = surface->format->BytesPerPixel;
  if (numcolors == 4) {
    if (surface->format->Rmask == 0x000000ff) {
      texture_format = GL_RGBA;
    } else {
      texture_format = GL_BGRA;
    }
  } else if (numcolors == 3) {
    if (surface->format->Rmask == 0x000000ff) {
      texture_format = GL_RGB;
    } else {
      texture_format = GL_BGR;
    }
  } else {
    cout << "Texture is not in truecolor: " << Filename << endl;
    exit(1);
  }

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  
  // not sure if these are necessary yet
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // move our sdl surface into opengl memory
  glTexImage2D(GL_TEXTURE_2D, 0, numcolors, width, height, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels);

  // the sdl surface was only temporary to construct the opengl texture, free it now
  SDL_FreeSurface(surface);
}

void cTexture::~cTexture() {
  glDeleteTextures(1, &texture);
}

//////////////// manager:

void cTextureManager::cTextureManager() {

}

void cTextureManager::~cTextureManager() {

}

cTexture* cTextureManager::Load(string Filename) {
  if (Textures.find(Filename) != Textures.end()) {
    Texture = Textures.find(Filename)->second;
  } else {
    Texture = cTexture(Filename);
    if (!Texture)
    { 
      cout << "Unable to load texture: " << Filename << endl;
      exit(1);
    }
    Textures[Filename] = Texture;
  }
  return &Texture;
}
