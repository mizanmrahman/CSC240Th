#include<iostream>
#include<string>

using namespace std;

class Animal {
  protected:
    string n;

  public:
    Animal(string s="NoName") {n=s;}   // Default value = "NoName"

    // Pure virtual method - must be overridden by any non-abstract
    //  derrived class.
    virtual void speak() = 0;

    // Virtual method - can be overridden by the child class.  The type of
    // the *object* being pointed to determines the method that gets called.
    virtual void move() { cout << "ANIMAL: I'm Moving!" << endl; }

    // Non-virtual method - can be overridden by the child class.  The 
    // type of the *pointer* determines the method that gets called.
    void eat() { cout << "ANIMAL: I'm hungry!" << endl; }
};

class Dog : public Animal {
  public:
    Dog(string s="Dog") : Animal(s) {}

    void speak() { cout << n << ": Woof!" << endl; }
    void move() { cout << n << ": Run around!" << endl; }
    void fetch() { cout << n << ": Ball! Ball!" << endl; }
};

class Cat : public Animal {
  public:
    Cat(string s="Cat") : Animal(s) {}

    void speak() { cout << n << ": Meow!" << endl; }
};

int main() {
  //Animal a;   // Cannot instantiate an Animal
  //Animal * aptr;
  Dog d("Rover");
  Dog * dptr;
  Dog &dogRef = d;
  Cat c("Whiskers");
  Cat *cptr;
  Cat &catRef = c;
 
  Animal *danimal, *canimal;

  /* Cannon instantiate an abstract class
  cout << endl << "Animal object: " << endl;
  a.speak();
  a.move();
  a.eat();

  cout << endl << "Animal pointer to an Animal object: " << endl;
  aptr = new Animal("Anotherone");
  aptr->speak();
  aptr->move();
  aptr->eat();
  */

  cout << endl << "Dog object: " << endl;
  d.speak();
  d.move();
  d.fetch();
  d.eat();

  cout << endl << "Dog pointer to a Dog object: " << endl;
  dptr = new Dog("Fluffy");
  dptr->speak();
  dptr->move();
  dptr->fetch();
  dptr->eat();

  cout << endl << "Dog reference to a Dog object: " << endl;
  dogRef.speak();
  dogRef.move();
  dogRef.fetch();
  dogRef.eat();

  cout << endl << "Animal pointer to a Dog object: " << endl;
  danimal = &d;
  danimal->speak();
  danimal->move();
  //danimal->fetch();  // Animals do not know how to fetch
  danimal->eat();

  cout << endl << "Cat object: " << endl;
  c.speak();
  c.move();
  c.eat();

  cout << endl << "Cat pointer to a Cat object: " << endl;
  cptr = new Cat("Garfield");
  cptr->speak();
  cptr->move();
  cptr->eat();

  cout << endl << "Cat reference to a Cat object: " << endl;
  catRef.speak();
  catRef.move();
  catRef.eat();

  cout << endl << "Animal pointer to a Cat object: " << endl;
  canimal = &c;
  canimal->speak();
  canimal->move();
  canimal->eat();

  cout << endl << "Animal reference to a cat object: " << endl; 
  Animal & animalRef = c;
  animalRef.speak();
  animalRef.move();
  animalRef.eat();
  
  return 0;
}
