/**********************************************************************/
/*                                                                    */
/* Program Name: program4 - Customer Account Receivable Database      */
/* Author:       Benedict Tobias                                      */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 16, 2010                                     */
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
/* The program gets the customer last name, amount owed, and priority */
/* then print the data in alphabetical order table format with        */
/* cleaned, title cased of customer lastname.                         */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */
#include <stdlib.h> /* exit                                           */
#include <string.h> /* memcpy, strcmp                                 */
#include <ctype.h>  /* isalpha, tolower, toupper                      */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER        "CS227"  /* PCC assigned course number   */ 
#define DATABASE_ALLOC_ERROR 1        /* Data memory allocation error */
#define END_OF_STRING        '\0'     /* End of string character      */ 
#define MAX_CUSTOMER         100      /* Max record quantity          */
#define MAX_NAME_LENGTH      20       /* Max customer last name       */
                                      /*    length                    */  
#define MIN_CUSTOMER         2        /* Min record quantity          */
#define NEW_LINE             '\n'     /* New line character           */  
#define PROGRAM_NUMBER	     4        /* Teacher assigned program     */
                                      /*    number                    */          
#define PROGRAMMER_NAME      "Tobias" /* The programmer's last name   */
#define QUIT                 0        /* Program quit value           */

/**********************************************************************/
/*                         Program Structures                         */
/**********************************************************************/
/* The specifications of a customer account receivable database       */
struct customer
{
   char  last_name[MAX_NAME_LENGTH + 1]; /* The customer's last name  */
   float customer_amount;                /* The owed amount           */
   int   customer_priority;              /* The customer's priority   */
};

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the heading                                               */
void print_instructions();
   /* Print the instructions                                          */
int get_quantity();
   /* Get the amount of the customer                                  */
void get_structure_value(struct customer *p_database, int quantity);   
   /* Get the last name, owed amount, and priority of each customer   */
void clean_name(struct customer *p_database, int quantity);
   /* Clean the name into the title case and throw away number        */
   /*    characther                                                   */
void sort_customer(struct customer *p_database, int quantity);
   /* Sort the customer database into alphabetical order last name    */
void print_customer_database(struct customer *p_database, int quantity);
   /* Print the customer database in table format                     */


/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   int             quantity;    /* The customer quantity              */
   struct customer *p_database; /* Points to the customer database    */
   
   /* Print the heading                                               */
   printf("\n\n\n\n\n");
   print_heading();

   /* Loop processing customer database until the user says to quit   */
   while(print_instructions(), (quantity = get_quantity()) != QUIT)
   {
      /* Allocate memory for customer database and abort if there is  */
      /* not enough memory to allocate database memory                */ 
      if ((p_database = (struct customer *)
                        malloc(sizeof(*p_database) * quantity)) == NULL)
      {
         printf("\nError number %d occurred in main().",
            DATABASE_ALLOC_ERROR);
         printf("\nUnable to allocate memory for the database.");
         printf("\nThe program is aborting.");
         exit  (DATABASE_ALLOC_ERROR);
      }

      /* Get the customer database, and clean each last name with     */
      /* title case, sort the customer database in alphabetical       */
      /* order, and print the customer data in table format           */
      get_structure_value    (p_database, quantity);
      clean_name             (p_database, quantity);
      sort_customer          (p_database, quantity);
      print_customer_database(p_database, quantity);
   
      /* Print the footer of the table                                */
      printf("\n\n******* End Of Customer Database Processing *******");

      /* Release the memory allocated to the customer database        */
      free (p_database);    
   }

   /* Print a goodbye message and terminate the program               */
   printf("\n\nThank you for processing data. 8-o");
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
   printf("\n\nThis program allows you to input customers which owe");
   printf("\nyou money (your accounts receivable), and manage these");
   printf("\naccounts in a database.  You will enter the following:");
   printf("\n   Customer last name (1-%d characters)", MAX_NAME_LENGTH);
   printf("\n   Amount the customer owes (to the exact cent)");
   printf("\n   Customer priority (1=VIP, 2=Important, 3=Regular)");
   printf("\nFrom %d to %d customers may be processed.", MIN_CUSTOMER,
      MAX_CUSTOMER);

   return;
}

