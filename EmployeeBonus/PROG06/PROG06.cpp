//**********************************************************************
//*                                                                    *
//* Program Name: PROG06 - XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX *
//* Author:       Ben Tobias                                           *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: March 31, 2011                                       *
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
//* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX *
//* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX *
//* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX *
//* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX *
//*                                                                    *
//**********************************************************************

#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <new>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME        "Object-Oriented Programming and Design"
                                   // PCC assigned course name
#define COURSE_NUMBER      "CS246" // PCC assigned course number
#define PROGRAM_NUMBER     6       // Teacher assigned program number
#define MAX_NAME_LENGTH    80      // Maximum length of company name
#define ERROR_COMPANY_NAME 1       // Can't alloc the company name
#define ERROR_EMP_NAME     2       // Can't alloc the employee name
#define ERROR_EMP_DATABASE 3       // Can't alloc the employee database

//**********************************************************************
//*                         Program Structure                          *
//**********************************************************************
// The company information
struct company
{
   char  *p_company_name;  // Points to the company name
   int   number_employee,  // The number of employees in the company
         year_given_bonus; // The year of the bonuses given
   float year_bonus;       // The yearly amount of bonus
};

//**********************************************************************
//*                           Program Class                            *
//**********************************************************************
// Employee bonus record
class employee
{
   int   employee_id,  // The employee Id number
         year_hired,   // The year of the employee hired 
         year_service; // The number of service years of employee
   float bonus_amount; // The employee bonus total amount
public:
   // Set the member variables
   void  set_employee_id   (int ei)   {employee_id  = ei;}
   void  set_year_hired    (int yh)   {year_hired   = yh;}
   void  set_year_service  (int ys)   {year_service = ys;}
   void  set_bonus_amount  (float ba) {bonus_amount = ba;}

   // Get the member variables
   int   get_employee_id   ()         {return employee_id;}
   int   get_year_hired    ()         {return year_hired;}
   int   get_year_service  ()         {return year_service;}
   float get_bonus_amount  ()         {return bonus_amount;}
   
   // Destructor
         ~employee         ()         {cout << "\n\nDestructor executing ...";}
};

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_instructions();
   // Print the program instructions
company *get_company_information();
   // Get the company information and return its company
employee *get_employee_database(company *p_company_information);
   // Get the employee records and return its record
void print_employee(employee *p_employee_database, int number_employee, 
                                                    char *p_table_name);
   // Print the employee database in table form
void sort_employee(employee *p_employee_database, int number_employee);
   // Sort the employee database by year hired into ascending order 
void fatal_error(int error_number, char *p_function_name, 
                                                   char *p_memory_type);
   // Handle the error that occurred in particular function

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   company  *p_company_information; // Points to the company information
   employee *p_employee_database;   // Points to the employee database

   // Print the instructions
   print_instructions();

   // Get and print the company information
   p_company_information = get_company_information();
   cout << "\n\nCompany name:        " 
                             << p_company_information->p_company_name;
   cout << "\nYear of the bonuses: "   
                             << p_company_information->year_given_bonus;
   cout << "\nNumber of employees: "   
                             << p_company_information->number_employee;
   cout << "\nBonus per year:      $"  
                             << p_company_information->year_bonus;

   // Get the employee database
   p_employee_database = get_employee_database(p_company_information);

   // Print the unsorted employee database in table form
   print_employee(p_employee_database, 
           p_company_information->number_employee, "IN UNSORTED ORDER");

   // Sort and print the employee database in table form
   sort_employee(p_employee_database, 
                                p_company_information->number_employee);
   print_employee(p_employee_database, 
        p_company_information->number_employee, "SORTED BY YEAR HIRED");

   // Free all the memory that had been allocated
   delete [] p_employee_database;
   delete    p_company_information;

   // Say goodbye and terminate the program
   cout << "\n\n\nThanks for processing employee bonuses today :)";
   return 0;
}

//**********************************************************************
//*                   Print the program instructions                   *
//**********************************************************************
void print_instructions()
{
   cout << "\n\n\n\n\n\n" << COURSE_NUMBER 
        << ' '            << COURSE_NAME
        << " - Program "  << PROGRAM_NUMBER;
   cout << "\n"
        << "========================================================";
   cout << "\nThis program asks for information about your company and";
   cout << "\nabout each employee. It then calculates the bonus amount";
   cout << "\nowed each employee based on the number of service years.";
   
   return;
}


