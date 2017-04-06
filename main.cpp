#include <iostream>
#include <thread>
#include <chrono>
#include <boost/lockfree/stack.hpp>

using namespace std;
boost::lockfree::stack<int, boost::lockfree::capacity<3>> q;

void push(int i)
{
  if (q.push(i))
    cout << "Done push " << i << endl;
  else
    cout << "Fail push " << i << endl;
}

void pop(int& tmp)
{
  bool s = q.pop(tmp);
  if ( s == true )
    cout << "Done pop " << tmp << endl;
  else
    cout << "Fail pop " << endl;
}

void test1()
{
  cout << "Running test1" << endl;
  push(1);
  push(2);
  push(3);
  push(4);

  int tmp;
  pop(tmp);

  push(5);

  pop(tmp);
  pop(tmp);

  pop(tmp); // should fail
}

void thread_push() {
  for( int i=0; i<10; i++ ){
    push(i);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void thread_pop() {
  for( int i=0; i<10; i++ ){
    int tmp;
    pop(tmp);
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
  }
}

void test2()
{
  std::thread t(thread_push);
  std::thread t2(thread_pop);

  t.join();
  t2.join();
}
int main(int argc, const char *argv[])
{
  //test1();
  test2();

  return 0;
}
