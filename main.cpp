#include <iostream>
#include <vector>
#include <memory>

using namespace std;
class Algo1;
class Algo2;
class Data
{
public:
  virtual std::shared_ptr<Data> process_with(Algo1& algo1){}
  virtual std::shared_ptr<Data> process_with(Algo2& algo2){}
};
class Algo
{
public:
  virtual ~Algo(){}
  virtual std::shared_ptr<Data> accept(std::shared_ptr<Data> data){}
};

class Algo1: public Algo
{
public:
  std::shared_ptr<Data> accept(std::shared_ptr<Data> data){
    return data->process_with(*this);
  }
};

class Algo2: public Algo
{
public:
  std::shared_ptr<Data> accept(std::shared_ptr<Data> data){
    return data->process_with(*this);
  }
};


class Data2: public Data
{
public:
  virtual std::shared_ptr<Data> process_with(Algo2& algo){
    cout << "Data2 process_with Algo2" << endl;
    return std::make_shared<Data2>();
  }
};

class Data1: public Data
{
public:
  virtual std::shared_ptr<Data> process_with(Algo1& algo1){
    cout << "Data1 process_with Algo1" << endl;
    return std::make_shared<Data2>();
  }
};

int main(int argc, const char *argv[])
{
  std::vector<std::shared_ptr<Algo>> vec{
    std::make_shared<Algo1>()
    ,std::make_shared<Algo2>()
    ,std::make_shared<Algo2>()
    ,std::make_shared<Algo2>()
  };

  std::shared_ptr<Data> data = std::make_shared<Data1>();
  for(std::vector<std::shared_ptr<Algo> >::iterator ii=vec.begin(); ii!=vec.end(); ii++)
  {
    data = (*ii)->accept(data);
  }

  return 0;
}
