

// Compute sum_(0 <= i < n) a[i] * b[i]

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
T inner_product(T a[], T b[], int n)
{// Return sum_(0 <= i < n) a[i] * b[i].
   T ip = 0;
   for (int i = 0; i < n; i++)
      ip += a[i] * b[i];
   return ip;
}

int main()
{
   int a[3] = {1, 2, 3};
   int b[3] = {2, 2, 1};

   // output the array elements
   cout << "a[0:3] = ";
   copy(a, a+3, ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "b[0:3] = ";
   copy(b, b+3, ostream_iterator<int>(cout, " "));
   cout << endl;

   // test the function inner_product
   cout << "inner_product(a,b,3) = " << inner_product(a,b,3) << endl;
   return 0;
}
