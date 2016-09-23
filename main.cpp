#include <iostream>
#include "foo.hpp"
using namespace std;

int main(int argc, const char *argv[])
{
  Foo f;
  int i=0;
  cin >> i;
  cout << f.foo1(i);
  cout << f.foo2(i);
  return 0;
}
