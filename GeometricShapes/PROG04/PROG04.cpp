//**********************************************************************
//*                                                                    *
//* Program Name: PROG04 - Manages The Straight-sided Geometric Shapes *
//* Author:       Ben Tobias                                           *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: March 3, 2011                                        *
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
//* This program manages straight-sided geometric shapes. This program *
//* creates the right triangle,the square, and the rectangle with      *
//* defined dimensions, calculate and print its specifications.        *
//*                                                                    *
//**********************************************************************

#include "stdafx.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME      "Object-Oriented Programming and Design"
                         // PCC assigned course name
#define COURSE_NUMBER    "CS246" 
                         // PCC assigned course number
#define PROGRAM_NUMBER   4 
                         // Teacher assigned program number
#define RECT_ALLOC_ERR   3 
                         // Unable to allocate memory for the rectangle
#define RT_ALLOC_ERR     1 
                         // Unable to allocate memory for right triangle
#define SQUARE_ALLOC_ERR 2 
                         // Unable to allocate memory for the square

//**********************************************************************
//*                         Class Definitions                          *
//**********************************************************************
//**********************************************************************
//*                             Base Class                             *
//**********************************************************************
// The base of the geometry shape
class geometry_shape
{
   int   total_sides,     // The total sides of a shape
         unique_sides;    // The number of unique sides of a shape
   float shape_area,      // The area of a shape in units
         shape_perimeter; // The perimeter of a shape in units
public:
   // Virtual function to show the specifications of the shape
   virtual void show_specifications()        {};

   // Set the member variable 
   void  set_total_sides           (int t_s) {total_sides     = t_s;}
   void  set_unique_sides          (int u_s) {unique_sides    = u_s;}
   void  set_shape_area            (float a) {shape_area      = a;}
   void  set_shape_perimeter       (float p) {shape_perimeter = p;}

   // Get the member variable
   int   get_total_sides           ()        {return total_sides;}
   int   get_unique_sides          ()        {return unique_sides;}
   float get_shape_area            ()        {return shape_area;}
   float get_shape_perimeter       ()        {return shape_perimeter;}

   // Handle the fatal error that might occurred
   void  fatal_error               (char *p_shape_name,
                                    int error_number);
};

//**********************************************************************
//*                          Derived Classes                           *
//**********************************************************************
// Defines a right triangle
class right_triangle: public geometry_shape
{
   char  *p_shape_name; // Points to the name of the right triangle
   float base,          // The base of a right triangle in units
         height,        // The height of a right triangle in units
         hypotenuse;    // The hypotenuse of a right triangle in units
public:
   // Constructor and destructor
        right_triangle     (char *p_shape, float b, float h);
        ~right_triangle    () {free(p_shape_name);}

   // Show the specifications of a right triangle
   void show_specifications();
};

// Defines a square
class square: public geometry_shape
{
   char  *p_shape_name; // Points to the name of the square
   float side;          // The side of the square in units
public:
   // Constructor and destructor
        square             (char *p_shape, float s);
        ~square            () {free(p_shape_name);}

   // Show the specifications of the square
   void show_specifications();
};

// Defines a rectangle 
class rectangle: public geometry_shape
{
   char  *p_shape_name; // Points to the name of the rectangle
   float base,          // The base of the rectangle in units
         height;        // The height of the rectangle in units
public:
   // Constructor and destructor
        rectangle          (char *p_shape, float b, float h);
        ~rectangle         () {free(p_shape_name);}

   // Show the specifications of the rectangle
   void show_specifications();
};

//**********************************************************************
//*                        Base class definition                       *
//**********************************************************************
// Handle the fatal error that might occurred
void geometry_shape::fatal_error(char *p_function_name,
                                 int  error_number)
{
   cout << "\nError #"         << error_number
        << " occurred in the " << p_function_name
        << " function.";
   cout << "\nUnable to allocate memory for the shape name.";
   cout << "\nThe program is aborting.";
   exit(error_number);
}

//**********************************************************************
//*                      Derived class definition                      *
//**********************************************************************
// Construct the right triangle
right_triangle::right_triangle(char *p_shape, float b, float h)
{
   cout << "\n\n\nCreating right triangle shape \"" << p_shape
        << "\"";
   cout << "\n     with base = "                    << b
        << " and height = "                         << h;

   if((p_shape_name = (char *) malloc(strlen(p_shape) + 1)) == NULL)
   {
      fatal_error("right triangle constructor", RT_ALLOC_ERR);
   }
   else
   {
      strcpy_s(p_shape_name, strlen(p_shape) + 1, p_shape);
      base       = b;
      height     = h;
      hypotenuse = sqrt((base * base) + (height * height));
      set_total_sides    (3);
      set_unique_sides   (3);
      set_shape_area     (0.5f * base * height);
      set_shape_perimeter(base + height + hypotenuse);
   }
}

