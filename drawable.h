#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <vector>
#include <string>

class cDrawable {
  public:
    cDrawable();
    Draw();
}

typedef vector<cDrawable*> DrawableVectorType;

class cDrawableManager {
  public:
    cDrawable* Register(string filename, );
    DrawAll();
  private:
    DrawableVectorType Drawables;
}

#endif // DRAWABLE_H
