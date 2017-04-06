#include <iostream>
#include <boost/lockfree/spsc_queue.hpp>

using namespace std;

template<class T>
void push(int i, T& q)
{
  if (q.push(i))
    cout << "Done push " << i << endl;
  else
    cout << "Fail push " << i << endl;
}

template<class T>
void pop(int& tmp, T& q)
{
  bool s = q.pop(tmp);
  if ( s == true )
    cout << "Done pop, value is " << tmp << endl;
  else
    cout << "Fail pop " << endl;
}

void test1()
{
  cout << "=============" << endl;
  cout << "Running test1" << endl;
  cout << "=============" << endl;
  boost::lockfree::spsc_queue<int, boost::lockfree::capacity<2>> q;
  push(1, q);
  push(2, q);

  int tmp;
  pop(tmp, q);

  push(3, q);

  pop(tmp, q);
  pop(tmp, q);
}
// test 1 result
// Running test1
// Done push 1
// Fail push 2             <-------------- notice here it should be successful because capacity is 2
// Done pop, value is 1
// Done push 3
// Done pop, value is 3
// Fail pop

void test2()
{
  cout << "=============" << endl;
  cout << "Running test2" << endl;
  cout << "=============" << endl;
  boost::lockfree::spsc_queue<int, boost::lockfree::capacity<1>> q;
  push(1, q);
}
//Running test2
//Fail push 1

int main(int argc, const char *argv[])
{
  test1();
  test2();

  return 0;
}

