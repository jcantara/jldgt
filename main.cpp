#include <stdio.h>
#include <GL/gl.h>
#include <SDL.h>

int main(int argc, char *argv[]){

  bool m_bGameIsRunning = true;
  SDL_Surface* m_pScreen;
  Uint32 m_iNextGameTick = 0;
  // fps related:
  Uint32 m_iElapsedTicks = 0;
  Uint32 m_iLastTick = 0;
  int m_iFPSTickCounter = 0;
  int m_iFPSCounter = 0;
  int m_iCurrentFPS = 0;

  printf("bllah");

  if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 ) {
    printf( "Unable to init SDL: %s\n", SDL_GetError() );
    exit(1);
  }

  //freopen( "CON", "w", stdout );
  //freopen( "CON", "w", stderr );

  atexit(SDL_Quit);

  m_pScreen = SDL_SetVideoMode(800, 400, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
  if ( !m_pScreen ) {
    printf("Unable to set video: %s\n", SDL_GetError());
    exit(1);
  }

  printf("test1");

  m_iElapsedTicks = 0;
  m_iLastTick = 0;
  m_iFPSTickCounter = 0;
  m_iFPSCounter = 0;
  m_iCurrentFPS = 0;

  while (m_bGameIsRunning) {
    //printf("asdf");
    int loops = 0;
    while( SDL_GetTicks() >= m_iNextGameTick && loops < 5) {
      SDL_Event event;
      m_iNextGameTick += 10;
      loops++;

      //printf("test");

    }
  }

  SDL_Quit();

  return 0;
}

