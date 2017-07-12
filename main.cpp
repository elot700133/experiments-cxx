#include <iostream>
#include <cstring>

using namespace std;
extern "C"
{
  typedef union Foo
  {
    unsigned int u;
    struct Bits
    {
      unsigned int b1 :1;
      unsigned int b2 :2;
    }bits;
  } Foo;
}


int main(int argc, const char *argv[])
{
  Foo foo;
  memset(&foo, 0, sizeof(foo));
  foo.bits.b2 = 1;
  printf("foo = 0x%02x\n", foo.u);

  return 0;
}
