/**********************************************************************/
/*                                                                    */
/* Program Name: program2 - Miscellaneous Operation for Two Whole     */
/*                          Numbers                                   */
/* Author:       Benedict Tobias                                      */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: September 19, 2010                                   */
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
/* This program asks the user to choose one of four operation options */ 
/* from the menu to operate two whole numbers. After the result       */
/* displayed, the menu will prompt to the user again until the user   */
/* choose to quit.                                                    */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* exit                                           */
#include <math.h>   /* pow                                            */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227"  /* PCC assigned course number      */
#define PROGRAM_NUMBER	  2        /* Teacher assigned program number */ 
#define PROGRAMMER_NAME   "Tobias" /* The programmer last name        */
#define MIN_MENU_CHOICE   1        /* Minimum user's menu choice      */
#define MAX_MENU_CHOICE   5        /* Maximum user's menu choice      */
#define MENU_CHOICE_ERROR 1        /* Menu choice error               */
#define QUIT              MAX_MENU_CHOICE
                                   /* Program exit value              */
  
/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the program heading for the user                          */
void print_menu();
   /* Print the menu operation for the user                           */
int get_menu_choice();
   /* Get one choice from the user                                    */
void get_two_numbers(int *p_first_number, int *p_second_number); 
   /* Get two whole numbers from the user to be used in operation     */
int sum_two_numbers(int first_number, int second_number);
   /* Calculate sum two whole numbers                                 */
float raise_power(int first_number, int second_number);
   /* Raise first number to the power of the second number            */
int sum_inclusive(int first_number, int second_number);
   /* Calculate sum between two whole numbers inclusively             */
void do_ascending_order(int *p_first_number, int *p_second_number);
   /* Sort two whole numbers into ascending order                     */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int first_number,  /* User's first number                          */
       menu_choice,   /* User's menu choice                           */
       second_number; /* User's second number                         */

   /* Print the heading of the program                                */
   printf("\n\n\n\n\n");
   print_heading();

   /* Loop processing two whole numbers until the user choose to quit */
   while (print_menu(), (menu_choice = get_menu_choice()) != QUIT)
   {
      /* Get two whole numbers from the user                          */
      get_two_numbers(&first_number, &second_number);
      
      /* Process the operation based on the user's choice             */
      switch (menu_choice)
      {
         /* Operate menu choice number 1                              */
         case 1:   
            printf("The sum of %d and %d is %d",
               first_number, second_number, 
               sum_two_numbers(first_number, second_number));
            break;        
         /* Operate menu choice number 2                              */   
         case 2:   
            printf("%d raised to the power of %d = %1.6e.",
               first_number, second_number, 
               raise_power(first_number, second_number));
            break;
         /* Operate menu choice number 3                              */
         case 3:
            printf("The sum of the numbers between %d and %d ",
               first_number, second_number);

            do_ascending_order(&first_number, &second_number);
            printf("(inclusive) is %d",
               sum_inclusive(first_number, second_number));
            break;        
         /* Operate menu choice number 4                              */   
         case 4:
            printf("%d and %d ", first_number, second_number);
            if (first_number > second_number)
            { 
               do_ascending_order(&first_number, &second_number);
               printf("properly ordered are %d and %d", first_number,
                  second_number);
            }
            else
               printf("are already in order");
            break;         
         /* Error handling when aborted                               */ 
         default: 
            printf("\nError occurred in main function.");
            printf("\nThe reason is imposible menu choice.");
            printf("\nThe program is now aborting.");
            exit  (MENU_CHOICE_ERROR);
            break;
      }
   }

   /* Print a goodbye message and terminate the program               */
   printf("\n\nThank you for processing numbers.");
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
   printf("\n   Miscellaneous operations on your two whole numbers   ");
   printf("\n--------------------------------------------------------");
   
   return;
}

/**********************************************************************/
/*                      Print the operation menu                      */
/**********************************************************************/
void print_menu()
{
   printf("\n\nMake the selection from the following menu:");
   printf("\n---------------------------------------------");
   printf("\n   1 - Add two whole numbers");
   printf("\n   2 - Raise the 1st number to the power of the 2nd");
   printf("\n   3 - Sum all two numbers between two whole numbers");
   printf("\n   4 - Put two whole numbers into ascending order");
   printf("\n   5 - Quit");
   printf("\n\n");
   
   return;
}

/**********************************************************************/
/*                 Get the menu choice from the user                  */
/**********************************************************************/
int get_menu_choice()
{
   int menu_choice; /* User's menu choice                             */

   do
   {
      printf("Please enter your menu selection (1-5): ");
      scanf ("%d", &menu_choice);
   }
   while (menu_choice < MIN_MENU_CHOICE || 
          menu_choice > MAX_MENU_CHOICE);

   return menu_choice;
}

/**********************************************************************/
/*                 Get two whole numbers from the user                */
/**********************************************************************/
void get_two_numbers(int *p_first_number, int *p_second_number) 
{
   printf("\nPlease enter any two whole numbers");
   printf("\n    Please enter the first number:");
   scanf ("%d", p_first_number);

   printf("    Please enter the second number:");
   scanf ("%d", p_second_number);

   return;
}

/**********************************************************************/
/*                       Sum two whole numbers                        */
/**********************************************************************/
int sum_two_numbers(int first_number, int second_number)
{
   return (first_number + second_number);
}

/**********************************************************************/
/*            Raise the 1st number to the power of the 2nd            */
/**********************************************************************/
float raise_power(int first_number, int second_number)
{  
   return (float) pow((double) first_number, (double) second_number);
}

/**********************************************************************/
/*             Sum between two whole numbers inclusively              */
/**********************************************************************/
int sum_inclusive(int first_number, int second_number)
{
   int counter,       /* Loop counter                                 */
       range_sum = 0; /* Total sum between two whole numbers          */

   for (counter = first_number; counter <= second_number; counter++)
      range_sum += counter; 	

   return range_sum;
}

/**********************************************************************/
/*           Sort two whole numbers into the ascending order          */
/**********************************************************************/
void do_ascending_order(int *p_first_number, int *p_second_number)
{
   int buffer; /* Temporary buffer                                    */

   if (*p_first_number > *p_second_number)
   {
      buffer           = *p_first_number;
      *p_first_number  = *p_second_number;
      *p_second_number = buffer;
   }

   return;
}
