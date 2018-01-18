//**********************************************************************
//*                                                                    *
//* Program Name: PROG07S - Test for the presence of all required      *
//*                         money class overloaded operator and member *
//*                         functions in a money.h file.               *
//* Author:       CS246 Instructor                                     *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: January 2, 2008                                      *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* This program tests to see if an included "money.h" file contains   *
//* all required money class overloaded operator and member functions. *
//* The "money.h" file being tested must be in this programs folder.   *
//* If this program runs correctly after compiling and linking, the    *
//* "money.h" file does contain all required money class overloaded    *
//* operator and member functions.                                     *
//* NOTE: This program DOES NOT test the correct execution of these    *
//*       overloaded operators and member functions.  It ONLY tests    *
//*       for their presence in the included "money.h" file.           *
//*                                                                    *
//**********************************************************************

#include "stdafx.h"
#include<iostream>
#include "money.h"
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME     "Object-Oriented Programming and Design"
                                 // PCC assigned course name
#define COURSE_NUMBER   "CS246"  // PCC assigned course number
#define PROGRAM_NUMBER  "7S"     // Teacher assigned program number

void print_objects(money ob1, money ob2, money ob3);

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   // Print the program heading
   cout << "\n\n\n\n\n\n" << COURSE_NUMBER
        << " "            << COURSE_NAME
        << " - Program "  << PROGRAM_NUMBER;
   cout << "\n=========================================================";

   // Print the "complied and linked properly" message
   cout << "\n\n  Your money.h compiled and linked properly, indicating"
        <<   "\n  all required overloaded operator and member functions"
        <<   "\n  are present. However this DOES NOT mean the functions"
        <<   "\n  are working correctly.   YOU MUST completely test all"
        <<   "\n  your functions yourself, to ensure their reliability.";


   // Test for the presence of the constructors
   money ob4,        // Uninitialized money object
         ob5(-10.50), // Initialized   money object
         ob3;
   float amount1, amount2;
   cout << "\n\n...Initialized and uninitialized initialization success!";

   // Test for the presence of the set member functions
   ob4.set_dollars(25.50f);
   ob4.set_cents  (0.75f);
   cout << "\n\n...All the set member functions working!";
   // However, i'm going to test with another value
   cout << "\n\nEnter the amount for ob1: ";
   cin  >> amount1;
   cout << "Enter the amount for ob2: ";
   cin  >> amount2;

   money ob1(amount1),
         ob2(amount2);

   // Test for the presence of the get member function
   cout << "\n\nTest to print all object before do anthing:";
   print_objects(ob1, ob2, ob3);

   cout << "\n\nComparing 'if (ob1 == ob2)':";
   if (ob1 == ob2)
      cout << "\n   relation ob1 and ob2 is TRUE";
   else 
      cout << "\n   relation ob1 and ob2 is FALSE";

   cout << "\n\nComparing 'if (ob1 != ob2)':";
   if (ob1 != ob2)
      cout << "\n   relation ob1 and ob2 is TRUE";
   else 
      cout << "\n   relation ob1 and ob2 is FALSE";

   ob3 = ob1  + ob2;
   cout << "\n\nAfter statement 'ob3 = ob1 + ob2':";
   print_objects(ob1, ob2, ob3);

   ob3 = ob1  - ob2;
   cout << "\n\nAfter statement 'ob3 = ob1 - ob2':";
   print_objects(ob1, ob2, ob3);

   ob3 = ob1  * ob2;
   cout << "\n\nAfter statement 'ob3 = ob1  * ob2':";
   print_objects(ob1, ob2, ob3);
   
   ob3 = ob1  / ob2;
   cout << "\n\nAfter statement 'ob3 = ob1 / ob2':";
   print_objects(ob1, ob2, ob3);
   
   ob1 += ob2;
   cout << "\n\nAfter statement 'ob1 += ob2':";
   print_objects(ob1, ob2, ob3);
   
   ob3 = ob1 << 3    ;
   cout << "\n\nAfter statement 'ob3 = ob1 << 3':";
   print_objects(ob1, ob2, ob3);
   
   ob3 = ob2 >> 3    ;
   cout << "\n\nAfter statement 'ob3 = ob2 >> 3':";
   print_objects(ob1, ob2, ob3);
   
   ob3 =      ++ob1;
   cout << "\n\nAfter statement 'ob3 = ++ob1':";
   print_objects(ob1, ob2, ob3);
   
   ob3 = ob1++     ;
   cout << "\n\nAfter statement 'ob3 = ob1++':";
   print_objects(ob1, ob2, ob3);
   
   ob1  = ob2;
   cout << "\n\nAfter statement 'ob1 = ob2':";
   print_objects(ob1, ob2, ob3);
   
}

void print_objects(money ob1, money ob2, money ob3)
{
   cout << "\nob1 members and total:";
   cout << "\n   Dollars = "    << ob1.get_dollars();
   cout << "\n   Cents   =   "    << ob1.get_cents();
   cout << "\n           ----------- +";
   cout << "\n   Total   = " << ob1.get_total();
   cout << "\nob2 members and total:";
   cout << "\n   Dollars = "    << ob2.get_dollars();
   cout << "\n   Cents   =   "    << ob2.get_cents();
   cout << "\n           ----------- +";
   cout << "\n   Total   = " << ob2.get_total();
   cout << "\nob3 members and total:";
   cout << "\n   Dollars = "    << ob3.get_dollars();
   cout << "\n   Cents   =   "    << ob3.get_cents();
   cout << "\n           ----------- +";
   cout << "\n   Total   = " << ob3.get_total();
}