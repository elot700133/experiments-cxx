#include <iostream>

using namespace std;

class A
{
  public:
   A(int i){}            //(1)
   A(int i, int j){}     //(2)
   A(int i, A a){}       //(3)
};

void f(A a)
{
  cout << "in f" << endl;
}
int main(int argc, const char *argv[])
{
  f(1);            // converts to A using (1)
  f({1,2});        // converts to A using (2) does compile without explicit only
  f({1,{1,2}});    // converts to A using (3)

  A a = {3,{4,5}};

  return 0;
}
