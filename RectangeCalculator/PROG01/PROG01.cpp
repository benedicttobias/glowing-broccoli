//**********************************************************************
//*                                                                    *
//* Program Name: PROG01 - Draw and Calculate Rectangle                *
//* Author:       Ben Tobias                                           *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS 246, Object-Oriented Programming and Design       *
//* Date Written: February 1, 2011                                     *
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
//* This program prints the message "Hello World!", and then manages   *
//* integer ranges, which consist of minimum and maximum range values, *
//* and the inclusive sum of all integers in the range.                *
//*                                                                    *
//**********************************************************************

#include "stdafx.h"
#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME    "Object-Oriented Programming and Design"
                               // PCC assigned course name
#define COURSE_NUMBER  "CS246" // PCC assigned course number
#define MIN_REC_LENGTH 1.0f    // Minimum rectangle length
#define MIN_REC_WIDTH  1.0f    // Minimum rectangle width
#define PROGRAM_NUMBER 1       // Teacher assigned program number
#define REC_BORDER     '*'     // Rectangle border character
#define REC_CENTER     ' '     // Rectangle center character
#define SCALE_FACTOR   1.5     // Scale factor to rectangle length

//**********************************************************************
//*                         Program Structures                         *
//**********************************************************************
// The specification of a rectangle
struct REC_STRUCTURE
{
   float rec_area,      // Area of the rectangle (L x W) in square units
         rec_length,    // Length of the rectangle in units
         rec_perimeter, // Perimeter of the rectangle (2L + 2W) in units
         rec_width;     // Width of the rectangle in units    
};

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading   
void get_rectangle(struct REC_STRUCTURE *p_rectangle);
   // Get the length and the width of an rectangle
void draw_rectangle(float rec_length, float rec_width);
   // Draw a rectangle base on the length and the width
void print_specification(struct REC_STRUCTURE rectangle);
   // Print the specifications of the rectangle

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   struct REC_STRUCTURE rectangle;

   // Print the program heading 
   print_heading();

   // Get the length and the width of a rectangle
   get_rectangle(&rectangle); 

   // Print and draw rectangle 
   draw_rectangle     (rectangle.rec_length, rectangle.rec_width);
   print_specification(rectangle);

   // Print a goodbye message and terminate the program               
   cout << "\n\n\nThanks for drawing a rectangle today ;)";
   cout << "\n\n\n\n\n\n";

   return 0;
}

//**********************************************************************
//*                     Print the program heading                      *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n";
   cout << "            " << COURSE_NUMBER 
        << ' '            << COURSE_NAME
        << " - Program "  << PROGRAM_NUMBER;
   cout << "\n\n                     This programs draws a rectangle";
   cout << "\n                     ===============================";

   return;
}

//**********************************************************************
//*            Get the length and the width of a rectangle             *
//**********************************************************************
void get_rectangle(struct REC_STRUCTURE *p_rectangle)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> p_rectangle->rec_length;
   cout << "Enter the rectangle  width now: ";
   cin  >> p_rectangle->rec_width;

   p_rectangle->rec_area      = p_rectangle->rec_length * 
                                                 p_rectangle->rec_width;
   p_rectangle->rec_perimeter = 
              2.0f * (p_rectangle->rec_length + p_rectangle->rec_width);

   return;
}

//**********************************************************************
//*         Draw a rectangle base on the length and the width          *
//**********************************************************************
void draw_rectangle(float rec_length, float rec_width)
{
   int int_length,
       int_width,
       rec_rows,
       rec_colomns;

   // Check the capability to drawing
   if (rec_length < MIN_REC_LENGTH || rec_width < MIN_REC_WIDTH)
   {   
      cout << "\n\nA "  << rec_length       << " by " 
           << rec_width << " rectangle is too small to draw.";
      cout << "\nIt must be at least size " << MIN_REC_LENGTH 
           << " by "    << MIN_REC_WIDTH    << "(length by width)."; 
   }
   else
   {
      // Convert the length and the width to an integer data type
      int_length = (int) (SCALE_FACTOR * rec_length);
      int_width  = (int) rec_width;

      // Print the title of rectangle's picture
      cout << "\n\nHere is a picture of your rectangle:";
      cout << "\n";

      // Print the top row of the rectangle
      for(rec_colomns = 0; rec_colomns < int_length; rec_colomns++)
         cout << REC_BORDER;

      // Print the middle row of the rectangle
      for(rec_rows = 0; rec_rows < (int_width - 2); rec_rows++)
      {
         cout << "\n" << REC_BORDER;
         for (rec_colomns = 0; rec_colomns < (int_length - 2);
                                                          rec_colomns++)
            cout << REC_CENTER;
         cout << REC_BORDER;
      }

      // Print the bottom row of the rectangle
      if (int_width >= 2)
      {
         cout << "\n";
         for(rec_colomns = 0; rec_colomns < int_length; rec_colomns++)
            cout << REC_BORDER;
      }
   }

   return;
}

//**********************************************************************
//*             Print the specifications of the rectangle              *
//**********************************************************************
void print_specification(struct REC_STRUCTURE rectangle)
{
   cout << "\n\n\nThe rectangle specifications are:";
   cout << "\n        Length = " << rectangle.rec_length    << " units";
   cout << "\n         Width = " << rectangle.rec_width     << " units";
   cout << "\n          Area = " << rectangle.rec_area      
        << " sq.units";
   cout << "\n     Perimeter = " << rectangle.rec_perimeter << " units";

   return;
}