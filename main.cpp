#include "mygame.h"

int main ( int argc, char** argv )
{
  cMyGame *game = new cMyGame;
  return game->Go();
}
