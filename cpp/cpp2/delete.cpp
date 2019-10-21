#include <iostream>

using namespace std;

class myDeleteClass {
  private:
    int *a;
    int *b;

  public:
  // Constructor
  myDeleteClass() {
    static int counter = 1;

    a = new int;
    *a = counter * 5;
    b = new int[*a];
    for (int ii=0;ii<*a;ii++) {
      b[ii] = ii;
    }
    counter ++;
  }

  // How would you write a copy constructor for myDeleteClass?

  // Destructor
  ~myDeleteClass() {
    delete a;
    a = nullptr;
    delete[] b;    // b points to an array, use delete[]
    b = nullptr;
  }

  void print() {
    cout << "  object " << *a << ": " ;
    for(int ii=0;ii<*a;ii++) {
      cout << b[ii] << "  "; 
    }
    cout << endl;
  }
};


int main() {
  myDeleteClass c1;            // value semantics
  myDeleteClass * c2;
  c2 = new myDeleteClass();    // reference semantics

  cout << "C1:" << endl;
  c1.print();
  cout << endl << "C2:" << endl;
  c2->print();
  return 0;
}
