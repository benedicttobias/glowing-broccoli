/**********************************************************************/
/*                                                                    */
/* Program Name: program3 - Process Experimental Scientific Data      */
/* Author:       Benedict Tobias                                      */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 1, 2010                                      */
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
/* This program processes experimental scientific data. The program   */
/* asks the user how many data to be process, then get the data (with */
/* negative value converted to positive), print into decending order  */
/* with duplicates noted and print the total.                         */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* exit                                           */
#include <string.h> /* memcpy                                         */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER     "CS227"  /* PCC assigned course number      */
#define PROGRAM_NUMBER	  3        /* Teacher assigned program number */ 
#define PROGRAMMER_NAME   "Tobias" /* The programmer's last name      */
#define MIN_QUANTITY      2        /* Minimum data quantity           */
#define MAX_QUANTITY      100      /* Maximum data quantity           */
#define QUIT              0        /* Program quit value              */
#define DATA_ALLOC_ERROR  1        /* Data memory allocate error      */
#define SORT_ALLOC_ERROR  2        /* Sorted data memory allocate     */
                                   /*    error                        */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the heading of the program                                */
void print_instruction();
   /* Print the instruction of the program                            */
int get_quantity();
   /* Get the scientific data quantity                                */
void get_data(float *p_data, int quantity);
   /* Get the scientific data as much as the quantity                 */
void sort_data(float *p_data, int quantity);
   /* Sort the scientific data into the decending order               */
void print_data(float *p_data, int quantity);
   /* Print the scientific data with duplicates noted                 */
float sum_data(float *p_data, int quantity);
   /* Sum all the scientific data                                     */
void print_total(float sum_result);
   /* Print the sum of the whole scientific data                      */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   float *p_data;  /* Points to the start of scientific data          */
   int   quantity; /* The quantity of the scientific data             */

   /* Print the heading of the program                                */
   printf("\n\n\n\n\n");
   print_heading();

   /* Loop processing scientific data until the user says to quit     */
   while (print_instruction(), (quantity = get_quantity()) != QUIT)
   {
      /* Allocate memory for the scientific data and abort if there   */
      /* is not enough memory to allocate                             */
      if ((p_data = 
                  (float *) malloc(sizeof(*p_data) * quantity)) == NULL)
      {
         printf("\nError number %d occured in main().",
            DATA_ALLOC_ERROR);
         printf("\nThere is not enough memory to allocate.");
         printf("\nThe program is now aborting.");
         exit  (DATA_ALLOC_ERROR);
      }

      /* Get the data with negative value converted to positive, then */ 
      /* print into the decending order with duplicates noted and     */
      /* print the total.                                             */        
      get_data   (p_data, quantity);    
      sort_data  (p_data, quantity);
      print_data (p_data, quantity);
      print_total(sum_data(p_data, quantity));

      /* Release the memory of the scientific data                    */
      free (p_data);
   }

   /* Print a goodbye message and terminate the program               */
   printf("\n\nThank you for processing data. :-D");
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
/*                   Print the program instruction                    */
/**********************************************************************/
void print_instruction()
{
   printf("\nThis program processes experimental scientific data");
   printf("\n---------------------------------------------------");

   return;
}

/**********************************************************************/
/*               Get the quantity of the scientific data              */
/**********************************************************************/
int get_quantity()
{
   int quantity; /* The scientific data quantity                      */

   do
   {
      printf("\nHow many data values are there (%d to %d, %d=quit): ",
         MIN_QUANTITY, MAX_QUANTITY, QUIT);
      scanf ("%d", &quantity);
   }
   while (!(quantity >= MIN_QUANTITY && quantity <= MAX_QUANTITY) &&
                                                      quantity != QUIT); 
   
   return quantity;
}

/**********************************************************************/
/*                Get the data as much as the quantity.               */
/*          The negative value will be converted to positive          */
/**********************************************************************/
void get_data(float *p_data, int quantity)
{
   float *p_data_down; /* Points to every scientific data             */

   for(p_data_down = p_data; (p_data_down - p_data) < quantity;
                                                          p_data_down++)
   {
      printf("    Enter data value %d: ", (p_data_down - p_data) + 1);
      scanf ("%f", p_data_down);

      if (*p_data_down < 0)
      {
         printf("        Negative %.2f converted to positive %.2f",
            *p_data_down, *p_data_down = -*p_data_down);
         printf("\n");
      }  
   }
   
   return;
}

/**********************************************************************/
/*            Sort the scientific data into decending order           */
/**********************************************************************/
void sort_data(float *p_data, int quantity)
{
   float *p_data_biggest = p_data,
                                 /* Points to the biggest data value  */
         *p_data_down,           /* Points to every data              */
         *p_data_start = p_data, /* Points to the start of the data   */
         *p_sort_down,           /* Points to every sorted data       */       
         *p_sort_start;          /* Points to the start of the sorted */
                                 /*    data                           */   

   if ((p_sort_start = 
            (float *) malloc(sizeof(*p_sort_start) * quantity)) == NULL)
   {
      printf("\nError number %d occured in sort_data().", 
         SORT_ALLOC_ERROR);
      printf("\nThere is not enough memory to allocate.");
      printf("\nThe program is now aborting.");
      exit  (SORT_ALLOC_ERROR);
   }

   for (p_sort_down = p_sort_start;
                 (p_sort_down - p_sort_start) < quantity; p_sort_down++)
   {
      *p_sort_down = 0.0f;
   
      for (p_data_down = p_data_start;
                 (p_data_down - p_data_start) < quantity; p_data_down++)
      {
         if (*p_sort_down < *p_data_down)
         {
            p_data_biggest = p_data_down;
            *p_sort_down   = *p_data_biggest;
         }
      }

      *p_data_biggest = 0.0f; 
   }

   memcpy (p_data, p_sort_start, sizeof(*p_data) * quantity); 
   free   (p_sort_start);

   return;   
}

/**********************************************************************/
/*          Print the scientific data with duplicates noted           */
/**********************************************************************/
void print_data(float *p_data, int quantity)
{
   float *p_data_down = p_data; /* Points to every scientific data    */

   printf("\nThe data in decending order (with duplicates noted):");
   printf("\n----------------------------------------------------");

   if (*p_data_down == *p_data_down) 
      printf("\n%25.2f", *p_data_down);  
   for (p_data_down = p_data + 1; (p_data_down - p_data) < quantity;
                                                          p_data_down++)
   {  
      printf("\n%25.2f", *p_data_down);
      if (*(p_data_down - 1) == *p_data_down)    
         printf(" (duplicate)");
   }
   
   return;
}

/**********************************************************************/
/*                    Sum all the scientific data                     */
/**********************************************************************/
float sum_data(float *p_data, int quantity)
{
   float *p_data_down, /* Points to every scientific data             */
         sum_result;   /* Total of scientific data                    */

   for (p_data_down = p_data; (p_data_down - p_data) < quantity;
                                                          p_data_down++)
      sum_result += *p_data_down;
   
   return sum_result;
}

/**********************************************************************/
/*                Print the sum of the scientific data                */
/**********************************************************************/
void print_total(float sum_result)
{
   printf("\n                ---------");
   printf("\n%25.2f total", sum_result);
   printf("\n\n");
   
   return;   
}
