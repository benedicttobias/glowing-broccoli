/**********************************************************************/
/*                                                                    */
/* Program Name: program5 - Recursively Sum of All Even Whole Numbers */
/*                          between Two Whole Numbers                 */
/* Author:       Benedict Tobias                                      */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 29, 2010                                     */
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
/* This program gets two whole numbers from the user and calculates   */
/* the sum of all even whole numbers between the smaller number and   */
/* the larger number recursively with print the information of        */
/* recursive action so the calculation of recursive may be observed   */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <ctype.h>  /* tolower                                        */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"  /* PCC assigned course number        */
#define PROGRAM_NUMBER	5        /* Teacher assigned program number   */       
#define PROGRAMMER_NAME "Tobias" /* The programmer's last name        */
#define MIN_RANGE       -5000    /* Minimum user's number             */
#define MAX_RANGE       5000     /* Maximum user's number             */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the heading                                               */
void print_instructions();
   /* Print the instructions                                          */
char get_response();
   /* Get the user response either continue or quit                   */
void get_range(int *p_first_number, int *p_second_number);
   /* Get a range of two whole numbers                                */
void swap_number(int *p_first_number, int *p_second_number);
   /* Swap two whole numbers                                          */
int iseven(int number);
   /* Determine if the number is even or not                          */
int sum_even(int first_number, int second_number);
   /* Recursively sum every even whole numbers in the range           */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int first_number,  /* User first number                            */
       second_number; /* User second number                           */

   /* Print the heading and the instructions                          */
   printf("\n\n\n\n\n");
   print_heading();
   print_instructions();

   /* Loop processing sum of all even whole numbers recursively       */
   /* between two whole numbers until the user says to quit           */
   while (get_response() == 'y')
   {
      /* Get the range of two whole numbers from the user             */
      get_range(&first_number, &second_number);
 
      /* Print the sum of all even whole numbers in the user range    */ 
      /* with showing each action of recursive calculation            */
      printf("\nProcessing the range %d to %d:", first_number, 
         second_number);
      if(first_number > second_number)
         swap_number(&first_number, &second_number);
      printf("\nThe sum of even number in the range %d to %d is: %d",
         first_number, second_number, 
         sum_even(first_number, second_number));   

   }

   /* Print a goodbye message and terminate the program               */
   printf("\n\nThank you for enjoying the even summing.");
   printf("\nGoodbye and have a nice day.");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        PROGRAMMER_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   
   return;
}

/**********************************************************************/
/*                   Print the program instructions                   */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program recursively calculates the sum of all");
   printf("\neven whole numbers between two numbers inclusively.");
   printf("\nYou are repeatedly asked to enter in the start and");
   printf("\nend of a range, and the sum of all even numbers in");
   printf("\nthat range is calculated and printed.  Information");
   printf("\nabout the recursive action of the function is also");
   printf("\nprinted so the recursive nature of the calculation");
   printf("\n                 may be observed.");

   return;
}

/**********************************************************************/
/*      Get response if the user want to process a range or not       */
/**********************************************************************/
char get_response()
{
   char response[2]; /* User's response                               */
   
   do
   {
      printf("\n\nDo you want to process another range (y or n): ");
      scanf ("%1s", response);
   
      response[0] = tolower(response[0]);
   }
   while (!(response[0] == 'y' || response[0] == 'n'));

   return response[0];   
}

/**********************************************************************/
/*                 Get the range of two whole numbers                 */
/**********************************************************************/
void get_range(int *p_first_number, int *p_second_number)
{
   do
   {
      printf("Enter the first number (from %d to %d): ", MIN_RANGE, 
         MAX_RANGE);
      scanf ("%d", p_first_number);
   }while (*p_first_number < MIN_RANGE || *p_first_number > MAX_RANGE);

   do
   {
      printf("Enter the last number (from %d to %d): ", MIN_RANGE,
         MAX_RANGE);
      scanf ("%d", p_second_number);
   }while (*p_second_number < MIN_RANGE || 
           *p_second_number > MAX_RANGE);

   return;
}


/**********************************************************************/
/*                       Swap two whole numbers                       */
/**********************************************************************/
void swap_number(int *p_first_number, int *p_second_number)
{
   *p_first_number  = *p_first_number + *p_second_number;
   *p_second_number = *p_first_number - *p_second_number;
   *p_first_number  = *p_first_number - *p_second_number;

   return;
}

/**********************************************************************/
/*                 Determine a number is even or not                  */
/**********************************************************************/
int iseven(int number)
{
   return !(number % 2);
}

/**********************************************************************/
/*           Sum all even whole numbers between two whole             */
/*        numbers recursively with print each recursive action        */
/**********************************************************************/
int sum_even(int first_number, int second_number)
{
   int sum = 0; /* sum of all even whole numbers in this range        */
      
   printf("\n   Entering sum function for range %d to %d", first_number,
      second_number);
   
   if (first_number <= second_number)
   {  
      if (iseven(first_number))
      {
         printf("\n     Adding: %d", first_number);
         sum = first_number + sum_even(first_number + 1, second_number);
      }
      else
      {
         printf("\n     Skipping: %d", first_number);
         sum = sum_even(first_number + 1, second_number);
      }
   }

   printf("\n   Exiting sum function for range ");
   printf("%d to %d with result: %d", first_number, second_number, sum);
      
   return sum;
}
