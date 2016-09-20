#include <iostream>

using namespace std;

class Parent
{
  public:
    void foo(){cout << "parent foo"<< endl;}
};

class Child: public Parent
{
  public:
    virtual void foo(){cout << "child foo" << endl;}
};
class GrandChild: public Child
{
  public:
    virtual void foo(){cout << "grand child foo" << endl;}
};
int main(int argc, const char *argv[])
{
  Child c;
  c.foo();

  GrandChild gc;
  gc.foo();


  Parent* p = &c;
  p->foo();

  p = &gc;
  p->foo();

  Child* pc = &gc;
  pc->foo();

  return 0;
}
