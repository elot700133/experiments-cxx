#include <iostream>
#include <array>
using namespace std;

array<int,64> buffer;

int main(int argc, const char *argv[])
{
  char* c = reinterpret_cast<char*>(&buffer[0]);
  for(unsigned int i=0; i < 64; i++)
  {
    printf("%02X", *(c+i));
      if ( (i+1) % 8 == 0 )
        printf("\n");
      else
        printf(" ");
  }
  return 0;
}
