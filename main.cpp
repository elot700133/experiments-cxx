#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

int function_1(float a, double d)
{
  int i = 0;
  i++;
  return i;
}

int main(int argc, const char *argv[])
{
  int k = function_1(1,2);
  bool exit_thread_1=false, exit_thread_2=false;
  std::vector<thread> vt;
  vt.push_back(thread([&](){ int i=0;  while(!exit_thread_1){ printf("thread 1 %d\n",i); i++; std::this_thread::sleep_for(chrono::seconds(1)); } }));
  vt.push_back(thread([&](){ int i=0;  while(!exit_thread_2){ printf("thread 2 %d\n",i); i++; std::this_thread::sleep_for(chrono::seconds(1)); } }));


  this_thread::sleep_for(chrono::seconds(15));
  exit_thread_1 = true;
  exit_thread_2 = true;

  for (std::vector<thread>::iterator i = vt.begin(); i != vt.end(); ++i) {
    i->join();
  }
    
  return 0;
}
