#include <iostream>
#include <boost/lockfree/spsc_queue.hpp>

using namespace std;
boost::lockfree::spsc_queue<int, boost::lockfree::capacity<10>> q;

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
template<unsigned long N>
void pop(std::array<int, N>& arr)
{
  int size = q.pop(&arr[0]);
  if (size > 0)
  {
    for (unsigned int i=0; i<N; i++)
    {
      cout << "Done pop: size " << size << " arr[" << i << "] = " << arr[i] << endl;
    }
  }
  else
  {
    cout << "Fail pop: nothing to pop" << endl;
  }
}

void test1()
{
  cout << "Running test1" << endl;
  push(1);
  push(2);

  int tmp;
  pop(tmp);

  push(3);

  pop(tmp);
  pop(tmp);
}
void test2()
{
  cout << "Running test2" << endl;
  std::array<int, 10> arr;

  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  push(7);
  push(8);
  push(9);
  push(10); // cannot pushed even though the queue size is set to 10
  push(11);
  push(12);
  pop(arr);

  push(13); // push return true (bug)
  push(14);
  pop(arr); // popped array showed 14, 2, 3, ...  // missing 13

  push(15);
  push(16);
  pop(arr);

  push(17);
  push(18);
  pop(arr);

  push(19);
  push(20);
  pop(arr);
}
int main(int argc, const char *argv[])
{
  //test1();
  test2();

  return 0;
}
