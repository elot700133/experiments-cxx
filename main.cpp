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


int main(int argc, const char *argv[])
{
  Foo foo;
  auto bar = foo.create_bar();
  bar->print();
  //Foo::Bar* bar = foo.create_bar();
  return 0;
}
