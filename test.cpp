#ifndef GAME_H
#define GAME_H
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

//g++ test.cpp -o test_bin `sdl-config --cflags --libs` -lGL -lGLU

using namespace std;

int main ( int argc, char** argv ) {

  // initialize sdl video and timers
  if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 ) {
    cout << "Unable to init SDL: " << SDL_GetError() << endl;
    exit(1);
  }

  int width = 320;
  int height = 200;

  // set up our exit cleanup
  atexit(SDL_Quit);

  // configure sdl gl settings
  SDL_GL_SetAttribute( SDL_GL_SWAP_CONTROL, 1);
  SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 1 );
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
  // create a new window
  //const SDL_VideoInfo* info = SDL_GetVideoInfo();
  SDL_Surface* m_pScreen = SDL_SetVideoMode(width, height, 0, SDL_OPENGL);
  if ( !m_pScreen ) {
    cout << "Unable to set video: " << SDL_GetError() << endl;
    exit(1);
  }

  // opengl init:
  //glEnable(GL_TEXTURE_2D);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // This Will Clear The Background Color To Black
  //glClearDepth(1.0);        // Enables Clearing Of The Depth Buffer
  //glDepthFunc(GL_LESS);       // The Type Of Depth Test To Do
  glDisable(GL_DEPTH_TEST); // disable depth test to enable blend below
  //glEnable(GL_BLEND);
  //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  //glShadeModel(GL_SMOOTH);      // Enables Smooth Color Shading
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();       // Reset The Projection Matrix
  glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);

  bool run = true;
  int loops = 0;
  int last_tick = 0;

  SDL_Event event;
  while (run) {
    // could draw stuff here, but just draw nothing, this "should" be fast
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
    for(int i=0; i<100; i++) {
      glColor4f( 1.0, 1.0, 1.0, 1.0 );
      glVertex3f( 0, 0, 0 );
      glVertex3f( 200, 0, 0 );
      glVertex3f( 200, 200, 0 );
      glVertex3f( 0, 200, 0 );
    }
    glEnd();

    // check for quit events to exit the loop
    while (SDL_PollEvent(&event))
    {
      // check for messages
      switch (event.type)
      {
      case SDL_QUIT:
        run = false;
        break;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          run = false;
        }
        break;
      }
    }


    SDL_GL_SwapBuffers();

    // output some debug info
    if (loops % 100 == 0) {
      cout << (100.0 / (SDL_GetTicks() - last_tick))*1000 << endl;
      last_tick = SDL_GetTicks();
    }
    loops++;
  }

}

#endif
