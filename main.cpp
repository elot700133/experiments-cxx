#include <iostream>

using namespace std;

class A
{
  public:
   A(int i, int j){}
   A(int i, A a){}
};

void f(A a)
{
  cout << "in f" << endl;
}
int main(int argc, const char *argv[])
{
  f({1,2}); // does compile without explicit only
  f({1,{1,2}}); // even more fucked up

  A a = {3,{4,5}};

  return 0;
}
