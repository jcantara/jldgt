#include <map>
#include <string>
#include <iostream>

using namespace std;

class myClass {
  public:
    void Talk();
};

void myClass::Talk() {
  cout << "hi" << endl;
}

typedef map<string, myClass> MyMapType;

int main(int argc, char** argv) {

  myClass* mc = new myClass;
  mc->Talk();

  MyMapType data;

  data["test"] = *mc;

}
