#include <iostream>
template <class T>
class Foo
{
  public:
    void func(T t);
};

template<class T>
void Foo<T>::func(T t){ std::cout << t << std::endl; }
