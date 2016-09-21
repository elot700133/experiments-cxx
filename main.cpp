#include <iostream>

using namespace std;

class Foo
{
  private:
  class Bar
  {
    public:
      void print(){ printf("cat\n"); }
  };
  public:
    Bar* create_bar(){ return new Bar(); }
};

class Foo2 : public Foo
{
  public:
    Bar* create_bar(){ return new Bar(); }
};


int main(int argc, const char *argv[])
{
  Foo foo;
  auto bar = foo.create_bar();
  bar->print();
  //Foo::Bar* bar = foo.create_bar();

  Foo2 foo2;
  foo2.create_bar(); // will not compile because Bar is private
  return 0;
}
