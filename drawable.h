#ifndef DRAWABLE_H
#define DRAWABLE_H

/*#include <vector>
#include <map>*/
#include <string>
#include "texture.h"

class cDrawable {
  public:
    cDrawable(cTextureManager texman, string texture_name, int subtextures_x, int subtextures_y);
    void Draw(int x, int y);
    void SetSub(int sub_x, int sub_y) {
      cur_sub_x = sub_x;
      cur_sub_y = sub_y;
    };
  private:
    float subpixel_x;
    float subpixel_y;
    float sub_f_x; // fraction of the texture for subtexture x
    float sub_f_y;
    int sub_x;
    int sub_y;
    int cur_sub_x;
    int cur_sub_y;
    cTexture* texture;
};

/*typedef vector<cDrawable*> DrawableVectorType;
typedef map<string, DrawableVectorType> DrawableTextureType;

class cDrawableManager {
  public:
    cDrawable* Register(string filename, );
    DrawAll();
  private:
    DrawableTextureType Drawables;
}*/

#endif // DRAWABLE_H
