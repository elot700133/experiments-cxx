#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  uint16_t y = 0;
  char* p = (char*)(&y);
  *p = 0x01;
  *(p+1) = 0xe0;
  printf("y = %d\n", y);
  return 0;
}
