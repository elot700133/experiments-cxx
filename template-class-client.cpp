#include "template-class.hpp"
#include "template-class-client.hpp"

void call_foo()
{
  Foo<int> foo;
  foo.func(4);
}
