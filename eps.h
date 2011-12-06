#ifndef EPS_H
#define EPS_H

#include <vector>

using namespace std;

// record and report events per second
class cEps {
  public:
    cEps(int ct); //constructor with count of events to average eps over
    ~cEps(); //destructor
    void event(); // register an event happening
    float persecond(); // return the events per second value
  private:
    vector<int> m_iArray;
    int cur;
};

#endif //EPS_H
