#include <iostream>
#include "template-class.hpp"
#include "template-class-client.hpp"
using namespace std;

int main(int argc, const char *argv[])
{
  call_foo();
  Foo<int> foo;
  foo.func(3);
  return 0;
}
