//**********************************************************************
//*                                                                    *
//* Program Name: PROG03 - Draw a Picture of a Rectangle and Print The *
//*                        Rectangle Specifications                    *
//* Author:       Ben Tobias                                           *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS 246, Object-Oriented Programming and Design       *
//* Date Written: March 1, 2011                                        *
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
//* The program asks the user for the length and width of a rectangle, *
//* calculates the area and perimeter, draws the picture of the        *
//* rectangle, and prints its specifications.                          *
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
#define PROGRAM_NUMBER 3       // Teacher assigned program number
#define REC_BORDER     '*'     // Rectangle border character
#define REC_CENTER     ' '     // Rectangle center character
#define SCALE_FACTOR   1.5f    // Scale factor for rectangle length

//**********************************************************************
//*                         Class Definitions                          *
//**********************************************************************
// Defines the specifications of a rectangle
class rectangle
{
   float rec_area,      // Area of the rectangle (L x W) in square units
         rec_length,    // Length of the rectangle in units
         rec_perimeter, // Perimeter of the rectangle (2L + 2W) in units
         rec_width;     // Width of the rectangle in units
public:
   // Constructor that assign the length and the width to member 
   // variables and destructor that print the destructor line
        rectangle          (float user_length, float user_width);
        ~rectangle         ();

   // Draw a rectangle base on the length and the width
   void draw_rectangle     ();

   // Show the specifications of the rectangle
   void show_specifications();
};

//**********************************************************************
//*        Assign the length and the width to member variables         *
//**********************************************************************
rectangle::rectangle(float user_length, float user_width)
{
   rec_length    = user_length;
   rec_width     = user_width;
   rec_area      = user_length * user_width;
   rec_perimeter = 2.0f * (user_length + user_width);
}

//**********************************************************************
//*                Print the destructor line execution                 *
//**********************************************************************
rectangle::~rectangle()
{
   cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
}

//**********************************************************************
//*  Draw a picture of a rectangle based on the length and the width   *
//**********************************************************************
void rectangle::draw_rectangle()
{
   int columns,    // Columns counter of rectangle picture
       int_length, // Integer length of the rectangle for drawing
       int_width,  // Integer width of the rectangle for drawing
       rows;       // Rows counter of rectangle picture
       

   // Check the capability to drawing a rectangle on the screen
   if (rec_length < MIN_REC_LENGTH || rec_width < MIN_REC_WIDTH)
   {   
      cout << "\n\nA "                      << rec_length        
           << " by "                        << rec_width 
           << " rectangle is too small to draw.";
      cout << "\nIt must be at least size " << MIN_REC_LENGTH 
           << " by "                        << MIN_REC_WIDTH    
           << " (length by width)."; 
   }
   else
   {
      // Convert the length and the width to an integer
      int_length = (int) (SCALE_FACTOR * rec_length);
      int_width  = (int) rec_width;

      // Print the title of rectangle's picture
      cout << "\n\nHere is a picture of your rectangle:";
      
      // Print the top row of the rectangle
      cout << "\n";
      for(columns = 1; columns <= int_length; columns++)
         cout << REC_BORDER;

      // Print the middle rows of the rectangle
      for(rows = 1; rows <= (int_width - 2); rows++)
      {
         cout << "\n" << REC_BORDER;
         for (columns = 1; columns <= (int_length - 2); columns++)                                             
            cout << REC_CENTER;
         cout << REC_BORDER;
      }

      // Print the bottom row of the rectangle
      if (int_width >= 2)
      {
         cout << "\n";
         for(columns = 1; columns <= int_length; columns++)
            cout << REC_BORDER;
      }
   }

   return;
}

//**********************************************************************
//*             Print the specifications of the rectangle              *
//**********************************************************************
void rectangle::show_specifications()
{
   cout << "\n\n\nThe rectangle specifications are:";
   cout << "\n        Length = " << rec_length    << " units";
   cout << "\n         Width = " << rec_width     << " units";
   cout << "\n          Area = " << rec_area      << " sq. units";       
   cout << "\n     Perimeter = " << rec_perimeter << " units";

   return;
}

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading   
void get_dimensions(float *p_user_length, float *p_user_width);
   // Get the dimensions (length and width) of a rectangle

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   float user_length, // The length of the rectangle in units
         user_width;  // The width of the rectangle in units

   // Print the program heading 
   print_heading();

   // Get the dimensions (length and width) of a rectangle
   get_dimensions(&user_length, &user_width); 

   // Create a rectangle object that holds dimensions from the user
   rectangle user_rectangle(user_length, user_width);

   // Draw the rectangle and show the its specifications
   user_rectangle.draw_rectangle     ();
   user_rectangle.show_specifications();

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
   cout << "\n\n\n\n\n\n            " << COURSE_NUMBER 
        << ' '                        << COURSE_NAME
        << " - Program "              << PROGRAM_NUMBER;
   cout << "\n\n                     This program draws a rectangle";
   cout << "\n                     ==============================";

   return;
}

//**********************************************************************
//*        Get the dimensions (length and width) of a rectangle        *
//**********************************************************************
void get_dimensions(float *p_user_length, float *p_user_width)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> *p_user_length;
   cout << "Enter the rectangle width here: ";
   cin  >> *p_user_width;

   return;
}

