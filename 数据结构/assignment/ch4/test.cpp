// measure the times of program 2-22.

#include <iostream>
#include <time.h>
using namespace std;

// multiply the n x n matrices a and b to get c (2-22)
void squareMatrixMultiply(int a[][100], int b[][100], int c[][100], int n)
{
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
         int sum = 0;
         for (int k = 0; k < n; k++)
            sum += a[i][k] * b[k][j];
         c[i][j] = sum;
      }
}

int a[100][100], b[100][100], c[100][100];

int main()
{
   // generate the 100x100 matrix
   for (int i = 0; i < 100; ++i)
      for (int j = 0; j < 100; ++j)
      {
         a[i][j] = i + j;
         b[i][j] = i - j;
      }  
   
   // step of measure
   int step = 10;

   // clock ticks per millisecond
   double clocksPerMillis = double(CLOCKS_PER_SEC) /1000;

   for (int n = 10; n <= 100; n += step)
   {
      double average_times = 0; // sum of 1000 times test
      for (int i = 1; i <= 1000; ++i)
      {
         clock_t startTime = clock(); // mark the start time
         squareMatrixMultiply(a,b,c,n); // call multiply function

         // calculus the time of such condition
         double elapsedMillis = (clock() - startTime) / clocksPerMillis;
         average_times += elapsedMillis;
      }
      average_times = average_times / 1000; // calculus the average
      cout << n << "\t" << average_times << endl; // output
   }
   return 0;
}