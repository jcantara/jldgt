#include "eps.h"
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif

cEps::cEps(int ct) : cur(0), m_iArray(ct,0) {};

cEps::~cEps() {};

void cEps::event() {
  cur = (cur + 1) % m_iArray.size();
  m_iArray[cur] = SDL_GetTicks();
};

float cEps::persecond() {
  if (m_iArray[cur] == 0) {
    return 0.0;
  }
  int last = (cur + 1) % m_iArray.size();
  if (m_iArray[last] == 0) {
    return 0.0;
  }
  float eps = (float)m_iArray.size() / ((float)(m_iArray[cur] - m_iArray[last]) / 1000);
  return eps;
};
