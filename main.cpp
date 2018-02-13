#include <iostream>

using namespace std;

template<class T>
struct is_optimizied
{
  static const bool value = false;
};

template<>
struct is_optimizied<int>
{
  static const bool value = true;
};

int main(int argc, const char *argv[])
{
  std::cout<<is_optimizied<int>::value<<std::endl;

  return 0;
}
