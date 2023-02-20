// enhancement of currency to include the methods input,
// subtract, percent, multiply, and divide

#ifndef enhancedCurrency_
#define enhancedCurrency_

#include "currency.h"

class enhancedCurrency : public currency
{
   public:
      // same constructors as in super class
      enhancedCurrency(signType theSign = plus,
                       unsigned long theDollars = 0,
                       unsigned int theCents = 0) :
         currency(theSign, theDollars, theCents) {}
   
      // new instance methods
      void input()
      {
         // input the amount as a double
         cout << "Enter the currency amount as a real number" << endl;
         double theValue;
         cin >> theValue;
   
         // set the value
         setValue(theValue);
      }
   
      enhancedCurrency subtract(const enhancedCurrency& x)
      {// Return *this - x.
         // convert *this to a long
         long a1 = getDollars() * 100 + getCents();
         if (getSign() == minus) a1 = -a1;
         
         // convert x to a long
         long a2 = x.getDollars() * 100 + x.getCents();
         if (x.getSign() == minus) a2 = -a2;
         
         long a3 = a1 - a2;
          
         // convert result to enhancedCurrency object
         enhancedCurrency result;
         signType theSign = plus;
         if (a3 < 0)
         {
            theSign = minus;
            a3 = -a3;
         }
         result.setValue(theSign, a3 / 100, a3 - a3 / 100 * 100);
         
         return result;
      }
   
      enhancedCurrency percent(float x)
      {// Return x percent of *this.
         long a1, a2;
         // convert this to a long
         a1 = getDollars() * 100 + getCents();
         if (getSign() == minus) a1 = -a1;
         
         a2 = (long) (a1 * x / 100);
          
         // convert result to enhancedCurrency object
         enhancedCurrency result;
         signType theSign = plus;
         if (a2 < 0)
         {
            theSign = minus;
            a2 = -a2;
         }
         result.setValue(theSign, a2 / 100, a2 - a2 / 100 * 100);
         
         return result;
      }
   
      enhancedCurrency multiply(float x)
      {// Return this * x.
         long a1, a2;
         // convert this to a long
         a1 = getDollars() * 100 + getCents();
         if (getSign() == minus) a1 = -a1;
         
         a2 = (long) (a1 * x);
          
         // convert result to enhancedCurrency object
         enhancedCurrency result;
         signType theSign = plus;
         if (a2 < 0)
         {
            theSign = minus;
            a2 = -a2;
         }
         result.setValue(theSign, a2 / 100, a2 - a2 / 100 * 100);
         
         return result;
      }
   
      enhancedCurrency divide(float x)
      {// Return this / x.
         long a1, a2;
         // convert this to a long
         a1 = getDollars() * 100 + getCents();
         if (getSign() == minus) a1 = -a1;
         
         a2 = (long) (a1 / x);
          
         // convert result to enhancedCurrency object
         enhancedCurrency result;
         signType theSign = plus;
         if (a2 < 0)
         {
            theSign = minus;
            a2 = -a2;
         }
         result.setValue(theSign, a2 / 100, a2 - a2 / 100 * 100);
         
         return result;
      }
};
#endif
