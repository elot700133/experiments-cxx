#include <iostream>
#include <array>

using namespace std;


int main(int argc, const char *argv[])
{
  int aa[3][3] = {{0,1,2},{3,4,5},{6,7,8}};
//////////////////////////////////////////////////////////////////////
  int (*p)[3] = aa;
  for ( int i = 0; i<3; i++ )
  {
    for ( int j = 0; j<3; j++)
    {
      printf("p[%d][%d] = %d\n",i,j,p[i][j]);
    }
  }

//////////////////////////////////////////////////////////////////////
  // this won't work
  int (*p2)[3][3] = &aa; // pointer arith won't work, it is incrementing to end of aa
  for ( int i = 0; i<3; i++ )
  {
    for ( int j = 0; j<3; j++)
    {
      printf("p2[%d][%d] = %d\n",i,j,p2[i][j]);
    }
  }

//////////////////////////////////////////////////////////////////////
  //int **p3 = &aa; // &aa is of type int (*)[3][3] - a pointer to an int array of 3 elements, with each of 3 elements of int
  int *p3 = &aa[0][0];
  for ( int i = 0; i<3; i++ )
  {
    for ( int j = 0; j<3; j++)
    {
      printf("p3[%d][%d] = %d\n",i,j, p3[i*3 + j]);
    }
  }
//////////////////////////////////////////////////////////////////////
  using ArrayType=std::array< std::array<int, 3>, 3>;
  ArrayType xx{{{{0,1,2}},{{3,4,5}},{{6,7,8}}}};
  ArrayType* p4 = &xx;
  for ( int i = 0; i<3; i++ )
  {
    for ( int j = 0; j<3; j++)
    {
      printf("p4[%d][%d] = %d\n",i,j, (*p4)[i][j]);
    }
  }

  return 0;
}
