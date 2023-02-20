// test enhancedCurrencyOverload

#include <iostream>
#include "enhancedCurrencyOverload.h"

using namespace std;

void main(void)
{
   currency g, h, i, j;
   cin >> g;
   cin >> h;


   i = g - h;
   cout << g << " - " << h << " = " 
        << (g - h) << endl;

   cout << "10% of " << g << " = "
        << (g % 10) << endl;

   cout << "3 * " << g << " = "
        << (g * 3) << endl;

   cout << "Half of " << g << " = "
        << (g / 2) << endl;
}
