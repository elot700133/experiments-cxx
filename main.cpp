#include <iostream>
#include <boost/lockfree/spsc_queue.hpp>

using namespace std;

void test1()
{
  boost::lockfree::spsc_queue<int, boost::lockfree::capacity<3>> q;

  bool s = false;
  if (q.push(1))
    cout << "Pushed 1" << endl;
  if (q.push(2))
    cout << "Pushed 2" << endl;

  int tmp;
  s = q.pop(tmp);
  if(s == true) { cout << "Pop " << tmp << endl; }

  if (q.push(3))
    cout << "Pushed 3" << endl;

  s = q.pop(tmp);
  if(s == true) { cout << "Pop " << tmp << endl; }

  s = q.pop(tmp);
  if(s == true) { cout << "Pop " << tmp << endl; }
}

void test2()
{
  boost::lockfree::spsc_queue<int, boost::lockfree::capacity<3>> q;
  bool s = false;
  std::array<int, 10> arr;

  if (q.push(1))
    cout << "Pushed 1" << endl;
  if (q.push(2))
    cout << "Pushed 2" << endl;

  int size = q.pop(&arr[0]);
  cout << "Pop size " << size << endl;
  cout << "  arr[0] = " << arr[0] << endl;
  cout << "  arr[1] = " << arr[1] << endl;
}
int main(int argc, const char *argv[])
{
  test2();

  return 0;
}
