
// count number of occurrences of specified value

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
int count(T a[], int n, const T& value)
{// Return number of occurrences of value in a[0:n-1].
   int theCount = 0;
   for (int i = 0; i < n; i++)
      if (a[i] == value)
         theCount++;
   return theCount;
}

int main()
{
   int a[6] = {6, 2, 6, 4, 5, 6};

   // output the array elements
   cout << "a[0:5] = ";
   copy(a, a+6, ostream_iterator<int>(cout, " "));
   cout << endl;

   // test the function count
   cout << "count(a,6,0) = " << count(a,6,0) << endl;
   cout << "count(a,6,4) = " << count(a,6,4) << endl;
   cout << "count(a,6,6) = " << count(a,6,6) << endl;
   return 0;
}
