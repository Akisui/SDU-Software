// function to compute an expression using int value parameters
// throw an exception of type int in case all of the parameters are <= 0

#include<iostream>

using namespace std;

int abc(int a, int b, int c)
{
   if (a < 0 && b < 0 && c < 0)
          throw 1;
   if (a == 0 && b == 0 && c == 0)
          throw 2;
   return a + b * c;
}

int main()
{
  int a = -1, b = -2, c= -3;
  cout << "The parameters to abc were " << a << ", "
       << b << ", " << c << endl;
  try {cout << abc(a,b,c) << endl;}
  catch (int e)
      {
         if (e == 1)
            cout << "All are < 0" << endl;
         else
            cout << "All are = 0" << endl;
      }
  a = b = c= 0;
  cout << "The parameters to abc were " << a << ", "
       << b << ", " << c << endl;
  try {cout << abc(a,b,c) << endl;}
  catch (int e)
      {
         if (e == 1)
            cout << "All are < 0" << endl;
         else
            cout << "All are = 0" << endl;
      }
  a = 1; b = 2; c= 0;
  cout << "The parameters to abc were " << a << ", "
       << b << ", " << c << endl;
  try {cout << abc(a,b,c) << endl;}
  catch (int e)
      {
         if (e == 1)
            cout << "All are < 0" << endl;
         else
            cout << "All are = 0" << endl;
         return 1;
      }
   cout << "No Exception" << endl;
   return 0;
}

