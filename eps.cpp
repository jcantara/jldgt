#include "eps.h"
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif

cEps::cEps(int count) {
  ct = count;
  m_iArray = new *int[ct]
}

cEps::~cEps {
  delete [] m_iArray;
  m_iArray = NULL;
}

cEps::event() {
  m_iArray[cur] = SDL_GetTicks();
  cur = (cur + 1) % ct;
}

float cEps::persecond() {
  if (m_iArray[cur] == 0) {
    return 0.0
  }
  int last = (cur + 1) % ct;
  if (m_iArray[last] == 0) {
    return 0.0
  }
  float eps = (float)(m_iArray[cur] - m_iArray[last]) / (float)ct;
}
