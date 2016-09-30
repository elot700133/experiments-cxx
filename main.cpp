#include <iostream>
#include <vector>

using namespace std;
class Counter
{
  public:
    Counter(){ ctor_++; }
    ~Counter(){ ctor_++; }
    Counter(const Counter&){ cctor_++; }
    Counter& operator=(Counter&){ copy_assign_++; }
    Counter(Counter&&){ mtor_++; }
    Counter& operator=(Counter&&){ move_assign_++; }
    static int ctor_;
    static int cctor_;
    static int mtor_;
    static int copy_assign_;
    static int move_assign_;
    static void print(){
      cout << "ctor_ " << ctor_ << endl;
      cout << "cctor_ " << cctor_ << endl;
      cout << "mtor_ " << mtor_ << endl;
      cout << "copy_assign_ " << copy_assign_ << endl;
      cout << "move_assign_ " << move_assign_ << endl;
    }
    static void clear(){
    ctor_ = 0;
    cctor_ = 0;
    mtor_ = 0;
    copy_assign_ = 0;
    move_assign_ = 0;
    }
};
int Counter::ctor_ = 0;
int Counter::cctor_ = 0;
int Counter::mtor_ = 0;
int Counter::copy_assign_ = 0;
int Counter::move_assign_ = 0;

// Comment out move assign then run
void return_temporary_variable()
{
  Counter::clear();
  printf("%s\n", __func__);
  auto f = [](){ return Counter(); };
  Counter c = f();
  Counter::print();
}

void return_local_variable()
{
  Counter::clear();
  printf("%s\n", __func__);
  auto f = [](){ Counter c; return c; };
  Counter c = f();
  Counter::print();
}

void vector_of_c()
{
  Counter::clear();
  printf("%s\n", __func__);
  auto f = [](){ std::vector<Counter> v; v.push_back(Counter()); return v; };
  auto v = f();
  Counter::print();
}

int main(int argc, const char *argv[])
{
  return_temporary_variable();
  return_local_variable();
  vector_of_c();


  return 0;
}
