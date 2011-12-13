#include "mygame.h"

void cMyGame::Init() {
  // mygame constructor
  tex = new cTexture("test.bmp");
  tex2 = new cTexture("test2.bmp");
}

void cMyGame::End() {
  // mygame destructor
  delete tex; tex = NULL;
  delete tex2; tex2 = NULL;
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
}

void cMyGame::Draw(float interpolation) {
  // this is called after physics happens if there's enough time

  glBindTexture( GL_TEXTURE_2D, tex->texture );

  for (int i=0; i<100; i++) {
  glBegin( GL_QUADS );
    //Bottom-left vertex (corner)
    glTexCoord2i( 0, 0 );
    glVertex3f( 100.f, 100.f, 0.0f );

    //Bottom-right vertex (corner)
    glTexCoord2i( 1, 0 );
    glVertex3f( 228.f, 100.f, 0.f );

    //Top-right vertex (corner)
    glTexCoord2i( 1, 1 );
    glVertex3f( 228.f, 228.f, 0.f );

    //Top-left vertex (corner)
    glTexCoord2i( 0, 1 );
    glVertex3f( 100.f, 228.f, 0.f );
  glEnd();
  }

  glBindTexture( GL_TEXTURE_2D, tex2->texture );

  for(int i=0;i<100;i++) {
  glBegin( GL_QUADS );
    //Bottom-left vertex (corner)
    glTexCoord2i( 0, 0 );
    glVertex3f( 100.f, 100.f, 0.0f );

    //Bottom-right vertex (corner)
    glTexCoord2i( 1, 0 );
    glVertex3f( 228.f, 100.f, 0.f );

    //Top-right vertex (corner)
    glTexCoord2i( 1, 1 );
    glVertex3f( 228.f, 228.f, 0.f );

    //Top-left vertex (corner)
    glTexCoord2i( 0, 1 );
    glVertex3f( 100.f, 228.f, 0.f );
  glEnd();
  }
}
