// test enhancedCurrency class

#include <iostream>
#include "enhancedCurrency.h"

using namespace std;

void main(void)
{
   enhancedCurrency g, h(plus, 3, 50), i(plus, 2, 50), j;

   // test input
   j.input();
   cout << "The input value is ";
   j.output();
   cout << endl;
   
   // test remaining new methods
   h.output();
   cout << " - ";
   i.output();
   cout << " = ";
   h.subtract(i).output();
   cout << endl;
   cout << "10 percent of ";
   i.output();
   cout << " is ";
   i.percent(10.0).output();
   cout << endl;
   cout << "2 * ";
   i.output();
   cout << " = ";
   i.multiply(2.0).output();
   cout << endl;
   i.output();
   cout << " / 5 = ";
   i.divide(5.0).output();
   cout << endl;
}
