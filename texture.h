#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>
#include <GL/glu.h>

#include <string>
#include <map>

using namespace std;

class cTexture {
  public:
    cTexture(string filename);
    ~cTexture();
    int height;
    int width;
    GLuint texture;
};

typedef map<string, cTexture> TextureMapType;

class cTextureManager {
  public:
    cTextureManager();
    ~cTextureManager();
    cTexture* Load(string filename); // pointer to our texture. Won't duplicate textures of same filename, will return pointer to the same one
  private:
    static TextureMapType Textures;
};

#endif // TEXTURE_H
