#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
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

  //printf("bllah");

  if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 ) {
    printf( "Unable to init SDL: %s\n", SDL_GetError() );
    exit(1);
  }

  //freopen( "CON", "w", stdout );
  //freopen( "CON", "w", stderr );

  atexit(SDL_Quit);

  m_pScreen = SDL_SetVideoMode(800, 400, 16, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_OPENGL);
  if ( !m_pScreen ) {
    printf("Unable to set video: %s\n", SDL_GetError());
    exit(1);
  }

  //printf("test1");

  m_iElapsedTicks = 0;
  m_iLastTick = 0;
  m_iFPSTickCounter = 0;
  m_iFPSCounter = 0;
  m_iCurrentFPS = 0;

/* rotation angle for the triangle. */
float rtri = 0.0f;

/* rotation angle for the quadrilateral. */
float rquad = 0.0f;

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   // This Will Clear The Background Color To Black
  glClearDepth(1.0);        // Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);       // The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);      // Enables Depth Testing
  glShadeModel(GL_SMOOTH);      // Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();       // Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)800/(GLfloat)400,0.1f,100.0f); // Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);

  m_iNextGameTick = SDL_GetTicks();

  while (m_bGameIsRunning) {
    //printf("asdf");
    int loops = 0;
    while( SDL_GetTicks() >= m_iNextGameTick && loops < 5) {
      SDL_Event event;

      while (SDL_PollEvent(&event))
      {
        // check for messages
        switch (event.type)
        {
        case SDL_QUIT:
          m_bGameIsRunning = false;
          break;
        }
      }

      m_iNextGameTick += 10;
      loops++;

      //printf("test");

    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear The Screen And The Depth Buffer
  glLoadIdentity();       // Reset The View

  glTranslatef(-1.5f,0.0f,-6.0f);   // Move Left 1.5 Units And Into The Screen 6.0

  glRotatef(rtri,0.0f,1.0f,0.0f);   // Rotate The Triangle On The Y axis 
  // draw a triangle (in smooth coloring mode)
  glBegin(GL_POLYGON);        // start drawing a polygon
  glColor3f(1.0f,0.0f,0.0f);      // Set The Color To Red
  glVertex3f( 0.0f, 1.0f, 0.0f);    // Top
  glColor3f(0.0f,1.0f,0.0f);      // Set The Color To Green
  glVertex3f( 1.0f,-1.0f, 0.0f);    // Bottom Right
  glColor3f(0.0f,0.0f,1.0f);      // Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, 0.0f);    // Bottom Left  
  glEnd();          // we're done with the polygon (smooth color interpolation)

  glLoadIdentity();       // make sure we're no longer rotated.
  glTranslatef(1.5f,0.0f,-6.0f);    // Move Right 3 Units, and back into the screen 6.0

  glRotatef(rquad,1.0f,0.0f,0.0f);    // Rotate The Quad On The X axis 
  // draw a square (quadrilateral)
  glColor3f(0.5f,0.5f,1.0f);      // set color to a blue shade.
  glBegin(GL_QUADS);        // start drawing a polygon (4 sided)
  glVertex3f(-1.0f, 1.0f, 0.0f);    // Top Left
  glVertex3f( 1.0f, 1.0f, 0.0f);    // Top Right
  glVertex3f( 1.0f,-1.0f, 0.0f);    // Bottom Right
  glVertex3f(-1.0f,-1.0f, 0.0f);    // Bottom Left  
  glEnd();          // done with the polygon

  rtri+=3.0f;          // Increase The Rotation Variable For The Triangle
  rquad-=4.1f;         // Decrease The Rotation Variable For The Quad 
  SDL_GL_SwapBuffers();
  }

  SDL_Quit();

  return 0;
}

