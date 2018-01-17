/**********************************************************************/
/*                                                                    */
/* Program Name: program1 - Sum Two Numbers Inclusively               */
/* Author:       Benedict Tobias                                      */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS 227, Data Structures and Algorithms               */
/* Date Written: September 9, 2010                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge that all the lines  in this C program are my own original */
/* work and that none of the lines in this C program have been copied */
/* from anyone else, unless I was specifically authorized to do so by */
/* my CS227 instructor.                                               */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program asks the user for two numbers and will sum the first  */
/* number until the second number inclusively and will display the    */
/* result on the monitor.                                             */
/*                                                                    */
/**********************************************************************/

#include <stdio.h> /* printf, scanf                                   */

/**********************************************************************/
/*                        Symbolic Constant                           */
/**********************************************************************/
#define COURSE_NUMBER    "CS227"   /* PCC assigned course number      */
#define PROGRAM_NUMBER	 1         /* Teacher assigned program number */ 
#define PROGRAMMERS_NAME "Tobias"  /* The programmer's username       */
                                   
/**********************************************************************/
/*                       Function Prototypes                          */
/**********************************************************************/
void print_instructions();
   /* Print the program heading and instructions for the user         */
void get_two_user_value(int *p_first_value, int *p_second_value);
   /* Get two integers from the user                                  */
void calc_result(int first_value, int second_value);
   /* Sum two numbers inclusively and display the result              */

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   int first_value,     /* First user's value input                   */
       second_value;    /* Second user's value input                  */

   /* Print the program heading                                       */	
   printf("\n\n\n\n\n\n");
   print_instructions();

   /* Get two range numbers from the user                             */
   get_two_user_value(&first_value, &second_value);

   /* Calculate the sum of two numbers inclusively                    */
   calc_result(first_value, second_value);

   /* Print a goodbye message and terminate the program               */
   printf("\n\nThank you for using this program.");
   printf("\nGoodbye and have a nice day.");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_instructions()
{

   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        PROGRAMMERS_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   printf("\nThis program calculates the sum of two integers");
   printf("\n        inclusively and display the result.");
   printf("\n        -----------------------------------------       ");
   return;
}

/**********************************************************************/
/*                   Ask the user two range numbers                   */
/**********************************************************************/
void get_two_user_value(int *p_first_value, int *p_second_value)
{
   printf("\n\nLet's begin. Please give me two numbers.");

   printf("\n   Please enter a small number: ");
   scanf("%d", p_first_value);

   printf("   Then enter a large number  : ");
   scanf("%d", p_second_value);

   return;
}

/**********************************************************************/
/*              Calculate the sum of two numbers inclusively          */
/*	                     and display the result                        */
/**********************************************************************/
void calc_result(int first_value, int second_value)
{
   int counter,
       total_value = 0;

   for(counter = first_value; counter <= second_value; counter++)
      total_value += counter; 	

   printf("\nThe sum from small number until large number inclusively is %d.",
      total_value);

   return;
}
