#include <iostream>
#include <thread>
#include <math.h>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
  std::vector<thread> vt;
  for (int i=0; i<24; i++)
  {
    vt.push_back( 
        move(
          thread( 
            [](){
              while(1){ sqrt(4); }
              } 
              )) 
        );
  }

  for (int i=0; i<24; i++)
  {
    vt[i].join();
  }

  
  return 0;
}
