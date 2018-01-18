//**********************************************************************
//*                                                                    *
//* Program Name: PROG05 - Calculates The Ratio of Area of The Square  *
//*                        to The Area of The Circle                   *
//* Author:       Ben Tobias                                           *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: March 22, 2011                                       *
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
//* This program asks the user to enter the diameter of a circle. It   *
//* calculates the specifications of the circle and the square where   *
//* the perimeter is equal to the circle's circumference, print their  *
//* specifications, then calculates and prints the ratio of the area   *
//* of the square to the area of the circle.                           *
//*                                                                    *
//**********************************************************************

#include "stdafx.h"
#include <iostream>
using namespace std;
class circle;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME    "Object-Oriented Programming and Design"
                                 // PCC assigned course name
#define COURSE_NUMBER  "CS246"   // PCC assigned course number   
#define MIN_DIAMETER   0.0f      // Minimum circle diameter in units
#define PI             3.141593f // Mathematical constant Pi
#define PROGRAM_NUMBER 5         // Teacher assigned program number
#define QUIT_DIAMETER  0.0f      // Diameter that allow the user to quit
           
//**********************************************************************
//*                          Program Classes                           *
//**********************************************************************
// The square specifications
class square
{
   float area,      // The area of a square in square units
         perimeter, // The perimeter of a square in units
         side;      // The side of a square in units
public:
   // Constructor
                 square         ()        {}
                 square         (float s) {area      = s * s;
                                           perimeter = 4.0f * s;
                                           side      = s;}

   // Set the member variables
          void   set_area       (float a) {area      = a;}
          void   set_perimeter  (float p) {perimeter = p;}
          void   set_side       (float s) {side      = s;}

   // Get the member variables
          float  get_area       ()        {return area;}
          float  get_perimeter  ()        {return perimeter;}
          float  get_side       ()        {return side;}

   // Returns a square where the perimeter is equal to the circumference
   // of the circle   
          square create_square  (circle user_circle);

   // Returns the ratio of the area of the square to the area of the
   // circle
   friend float  calculate_ratio(square user_square, 
                                 circle user_circle);
};

// The circle specifications
class circle
{
   float area,          // The area of a circle in square units
         circumference, // The circumference of a circle in units
         diameter;      // The diameter of a circle in units
public:
   // Constructor
                 circle               ()        {}
                 circle               (float d) {area          = 0.25f *
                                                             PI * d * d;  
                                                 circumference = PI * d;
                                                 diameter      = d;}

   // Set the member variables
          void   set_area             (float a) {area          = a;}
          void   set_circumference    (float c) {circumference = c;}
          void   set_diameter         (float d) {diameter      = d;}

   // Get the member variables
          float  get_area             ()        {return area;}
          float  get_circumference    ()        {return circumference;}
          float  get_diameter         ()        {return diameter;}

   // Return a square where the perimeter is equal to the circumference
   // of the circle   
   friend square square::create_square(circle user_circle);

   // Returns the ratio of the area of the square to the area of the
   // circle
   friend float  calculate_ratio      (square user_square, 
                                       circle user_circle);
};

//**********************************************************************
//* Returns a square where the perimeter is equal to the circumference *
//*                           of the circle                            *
//**********************************************************************
square square::create_square(circle user_circle)
{
   square user_square(user_circle.get_circumference() * 0.25f);

   return user_square;
}

//**********************************************************************
//*   Returns the ratio of the area of the square to the area of the   *
//*                               circle                               *
//**********************************************************************
float calculate_ratio(square user_square, circle user_circle)
{
   return user_square.get_area() / user_circle.get_area();
}

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading
circle get_circle();
   // Get the diameter of the circle and return its circle

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   square user_square; // The unitialized square geometric shape
   circle user_circle; // The unitialized circle geometric shape

   // Print the heading
   print_heading();

   // Loop processing the circle diameter until the user says to quit
   cout << "\n";
   while (user_circle = get_circle(), 
                            user_circle.get_diameter() != QUIT_DIAMETER)
   {
      // Print the circle's specifications
      cout << "\n\nThe circle's specifications are:";
      cout << "\n--------------------------------";
      cout << "\n        diameter: " << user_circle.get_diameter();
      cout << "\n   circumference: " << user_circle.get_circumference();
      cout << "\n            area: " << user_circle.get_area();
      
      // Create the square geometric shape
      user_square = user_square.create_square(user_circle);

      // Print the square's specifications
      cout << "\n\nThe square's specifications are:";
      cout << "\n--------------------------------";
      cout << "\n            side: " << user_square.get_side();
      cout << "\n       perimeter: " << user_square.get_perimeter();
      cout << "\n            area: " << user_square.get_area();

      // Calculate and print the ratio of square and circle's area
      cout << "\n\nRatio of the square's area to the circle's area is:";
      cout << "\n-----------------------------------------------";
      cout << "\n              <**** "  
           << calculate_ratio(user_square, user_circle) << " ****>"; 
   }

   // Print a goodbye message and terminate the program
   cout << "\n\n  Goodbye, and I hope you learned something about the";
   cout << "\n ratio of the area of a square to the area of a circle,";
   cout << "\n where the perimeter of the square is exactly equal to";
   cout << "\n            the circumference of the circle.";
   return 0;
}

//**********************************************************************
//*                     Print the program heading                      *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n        " << COURSE_NUMBER 
        << ' '                    << COURSE_NAME
        << " - Program "          << PROGRAM_NUMBER;
   cout << "\n        "
        << "========================================================";

   return;
}

//**********************************************************************
//*        Get the diameter of the circle and return its circle        *
//**********************************************************************
circle get_circle()
{
   float user_diameter; // The diameter of a circle in units

   do
   {
      cout << "\n\nEnter a circle diameter greater than " 
                                                        << MIN_DIAMETER
           << " (or "                                   << QUIT_DIAMETER
           << " to quit): ";
      cin  >> user_diameter;

      if (user_diameter < MIN_DIAMETER)
         cout << "     Invalid: diameter must be greater than " 
                                                        << MIN_DIAMETER
              << " (or "                                << QUIT_DIAMETER
              << " to quit).";
   } 
   while (user_diameter < MIN_DIAMETER && 
                                        user_diameter != QUIT_DIAMETER);

   circle user_circle(user_diameter); 
   
   return user_circle; 
}

// using pen:
// The square is created by using the circle's circumference as the 
// square's perimeter. it makes the comparison calculation of both area 
// performed cancelation of diameter which is leaves Pi over four. No 
// matter what diameter that the user enter, the ratio is still Pi over 
// four.