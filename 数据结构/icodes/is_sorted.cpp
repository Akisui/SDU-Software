// Return true iff a[0:n-1] are in non-decreasing order

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
bool is_sorted(T a[], int n)
{// Return true iff a[0:n-1] are in non-decreasing order.
   for (int i = 0; i < n - 1; i++)
      if (a[i] > a[i + 1])
         return false;
   return true;
}

int main()
{
   int a[6] = {1, 2, 3, 4, 5, 6};
   int b[5] = {1, 2, 4, 2, 1};

   // output the array elements
   cout << "a[0:5] = ";
   copy(a, a+6, ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "b[0:4] = ";
   copy(b, b+5, ostream_iterator<int>(cout, " "));
   cout << endl;

   // test the function is_sorted
   cout << "is_sorted(a,6) = " << is_sorted(a,6) << endl;
   cout << "is_sorted(b,5) = " << is_sorted(b,5) << endl;
   return 0;
}
