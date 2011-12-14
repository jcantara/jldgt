#include "eps.h"
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif

/*
  event-per-second recorder/reporter, for fps and physics-per-second.
  records time at each "event" and keeps a history for as many events as you initialize with.
  persecond returns the #of events / the seconds elapsed from the most recent event to the oldest event
*/

cEps::cEps(int ct) : m_iArray(ct,0), cur(0) {};

cEps::~cEps() {};

void cEps::event() {
  cur = (cur + 1) % m_iArray.size();
  m_iArray[cur] = SDL_GetTicks();
};

float cEps::persecond() {
  // if we don't have a full data set, return 0
  int last = (cur + 1) % m_iArray.size();
  if (m_iArray[cur] == 0 || m_iArray[last] == 0) {
    return 0.0;
  }
  float eps = (float)m_iArray.size() / ((float)(m_iArray[cur] - m_iArray[last]) / 1000);
  return eps;
};
