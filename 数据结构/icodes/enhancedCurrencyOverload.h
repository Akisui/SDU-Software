// currency class with operator overloading
// enhanced to include >>, -, %, *, /

#ifndef currency_
#define currency_

#include <iostream>
#include "myExceptions.h"

using namespace std;

enum signType {plus, minus};

class currency 
{
   friend istream& operator>>(istream&, currency&);
   public:
      // constructor
      currency(signType theSign = plus,
               unsigned long theDollars = 0,
               unsigned int theCents = 0);
      // destructor
      ~currency() {}
      currency operator=(int theAmount)
      {
         amount = theAmount;
         return *this;
      }
      currency operator=(float theAmount)
      {
         if (theAmount < 0)
            amount = (long) ((theAmount - 0.001) * 100);
         else
            amount = (long) ((theAmount + 0.001) * 100);
         return *this;
      }
      signType getSign() const
        {if (amount < 0) return minus;
         else return plus;}
      unsigned long getDollars() const
        {if (amount < 0) return (-amount) / 100;
         else return amount / 100;}
      unsigned int getCents() const
        {if (amount < 0) return -amount - getDollars() * 100;
         else return amount - getDollars() * 100;}
      currency operator+(const currency&) const;
      currency operator-(const currency&) const;
      currency operator%(float) const;
      currency operator*(float) const;
      currency operator/(float) const;
      currency& operator+=(const currency& x)
        {amount += x.amount; return *this;}
      void output(ostream&) const;
   private:
      long amount;
};

currency::currency(signType theSign, unsigned long theDollars,
                                     unsigned int theCents)
{// Create a currency object.
   if (theCents > 99)
      // too many cents
      throw illegalParameterValue("Cents should be < 100");
   
   amount = theDollars * 100 + theCents;
   if (theSign == minus) amount = -amount;
}

currency currency::operator+(const currency& x) const
{// Add x and *this.
   currency result;
   result.amount = amount + x.amount;
   return result;
}

currency currency::operator-(const currency& x) const
{// Subtract x from *this.
   currency y;
   y.amount = amount - x.amount;
   return y;
}

currency currency::operator%(float x) const
{// Return x% of *this.
   currency y;
   y.amount = (long) (amount * x) / 100;
   return y;
}

currency currency::operator*(float x) const
{// Return x * (*this).
   currency y;
   y.amount = (long) (amount * x);
   return y;
}

currency currency::operator/(float x) const
{// Return (*this) / x.
   currency y;
   y.amount = (long) (amount / x);
   return y;
}

void currency::output(ostream& out) const
{// Insert currency value into stream out.
   long theAmount = amount;
   if (theAmount < 0) {out << '-';
                       theAmount = -theAmount;}
   long dollars = theAmount / 100; // dollars
   out << '$' << dollars << '.';
   int cents = theAmount - dollars * 100; // cents
   if (cents < 10) out << '0';
   out << cents;
}

// overload <<
ostream& operator<<(ostream& out, const currency& x)
   {x.output(out); return out;}

// overload >>
istream& operator>>(istream& in, currency& x)
{// Input a currency amount.

   float y;
   cout << "Enter the currency amount as "
        << "a floating point number as in dd.cc or -dd.cc"
        << endl;

   in >> y;
   x = y;
   return in;
}
#endif
