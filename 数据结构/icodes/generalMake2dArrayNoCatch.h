// create a 2D array but do not catch exception thrown
// when new fails to allocate sufficient memory
// general version; rows may have different size

#ifndef generalMake2dArrayNoCatch_
#define generalMake2dArrayNoCatch_

using namespace std;

template <class T>
void make2dArray(T ** &x, int numberOfRows, int* rowSize)
{// Create a two-dimensional array.

   // create pointers for the rows
   x = new T * [numberOfRows];
      
   // get memory for each row
   for (int i = 0; i < numberOfRows; i++)
      x[i] = new T [rowSize[i]];
}

#endif