/**********************************************************************/
/*                 Get the amount of customer values                  */
/**********************************************************************/
int get_quantity()
{
   int quantity; /* The customer record amount                        */

   printf("\n\nGet the customers for the database");
   printf("\n--------------------------------------------------");

   do
   {
      printf("\nHow many customers do you have (%d to %d, %d=quit): ",
         MIN_CUSTOMER, MAX_CUSTOMER, QUIT);
      scanf ("%d", &quantity);
   }
   while (!(quantity >= MIN_CUSTOMER && quantity <= MAX_CUSTOMER) &&
                                                      quantity != QUIT); 
   
   return quantity;
}

/**********************************************************************/
/*    Get the last name, amount owed, and priority of the customer    */
/**********************************************************************/
void get_structure_value(struct customer *p_database, int quantity); 
{
   struct customer *p_structure; /* Points to every customer record   */
              char *p_last_name; /* Points to every customer          */
                                 /*    last name character            */

   for (p_structure = p_database; (p_structure - p_database) < quantity;
                                                          p_structure++)
   {
      printf("\nCustomer number %d", (p_structure - p_database) + 1);
      printf("\n   Enter the customer's last name: ");   
      getchar();

      p_last_name = p_structure->last_name;      
      do
      {
         *p_last_name++ = getchar();
      }
      while (*(p_last_name - 1) != NEW_LINE);
      *(--p_last_name) = END_OF_STRING; 

      printf("   Enter the amount owed: ");
      scanf ("%f", &p_structure->customer_amount);

      do
      {
         printf("   Enter the customer's priority (1-3): ");
         scanf ("%d", &p_structure->customer_priority); 
      }
      while (p_structure->customer_priority < 1 ||
                                    p_structure->customer_priority > 3);
   } 
   
   return;        
}

/**********************************************************************/
/*      Clean the name into title case and throw away any number      */
/**********************************************************************/
void clean_name(struct customer *p_database, int quantity)
{
   struct customer *p_structure; /* Points to every customer record   */
   char *p_fast,                 /* Points to every last name 
                                 /*    characther   */
        *p_slow;                 /* Points to every cleaned name 
                                 /*    character */

   for (p_structure = p_database; (p_structure - p_database) < quantity;
                                                          p_structure++)
   {
      p_fast = p_slow = p_structure->last_name;
      while (*p_fast != END_OF_STRING)
      {
         if (isalpha(*p_fast))
            *p_slow++ = tolower(*p_fast);
         p_fast++;      
      }
      *p_slow = END_OF_STRING;

      *p_structure->last_name = toupper(*p_structure->last_name);
   }
   
   return;
}

/**********************************************************************/
/*        Sort the customer with alphabetical order last name         */
/**********************************************************************/
void sort_customer(struct customer *p_database, int quantity)
{
   struct customer *p_inner,  /* Points initially to the second       */
                              /*    customer record                   */
                   *p_outer,  /* Points initially to the first        */
                              /*    customer record                   */
                   temporary; /* Points to the temporary customer     */
                              /*    record                            */ 

   for (p_outer = p_database; (p_outer - p_database + 1) < quantity;
                                                              p_outer++)
   {
      for (p_inner = p_outer + 1; (p_inner - p_database) < quantity;
                                                              p_inner++)
         if (strcmp(p_outer->last_name, p_inner->last_name) > 0)
         {
            temporary = *p_outer;
            *p_outer  = *p_inner; 
            *p_inner  = temporary;
         }
   }

   return;
}

/**********************************************************************/
/*            Print the customer database in table format             */
/**********************************************************************/
void print_customer_database(struct customer *p_database, int quantity)
{
   struct customer *p_structure; /* Points to every customer record   */

   printf("\n  Here is the accounts receivable customer database");
   printf("\n=====================================================");
   printf("\n   Customer Name         Amount        Priority");
   printf("\n--------------------    ---------    -------------");
   
   for (p_structure = p_database; (p_structure - p_database) < quantity;
                                                               p_down++)
   {
      printf("\n%20s    $%8.2f    %d ", p_structure->last_name, 
         p_structure->customer_amount, p_structure->customer_priority);      
      switch (p_structure->customer_priority)
      {
         case 1:
            printf("(VIP)");
            break;
         case 2:
            printf("(Regular)");
            break;
         case 3:
            printf("(Important)");
            break;
      }
   }
   
   return;
}
