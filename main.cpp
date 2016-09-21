#include <iostream>

using namespace std;

class A
{
  public:
   A(int i, int j){}
};

void f(A a)
{
  cout << "in f" << endl;
}
int main(int argc, const char *argv[])
{
  f({1,2}); // does compile without explicit only

  return 0;
}
