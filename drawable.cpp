#include "drawable.h"

#include <GL/gl.h>
#include <GL/glu.h>

cDrawable::cDrawable(cTextureManager texman, string texture_name, int subtextures_x, int subtextures_y) {
  texture = texman.Load(texture_name);
  subpixel_x = (1.0/(2*texture->width));
  subpixel_y = (1.0/(2*texture->height));
  sub_x = subtextures_x;
  sub_y = subtextures_y;
  sub_f_x = 1.0/sub_x;
  sub_f_y = 1.0/sub_y;
  cur_sub_x = 0;
  cur_sub_y = 0;
}

void cDrawable::Draw(int x, int y) {
  glBindTexture( GL_TEXTURE_2D, texture->texture );
  glBegin( GL_QUADS );
    //Bottom-left vertex (corner)
    glTexCoord2f( (cur_sub_x * sub_f_x)+subpixel_x, (cur_sub_y * sub_f_y)+subpixel_y );
    glVertex3f( x, y, 0.0f );

    //Bottom-right vertex (corner)
    glTexCoord2f( (cur_sub_x * (sub_f_x+1))-subpixel_x, (cur_sub_y * sub_f_y)+subpixel_y );
    glVertex3f( x+(texture->width/sub_x)-1, y, 0.0f );

    //Top-right vertex (corner)
    glTexCoord2f( (cur_sub_x * (sub_f_x+1))-subpixel_x, (cur_sub_y * (sub_f_y+1))-subpixel_y );
    glVertex3f( x+(texture->width/sub_x)-1, y+(texture->height/sub_y)-1, 0.0f );

    //Top-left vertex (corner)
    glTexCoord2f( (cur_sub_x * sub_f_x)+subpixel_x, (cur_sub_y * (sub_f_y+1))-subpixel_y );
    glVertex3f( x, y+(texture->height/sub_y)-1, 0.0f );
  glEnd();
}
