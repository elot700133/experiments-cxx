#include <iostream>

struct Foo
{
  int32_t  i1 : 8;
  int32_t     : 8;
};

using namespace std;

int main(int argc, const char *argv[])
{
  cout << "int sizeof " << sizeof(int32_t) << endl;
  cout << "uint sizeof " << sizeof(uint32_t) << endl;
  cout << sizeof(Foo) << endl;

  return 0;
}