// Show the specifications of the right triangle
void right_triangle::show_specifications()
{
   cout << "\n\n\nThe specifications of a right triangle shape are:";
   cout << "\n-------------------------------------------------";
   cout << "\nName of the shape:         \"" << p_shape_name 
        << "\"";
   cout << "\nTotal number of sides:     "   << get_total_sides();
   cout << "\nNumber of unique sides:    "   << get_unique_sides(); 
   cout << "\nLength of base:            "   << base;
   cout << "\nLength of height:          "   << height;
   cout << "\nLength of hypotenuse:      "   << hypotenuse;
   cout << "\nArea:                      "   << get_shape_area();
   cout << "\nPerimeter:                 "   << get_shape_perimeter();

   return;
}

// Construct a square 
square::square(char *p_shape, float s)
{
   cout << "\nCreating square shape \"" << p_shape
        << "\"";
   cout << "\n     with side = "        << s;

   if((p_shape_name = (char *) malloc(strlen(p_shape) + 1)) == NULL)
   {
      fatal_error("square constructor", SQUARE_ALLOC_ERR);
   }
   else
   {
      strcpy_s(p_shape_name, strlen(p_shape) + 1, p_shape);
      side = s;
      set_total_sides    (4);
      set_unique_sides   (1);
      set_shape_area     (side * side);
      set_shape_perimeter(4.0f * side);
   }
}

// Show the specifications of the square
void square::show_specifications()
{
   cout << "\n\n\nThe specifications of a square shape are:";
   cout << "\n-----------------------------------------";
   cout << "\nName of the shape:         \"" << p_shape_name 
        << "\"";
   cout << "\nTotal number of sides:     "   << get_total_sides();
   cout << "\nNumber of unique sides:    "   << get_unique_sides(); 
   cout << "\nLength of a side:          "   << side;
   cout << "\nArea:                      "   << get_shape_area();
   cout << "\nPerimeter:                 "   << get_shape_perimeter();

   return;
}
   
// Construct the rectangle
rectangle::rectangle(char *p_shape, float b, float h)
{
   cout << "\nCreating rectangle shape \"" << p_shape
        << "\"";
   cout << "\n     with base = "           << b
        << " and height = "                << h;

   if((p_shape_name = (char *) malloc(strlen(p_shape) + 1)) == NULL)
   {
      fatal_error("rectangle constructor", RECT_ALLOC_ERR);
   }
   else
   {
      strcpy_s(p_shape_name, strlen(p_shape) + 1, p_shape);
      base   = b;
      height = h;
      set_total_sides    (4);
      set_unique_sides   (2);
      set_shape_area     (base * height);
      set_shape_perimeter(2.0f * (base + height));
   }
}

// Show the specifications of the rectangle
void rectangle::show_specifications()
{
   cout << "\n\n\nThe specifications of a rectangle shape are:";
   cout << "\n--------------------------------------------";
   cout << "\nName of the shape:         \"" << p_shape_name 
        << "\"";
   cout << "\nTotal number of sides:     "   << get_total_sides();
   cout << "\nNumber of unique sides:    "   << get_unique_sides();
   cout << "\nLength of base:            "   << base;
   cout << "\nLength of height:          "   << height;
   cout << "\nArea:                      "   << get_shape_area();
   cout << "\nPerimeter:                 "   << get_shape_perimeter();

   return;
}
   
//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   geometry_shape *p_geometry_shape; // Points to every geometry shape

   // Print the program heading
   print_heading();

   // Create the three object of geometry shape
   right_triangle rt_triangle("RIGHT-TRIANGLE-1", 5.99f,  11.99f);
   square         square     ("SQUARE-1"        , 11.99f);
   rectangle      rectangle  ("RECTANGLE-1"     , 11.99f, 5.99f);

   // Print the right triangle, square, and rectangle specifications
   p_geometry_shape = &rt_triangle;
   p_geometry_shape->show_specifications();
   p_geometry_shape = &square;
   p_geometry_shape->show_specifications();
   p_geometry_shape = &rectangle;
   p_geometry_shape->show_specifications();

   // Print a goodbye message and terminate the program
   cout << "\n\n\nThanks for shaping things up today!";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                     Print the program heading                      *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n" << COURSE_NUMBER 
        << ' '            << COURSE_NAME
        << " - Program "  << PROGRAM_NUMBER;
   cout << "\n\n The specifications of straight-sided geometric shapes";
   cout << "\n =====================================================";

   return;
}