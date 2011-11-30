#include <map>
#include <string>
#include <iostream>

using namespace std;

class myClass {
  public:
    void Talk() {
      cout << "hi from " << this << endl;
    }
    myClass() {
      cout << "Constructor of " << this << endl;
    }
    myClass(const myClass & mc) {
      cout << "Copy constructor to " << this << " from " << &mc << endl;
    }
    myClass & operator=(const myClass & mc) {
      cout << this << "=" << &mc << endl;
    }
    ~myClass() {
      cout << "Destructor of " << this << endl;
    }
};

typedef map<string, myClass> MyMapType;

int main(int argc, char** argv) {

  cout << "new myclass" << endl;
  myClass* mc = new myClass;
  cout << "talking" << endl;
  mc->Talk();

  MyMapType data;

  cout << "[]" << endl;
  data["test"] = *mc;

  cout << "deleting original" << endl;
  delete mc;

  cout << "calling talk from map" << endl;
  data["test"].Talk();
  cout << "END" << endl;
}
