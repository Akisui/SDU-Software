
// test changeLength2D.h

#include <iostream>
#include "changeLength2D.h"
#include "make2dArray.h"

using namespace std;

void main(void)
{
   int **x;
   make2dArray(x, 3, 4);
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         x[i][j] = i + j;
         cout << x[i][j] << ' ';
      }
      cout << endl;
   }

   changeLength2D(x, 3, 4, 2, 2);

   cout << endl << endl;

   for (int i = 0; i < 2; i++)
   {
      for (int j = 0; j < 2; j++)
         cout << x[i][j] << ' ';
      cout << endl;
   }
}
