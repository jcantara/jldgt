#ifndef MY_GAME_H
#define MY_GAME_H

#include "game.h"

class cMyGame: public cGame {
  public:
    void Draw(float interpolation);
    void Physics();
    void Init();
    void End();
    void KeyDown(const int& iKeyEnum);
    void KeyUp(const int& iKeyEnum);
    void MouseMoved   (const int& iX,
      const int& iY,
      const int& iRelX,
      const int& iRelY);
    void MouseButtonUp (const int& iButton,
      const int& iX,
      const int& iY,
      const int& iRelX,
      const int& iRelY);
    void MouseButtonDown (const int& iButton,
      const int& iX,
      const int& iY,
      const int& iRelX,
      const int& iRelY);
  protected:
  private:
    cTexture* tex;
    cTexture* tex2;
    float size;
};

#endif // MY_GAME_H
