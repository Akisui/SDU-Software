
// Second version of recursive dynamic programming solution for
// the matrix multiplication chains problem, this version
// computes each c(i,j) at most once 

#include <iostream>
#include "make2dArray.h"

using namespace std;

// global variables
int *r;      // r[i] is number of rows in matrix i
int **kay;   // recurrence selector
int **theC;
   
int c(int i, int j)
{// Return c(i,j) and compute kay[i][j] = kay(i,j).
   // check if already computed
   if (theC[i][j] > 0)  // c(i,j) was computed earlier
      return theC[i][j];

   // c(i,j) not computed before, compute it now
   if (i == j)
      return 0;  // one matrix
   if (i == j - 1)
   {// two matrices
      kay[i][i + 1] = i;
      theC[i][j] = r[i] * r[i + 1] * r[i + 2];
      return theC[i][j];
   }

   // more than two matrices
   // set u to min term for k = i
   int u = c(i,i) + c(i + 1, j) + r[i] * r[i + 1] * r[j + 1];
   kay[i][j] = i;

   // compute remaining min terms and update u
   for (int k = i + 1; k < j; k++)
   {
      int t = c(i, k) + c(k + 1, j) + r[i] * r[k + 1] * r[j + 1];
      if (t < u)
      {// smaller min term found, update u and kay[i][j]
         u = t;
         kay[i][j] = k;
      }
   }

   theC[i][j] = u;
   return theC[i][j];
}

void traceback(int i, int j)
{// Output best way to compute Mij.
   if (i == j)  // only one matrix
      return;
   traceback(i, kay[i][j]);
   traceback(kay[i][j] + 1, j);
   cout << "Multiply M " << i << ", " << kay[i][j] <<
           " and M " << (kay[i][j] + 1) << ", " << j << endl;
}

void main(void)
{
   // initialize
   cout << "Enter number of matrices" << endl;
   int q;
   cin >> q;
   r = new int [q + 2];
   make2dArray(kay, q + 1, q + 1);
   make2dArray(theC, q + 1, q + 1);
   for (int i = 1; i <= q; i++)
      for (int j = i; j <= q; j++)
         theC[i][j] = 0;

   // input matrix data
   for (int i = 1; i <= q; i++)
   {
      cout << "Enter number of rows in matrix " << i << endl;
      cin >> r[i];
   }
   cout << "Enter number of columns in matrix " << q << endl;
   cin >> r[q + 1];

   // compute cost of best way to multiply
   cout << "Minimum cost is " << c(1, q) << endl;

   // output optimal multiplication sequence
   traceback(1, q);
}
