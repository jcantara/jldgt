#include "game.h"
#include <iostream>

using namespace std;

cGame::cGame() { 
  // initialize SDL video
  if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 ) {
    cout << "Unable to init SDL: " << SDL_GetError() << endl;
    exit(1);
  }

  // SDL defaults stderr and stdout to text files, reset that:
  //freopen( "CON", "w", stdout );
  //freopen( "CON", "w", stderr );

  // make sure SDL cleans up before exit
  atexit(SDL_Quit);

  // create a new window
  m_pScreen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_OPENGL);
  if ( !m_pScreen ) {
    cout << "Unable to set video: " << SDL_GetError() << endl;
    exit(1);
  }

  m_iElapsedTicks = 0;
  m_iLastTick = 0;
  m_iFPSTickCounter = 0;
  m_iFPSCounter = 0;
  m_iCurrentFPS = 0;

  // opengl 3D init:
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // This Will Clear The Background Color To Black
  glClearDepth(1.0);        // Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);       // The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);      // Enables Depth Testing
  glShadeModel(GL_SMOOTH);      // Enables Smooth Color Shading
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();       // Reset The Projection Matrix
  //gluPerspective(45.0f,(GLfloat)800/(GLfloat)400,0.1f,100.0f); // Calculate The Aspect Ratio Of The Window
  glOrtho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 0.0f, 1.0f);
  glMatrixMode(GL_MODELVIEW);
}

cGame::~cGame() { 
  //destructor
  SDL_Quit();
}

void cGame::Physicsloop() {
  int loops = 0;
  while( SDL_GetTicks() >= m_iNextGameTick && loops < MAX_FRAMESKIP) {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    { 
      // check for messages
      switch (event.type)
      {
      case SDL_QUIT:
        m_bGameIsRunning = false;
        break;
      case SDL_KEYDOWN:
        KeyDown(event.key.keysym.sym);
        break;
      case SDL_KEYUP:
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
    loops++;
    Physics(); // call this in child class
  }
  if (loops == MAX_FRAMESKIP) {
    // computer is too slow to run game
    std::cout << "computer too slow" << std::endl;
    //return 1;
  }
}

void cGame::Drawingloop() {
  // fps calculation
  m_iElapsedTicks = SDL_GetTicks() - m_iLastTick;
  m_iFPSTickCounter += m_iElapsedTicks;
  ++m_iFPSCounter;
  if (m_iFPSTickCounter >= 1000) {
    m_iCurrentFPS = m_iFPSCounter;
    m_iFPSCounter = 0;
    m_iFPSTickCounter = 0;
    cout << m_iCurrentFPS << endl;
  }
  m_iLastTick = SDL_GetTicks();

  //SDL_FillRect(m_pScreen, 0, SDL_MapRGB(m_pScreen->format, 0, 0, 0)); // black background
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear The Screen And The Depth Buffer
  glLoadIdentity();

  float interpolation = float( SDL_GetTicks() + SKIP_TICKS - m_iNextGameTick ) / float( SKIP_TICKS );
  Draw(interpolation); // call this in child class

  //SDL_Flip(m_pScreen);
  SDL_GL_SwapBuffers();
}

int cGame::Go() { 
  Init(); // child class setup

  m_iNextGameTick = SDL_GetTicks();
  m_bGameIsRunning = true;
  while( m_bGameIsRunning ) {
    Physicsloop();
    Drawingloop();
  }
  End(); // child class cleanup
  return 0;
}
