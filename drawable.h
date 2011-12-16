#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <vector>

class cDrawable {
  public:
    cDrawable();
    Draw();
}

typedef vector<cDrawable*> DrawableVectorType;

class cDrawableManager {
  public:
    cDrawable* Register(cDrawable* drawable);
    DrawAll();
  private:
    DrawableVectorType Drawables;
}

#endif // DRAWABLE_H
