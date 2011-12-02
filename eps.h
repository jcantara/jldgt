#ifndef EPS_H
#define EPS_H

// record and report events per second
class cEps {
  public:
    cEps(int count); //constructor with count of events to average eps over
    ~cEps(); //destructor
    event(); // register an event happening
    float persecond(); // return the events per second value
  private:
    int * m_iArray;
    int ct;
    int cur = 0;
}

#endif //EPS_H
