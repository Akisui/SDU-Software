// change the dimensions of a 2D array

#ifndef changeLength2D_
#define changeLength2D_

#include "make2dArray.h"
#include "delete2dArray.h"
#include "myExceptions.h"

using namespace std;

template<class T>
void changeLength2D(T**& a, int oldRows, int oldColumns,
                           int newRows, int newColumns)
{
   if (newRows < 0 || newColumns < 0)
      throw illegalParameterValue("# of rows and columns must be >= 0");

   T** temp;
   make2dArray(temp, newRows, newColumns);
   int rowsToCopy = min(oldRows, newRows);
   int columnsToCopy = min(oldColumns, newColumns);
   for (int i = 0; i < rowsToCopy; i++)
      copy(a[i], a[i] + columnsToCopy, temp[i]);
   delete2dArray(a, oldRows);    // deallocate old memory
   a = temp;
}

#endif
