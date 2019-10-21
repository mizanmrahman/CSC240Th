#include<iostream>

using namespace std;

class MyBase {
  public:
    MyBase() { cout << "  MYBASE Constructor" << endl; }
    virtual ~MyBase() { cout << "  MYBASE Destructor" << endl; }
};

class MyClass : public MyBase {
  private:
    int * a;
  public:
    MyClass(int x=0) {
      a = new int;
      *a = x;
      cout << "  MYCLASS Constructor: " << *a << endl;
    }

    ~MyClass() {
      cout << "  MYCLASS Destructor: " << *a << endl;
      delete a;
      a=nullptr;
    }
};

int main () {
  cout << "MAIN: start" << endl;
  cout << "MAIN: declare c1 (MyClass) - start" << endl;
  MyClass c1(1);
  cout << "MAIN: declare c1 (MyClass) - end" << endl;

  cout << "MAIN: declare c2 (MyBase *) - start" << endl;
  MyBase * c2 = new MyClass(2);
  cout << "MAIN: declare c2 (MyBase *) - end" << endl;

  cout << "MAIN: delete c2 (MyBase * to MyClass) - start" << endl;
  delete(c2);
  cout << "MAIN: delete c2 (MyBase * to MyClass) - end" << endl;
  
  cout << "MAIN: end" << endl;
  return 0;
}