//**********************************************************************
//*         Get the company information and return its company         *
//**********************************************************************
company *get_company_information()
{
   company *p_company_information; // Points to the company information
   char    company_name[MAX_NAME_LENGTH + 1];
                                   // The name of the company

   // Try to allocate memory for the company information
   try
   {
      p_company_information = new company;
   }
   catch (bad_alloc xa)
   {
      fatal_error (ERROR_COMPANY_NAME, "get_company_information", 
                                                 "company information");
   }

   // Read the company name 
   cout << "\n\n\nEnter the name of your company here (no spaces): ";
   cin  >> company_name;
   try
   {
      p_company_information->p_company_name = 
                                     new char[strlen(company_name) + 1];
      strcpy_s(p_company_information->p_company_name, 
                                strlen(company_name) + 1, company_name);
   }
   catch (bad_alloc xa)
   {
      fatal_error (ERROR_EMP_NAME, "get_company_information", 
                                                        "company name");
   }

   // Get the number of employees
   do
   {
      cout << "Enter your number of employees (1 or more): ";
      cin  >> p_company_information->number_employee;
   
      if (p_company_information->number_employee < 1)
         cout << "     The number of employees must be 1 or more";
   }
   while (p_company_information->number_employee < 1);

   // Get the year in which the bonuses are given
   cout << "Enter the year in which the bonuses are given (YYYY): ";
   cin  >> p_company_information->year_given_bonus;

   // Get the yearly bonuses amount
   cout << "Give the yearly bonus amount per employee (in dollars): ";
   cin  >> p_company_information->year_bonus;

   // Return it
   return p_company_information;

}

//**********************************************************************
//*           Get the employee records and return its record           *
//**********************************************************************
employee *get_employee_database(company *p_company_information)
{
   int      id_number = 1,   // The Id number of the employee
            year_service;    // The number of service years of employee
   employee *p_employee_database,
                             // Points to the employee database
            *p_start_database;    
                             // Points to the start of employee database

   // Try to allocate the memory for the employee database
   try
   {
      p_employee_database = 
                   new employee[p_company_information->number_employee];
      p_start_database = p_employee_database;
   }
   catch (bad_alloc xa)
   {
      fatal_error (ERROR_EMP_DATABASE, "get_employee_database", 
                                                   "employee database");
   }

   // Get the employee records
   cout << "\n\n";
   do
   {
      // Get the valid number of service years of employee
      do
      {
         cout << "\nEnter the number of service years of employee #" 
                                                            << id_number
              << '.';
         cout << "\nEnter 0 (zero) if this employee does not exist: ";
         cin  >> year_service;

         if (year_service < 0)
         {
            cout << "   The service years must be 0 or greater.";
            cout << "\n   Please reenter the number of service years.";
         }
      }
      while (year_service < 0);

      // Built the employee bonuses record
      if (year_service > 0)
      {
         p_employee_database->set_year_service(year_service);
         p_employee_database->set_employee_id(id_number);
         p_employee_database->set_year_hired
                              (p_company_information->year_given_bonus -
                               p_employee_database->get_year_service());
         p_employee_database->set_bonus_amount(
                       (float) p_employee_database->get_year_service() * 
                                     p_company_information->year_bonus);
         p_employee_database += 1;
      }

      id_number += 1;

   }
   while ((p_employee_database - p_start_database) <
                                p_company_information->number_employee);

   // Return the employee database
   return p_start_database;
}

//**********************************************************************
//*             Print the employee database in table form              *
//**********************************************************************
void print_employee(employee *p_employee_database, int number_employee,
                                                     char *p_table_name)
{
   employee *p_employee; // Points to every employee records

   cout << "\n\nHere is the employee database, " << p_table_name << ':';
   cout << "\n====================================================";
   cout << "\nEmployee Id   Service Years   Year Hired   Bonus Amt";
   cout << "\n-----------   -------------   ----------   ---------";
   for (p_employee = p_employee_database; 
                                    (p_employee - p_employee_database) <
                                          number_employee; p_employee++)
   {
      cout << "\n     "        << p_employee->get_employee_id ()
           << "              " << p_employee->get_year_service()
           << "            "   << p_employee->get_year_hired  ()
           << "        $"      << p_employee->get_bonus_amount();
   }

   return;
}
//**********************************************************************
//*   Sort the employee database by year hired into ascending order    *
//**********************************************************************
void sort_employee(employee *p_employee_start, int number_employee)
{
   employee *p_inner,           // Points to every employee records
            *p_outer,           // Points to initially employee records
            temporary_employee; // Temporary employee for the swap

   for (p_outer = p_employee_start; 
                     (p_outer - p_employee_start) < number_employee - 1;
                                                              p_outer++)
      for (p_inner = p_employee_start; 
                     (p_inner - p_employee_start) < number_employee - 1;
                                                              p_inner++)
         if (p_inner->get_year_hired() > 
                                        (p_inner + 1)->get_year_hired())
         {
            temporary_employee = *p_inner;
            *p_inner           = *(p_inner + 1); 
            *(p_inner + 1)     = temporary_employee;
         }

   return;
}

//**********************************************************************
//*       Handle the error that occurred in particular function        *
//**********************************************************************
void fatal_error(int error_number, char *p_function_name, 
                                                    char *p_memory_type)
{
   cout << "\nError #"                            << error_number
        << " occurred in the "                    << p_function_name
        << " function.";
   cout << "\nUnable to allocate memory for the " << p_memory_type;
   cout << "\nThe program is aborting.";
   exit(error_number);
}