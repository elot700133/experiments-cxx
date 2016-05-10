#include <iostream>
#include <memory>
class CustomDtor
{
public:
  CustomDtor(){}
  //CustomDtor(CustomDtor&){ printf("copy ctor\n"); }
  //CustomDtor(CustomDtor&) = default;
  //CustomDtor(CustomDtor&) = delete;
  //CustomDtor(CustomDtor&&) = default;
  //CustomDtor& operator=(CustomDtor&) = delete;
  //CustomDtor& operator=(CustomDtor&&) = default;
  virtual ~CustomDtor(){ printf("abc"); }

void print(){ printf("foo\n"); }
private:
  /* data */
};




using namespace std;

int main(int argc, const char *argv[])
{
 // CustomDtor cd;
 // CustomDtor v1 = cd;
    
  
  auto p = make_shared<CustomDtor>();
  CustomDtor v1;
  CustomDtor r(std::move(v1));
  p->print();
  r.print();
  
  return 0;
}
