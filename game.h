#ifndef GAME_H
#define GAME_H
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

#include "texture.h"
#include "eps.h"

class cGame
{
  public:
    cGame();
    ~cGame();
    int Go();
    static const int TICKS_PER_SECOND = 50; // physics events per second
    static const int SKIP_TICKS = 1000 / TICKS_PER_SECOND; // calculate inverse of physics tick rate
    static const int MAX_FRAMESKIP = 5; // maximum allowed physics ticks without drawing a frame
   static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 400;
    // interface functions:
    virtual void Draw(const float interpolation) =0;
    virtual void Physics() =0;
    virtual void Init() =0;
    virtual void End() =0;
    virtual void KeyDown(const int& iKeyEnum) =0;
    virtual void KeyUp(const int& iKeyEnum) =0;
    virtual void MouseMoved (const int& iX,
      const int& iY,
      const int& iRelX,
      const int& iRelY) =0;
    virtual void MouseButtonUp (const int& iButton,
      const int& iX,
      const int& iY,
      const int& iRelX,
      const int& iRelY) =0;
    virtual void MouseButtonDown (const int& iButton,
      const int& iX,
      const int& iY,
      const int& iRelX,
      const int& iRelY) =0;
  protected:
    int Physicsloop();
    int Drawingloop();

    bool m_bGameIsRunning;
    SDL_Surface* m_pScreen;
    SDL_mutex* m_pLock;
    bool m_bKeysHeld[SDLK_LAST];

    static int StaticPhysicsloop(void* pParam) {
      return ((cGame*)pParam)->Physicsloop();
    }
  private:
    Uint32 m_iNextGameTick;

    // fps related:
    cEps m_Fps;
    cEps m_Eps;

    // texture manager:
    cTextureManager m_TextureManager;
};

#endif // GAME_H
