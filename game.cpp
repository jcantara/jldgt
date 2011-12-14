#include "game.h"
#include <iostream>
#include "SDL_thread.h"
#include "SDL_mutex.h"

using namespace std;

cGame::cGame() : m_Fps(50), m_Eps(50), m_TextureManager() {
  // initialize SDL video
  if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 ) {
    cout << "Unable to init SDL: " << SDL_GetError() << endl;
    exit(1);
  }

  m_bGameIsRunning = true;

  // make sure SDL cleans up before exit
  atexit(SDL_Quit);

  SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);
  SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
  // create a new window
  m_pScreen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 0, SDL_OPENGL);
  if ( !m_pScreen ) {
    cout << "Unable to set video: " << SDL_GetError() << endl;
    exit(1);
  }

  // opengl init:
  glEnable(GL_TEXTURE_2D);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // This Will Clear The Background Color To Black
  glClearDepth(1.0);        // Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);       // The Type Of Depth Test To Do
  glDisable(GL_DEPTH_TEST); // disable depth test to enable blend below
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glShadeModel(GL_SMOOTH);      // Enables Smooth Color Shading
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();       // Reset The Projection Matrix
  glOrtho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 0.0f, 1.0f);
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

cGame::~cGame() {
  //destructor
  SDL_Quit();
}

int cGame::Physicsloop() {
  SDL_Event event;
  int oloop = 0;
  while( m_bGameIsRunning ) {
    int loops = 0;
    while( SDL_GetTicks() >= m_iNextGameTick && loops < MAX_FRAMESKIP) {
      SDL_mutexP(m_pLock);
      while (SDL_PollEvent(&event))
      {
        // check for messages
        switch (event.type)
        {
        case SDL_QUIT:
          m_bGameIsRunning = false;
          break;
        case SDL_KEYDOWN:
          m_bKeysHeld[event.key.keysym.sym] = true;
          KeyDown(event.key.keysym.sym);
          break;
        case SDL_KEYUP:
          m_bKeysHeld[event.key.keysym.sym] = false;
          KeyUp(event.key.keysym.sym);
          break;
        case SDL_MOUSEMOTION:
          //std::cout << (int)event.button.button << std::endl;
          MouseMoved(
            event.motion.x,
            event.motion.y,
            event.motion.xrel,
            event.motion.yrel);
          break;
        case SDL_MOUSEBUTTONUP:
          //std::cout << (int)event.button.button << std::endl;
          MouseButtonUp(
            event.button.button,
            event.motion.x,
            event.motion.y,
            event.motion.xrel,
            event.motion.yrel);
          break;
        case SDL_MOUSEBUTTONDOWN:
          //std::cout << (int)event.button.button << std::endl;
          MouseButtonDown(
            event.button.button,
            event.motion.x,
            event.motion.y,
            event.motion.xrel,
            event.motion.yrel);
          break;
        }
      }

      m_iNextGameTick += SKIP_TICKS;
      oloop++;
      loops++;
      m_Eps.event();
      Physics(); // call this in child class
      SDL_mutexV(m_pLock);
      if (oloop % 1000 == 0) {
        cout << "P: " << m_Eps.persecond() << endl;
      }
    }
    if (loops == MAX_FRAMESKIP) {
      // computer is too slow to run game
      std::cout << "computer too slow" << std::endl;
    }
    SDL_Delay(10);
  }
  return 0;
}

int cGame::Drawingloop() {
  int loops = 0;
  while(m_bGameIsRunning) {
    m_Fps.event();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear The Screen And The Depth Buffer
    glLoadIdentity();

    SDL_mutexP(m_pLock);
    float interpolation = float( SDL_GetTicks() + SKIP_TICKS - m_iNextGameTick ) / float( SKIP_TICKS );
    Draw(interpolation); // call this in child class
    SDL_mutexV(m_pLock);

    SDL_GL_SwapBuffers();
    loops++;
    if (loops % 100 == 0) {
      cout << "D: " << m_Fps.persecond() << endl;
    }
  }
  return 0;
}

int cGame::Go() {
  cout << "Starting Init" << endl;
  SDL_Thread *physics_thread;

  m_pLock = SDL_CreateMutex();
  Init(); // child class setup
  cout << "Init Done" << endl;

  m_iNextGameTick = SDL_GetTicks();
  physics_thread = SDL_CreateThread(StaticPhysicsloop, this);
  Drawingloop(); // this will run until game ends

  End(); // child class cleanup
  return 0;
}
