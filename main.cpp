#include <iostream>

using namespace std;



void print_menu()
{
  printf("Press 1  to Add 1\n");
  printf("Press 2  to Add 2\n");
  printf("Press 99 to exit\n");
}

int main(int argc, const char *argv[])
{
  int options = 0;
  int total = 0;
  while(options != 99)
  {
    print_menu();
    switch(options)
    {
      case 1:
        total = total + 1;
        break;
      case 2:
        total = total + 2;
        break;
      default:
        break;
    }
    printf("total value = %d\n", total);
    cin >> options;
  }

  return 0;
}
