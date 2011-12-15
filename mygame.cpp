#include "mygame.h"
#include <cmath>
#include <iostream>

using namespace std;

void cMyGame::Init() {
  // mygame constructor
  tex = m_TextureManager.Load("test.bmp");
  tex2 = m_TextureManager.Load("test2.bmp");
  size = 1.0;
}

void cMyGame::End() {
  // mygame destructor
}

void cMyGame::KeyDown(const int& iKeyEnum) {
  // keyboard down
}

void cMyGame::KeyUp(const int& iKeyEnum) {
  // keyboard up
}

void cMyGame::MouseMoved (const int& iX, const int& iY, const int& iRelX, const int& iRelY) {
  // mouse has moved
}

void cMyGame::MouseButtonUp (const int& iButton, const int& iX, const int& iY, const int& iRelX, const int& iRelY) {
  // mouse button up
}

void cMyGame::MouseButtonDown (const int& iButton,const int& iX, const int& iY, const int& iRelX, const int& iRelY) {
  // mouse button down
}

void cMyGame::Physics() {
  // this is called at strict rate, shouldn't fall behind
  size = fmod(size + 0.1, 10.0);
}

void cMyGame::Draw(float interpolation) {
  // this is called after every vsync to set up drawing

  glBindTexture( GL_TEXTURE_2D, tex->texture );

  for (int i=0; i<10000; i++) {
  float x = rand() % WINDOW_WIDTH;
  float y = rand() % WINDOW_HEIGHT;
  glBegin( GL_QUADS );
    //Bottom-left vertex (corner)
    glTexCoord2i( 0, 0 );
    glVertex3f( x, y, 0.0f );

    //Bottom-right vertex (corner)
    glTexCoord2i( 1, 0 );
    glVertex3f( x+size, y, 0.f );

    //Top-right vertex (corner)
    glTexCoord2i( 1, 1 );
    glVertex3f( x+size, y+size, 0.f );

    //Top-left vertex (corner)
    glTexCoord2i( 0, 1 );
    glVertex3f( x, y+size, 0.f );
  glEnd();
  }

  glBindTexture( GL_TEXTURE_2D, tex2->texture );

  for(int i=0;i<10000;i++) {
  float x = rand() % WINDOW_WIDTH;
  float y = rand() % WINDOW_HEIGHT;
  glBegin( GL_QUADS );
    //Bottom-left vertex (corner)
    glTexCoord2i( 0, 0 );
    glVertex3f( x, y, 0.0f );

    //Bottom-right vertex (corner)
    glTexCoord2i( 1, 0 );
    glVertex3f( x+size, y, 0.f );

    //Top-right vertex (corner)
    glTexCoord2i( 1, 1 );
    glVertex3f( x+size, y+size, 0.f );

    //Top-left vertex (corner)
    glTexCoord2i( 0, 1 );
    glVertex3f( x, y+size, 0.f );
  glEnd();
  }
}
