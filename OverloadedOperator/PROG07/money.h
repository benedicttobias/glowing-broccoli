//**********************************************************************
//*                                                                    *
//* Program Name: money.h - The Header File for Money Class Objects    *
//* Author:       Ben Tobias                                           *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: April 14, 2010                                       *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* I pledge the lines  in this C++ program are my own  original work, *
//* and none of the  lines in this C++  program have been  copied from *
//* anyone else,  unless I was specifically  authorized to do so by my *
//*                          CS246 instructor.                         *
//*                                                                    *
//*                                                                    *
//*                      Signed: ____________________________________  *
//*                                           (signature)              *
//*                                                                    *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* This header contains the money class objects which handles the     *
//* money amount. The dollars and the cents in the amount of money are *
//* forced to be separate into two whole numbers integer value         *
//* (dollars and cents part). The following operation are implemented  *
//* into money class object: assignment, addition, subtraction,        *
//* multiplication, division, shorthand summation, relational          *
//* equality, relational not equal to, left shift, right shift, prefix *
//* increment, and postfix increment operators.                        *
//*                                                                    *
//**********************************************************************

#include <iostream>
#include "stdafx.h"
using namespace std;

//**********************************************************************
//*                           Program Class                            *
//**********************************************************************
// Money amounts class
class money
{
   int cents,   // The cents part in the amount of money
       dollars; // The dollars part in the amount of money
public: 
   // Constructors
         money      ()                {dollars = 0; cents = 0;        }
         money      (float amount)    {set_dollars(amount); 
                                       set_cents  (amount);           }

   // Set the member variables
   void  set_cents  (float amount);
   void  set_dollars(float amount)    {dollars = (int) amount;        } 

   // Get the member variables
   float get_total  ()                {return (float) dollars + 
                                              (float) cents   * 0.01f;}
   int   get_dollars()                {return dollars;    } // DELETE LATER
   int   get_cents  ()                {return cents;      } // DELETE LATER

   // Overloaded Operators
   money operator=  (money object2  );
   money operator+  (money object2  );
   money operator-  (money object2  );
   money operator*  (money object2  );
   money operator/  (money object2  );
   money operator+= (money object2  );
   int   operator== (money object2  );
   int   operator!= (money object2  );
   money operator<< (int   shift    );
   money operator>> (int   shift    );
   money operator++ (               );
   money operator++ (int   not_used );
};
  
//**********************************************************************
//*                           Set the cents                            *
//**********************************************************************
void money::set_cents (float amount)
{
   // Eliminate the dollar part by subtract the dollar itself
   amount -= (int) amount;

   // Check if the amount less or more than 0
   if (amount < 0.00f)
      amount -= 0.005f; // Subtract the cents by 0.005
   else
      amount += 0.005f; // Add the cents by 0.005

   // Multiply the subtracted amount by 100
   amount *= 100.0f;

   // Truncate the fixed cents to integer and assign it to the cents part
   cents = (int) amount;

   // Reround the cents if its bigger than 99 or smaller than -99
   if (cents > 99)
   {
      cents   -= 100;
      dollars += 1;
   }
   else if (cents < -99)
   {
      cents   += 100;
      dollars -= 1;
   }

   return;
}

//**********************************************************************
//*                   Overloaded assignment operator                   *
//**********************************************************************
money money::operator= (money object2)
{
   dollars = object2.dollars;
   cents   = object2.cents;

   return *this;
}

//**********************************************************************
//*                    Overloaded addition operator                    *
//**********************************************************************
money money::operator+ (money object2)
{
   money sum(get_total() + object2.get_total()); 
                                      // The sum of two amounts of money
   
   return sum;
}

//**********************************************************************
//*                   Overloaded subtraction operator                  *
//**********************************************************************
money money::operator- (money object2)
{
   money difference(get_total() - object2.get_total());
                               // The difference of two amounts of money
   
   return difference;
}

//**********************************************************************
//*                 Overloaded multiplication operator                 *
//**********************************************************************
money money::operator* (money object2)
{
   money product(get_total() * object2.get_total());
                                  // The product of two amounts of money

   return product;
}

//**********************************************************************
//*                    Overloaded division operator                    *
//**********************************************************************
money money::operator/ (money object2)
{
   money quotient; // The quotient of two amounts of money

   if (object2.get_total() == 0.00f)
   {
      cout << "\nWarning: A divide by 0.00 operation cannot be done!";
      cout << "\nThe result of this operation is being set to  0.00!";
      quotient = 0.00f;
   }
   else
      quotient = get_total() / object2.get_total();
   
   return quotient;
}

//**********************************************************************
//*      Overloaded sum compound assignment/shorthand sum operator     *
//**********************************************************************
money money::operator+= (money object2)
{
   *this = get_total() + object2.get_total();

   return *this;
}

//**********************************************************************
//*              Overloaded relational equality operator               *
//**********************************************************************
int money::operator== (money object2)
{
   return (dollars == object2.dollars && cents == object2.cents);
}

//**********************************************************************
//*            Overloaded relational not equal to operator             *
//**********************************************************************
int money::operator!= (money object2)
{
   return (dollars != object2.dollars || cents != object2.cents);
}

//**********************************************************************
//*                   Overloaded left shift operator                   *
//**********************************************************************
money money::operator<< (int shift)
{
   int   counter;            // Counts until equal to the shift power
   float shift_power = 1.0f; // The shift amount for the division
   
   for(counter = 1; counter <= shift; counter++)
      shift_power *= 10.0f;  

   return get_total() / shift_power;
}

//**********************************************************************
//*                  Overloaded right shift operator                   *
//**********************************************************************
money money::operator>> (int shift)
{
   int   counter;            // Counts until equal to the shift power
   float shift_power = 1.0f; // The shift amount for the multiplication

   for(counter = 1; counter <= shift; counter++)
      shift_power *= 10.0f;

   return get_total() * shift_power;
}

//**********************************************************************
//*                Overloaded prefix increment operator                *
//**********************************************************************
money money::operator++ ()
{
   dollars += 1;

   return *this;
}

//**********************************************************************
//*               Overloaded postfix increment operator                *
//**********************************************************************
money money::operator++ (int not_used)
{
   dollars += 1;

   return (get_total() - 1.0f);
}