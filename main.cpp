#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;


std::mutex my_mutex;

void print_star()
{
  unique_lock<mutex> lck(my_mutex, defer_lock);
  if ( lck.try_lock() )
    cout << "*\n";
  else
    cout << "x\n";
}

void print_x()
{
  unique_lock<mutex> lck(my_mutex, defer_lock);
  lck.lock();
  cout << "x";
  lck.unlock();
}


int main(int argc, const char *argv[])
{
  vector<thread> thread_pool;
  for( unsigned int i; i<500; i++ ){
      thread_pool.emplace_back(print_star);
  }


  for( auto&& t : thread_pool )
    t.join();

  cout << endl;
  return 0;
}
