#ifndef FOO_HPP
#include <iostream>
using namespace std;
class Foo
{
  public:
int foo1(int& i)
{
  i++;
  return i;
//  cout << "foo1" << endl;
}

int foo2(int& i);
};
#endif
