#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "game.h"

using namespace std;

class cTexture {
  public:
    cTexture(string filename);
    ~cTexture();
    int height;
    int width;
};

#endif // TEXTURE_H
