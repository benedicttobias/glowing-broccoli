/**********************************************************************/
/*                                                                    */
/* Program Name: program7 - Demonstrates Various Search Algorithms    */
/* Author:       Benedict Tobias                                      */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 13, 2010                                    */
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
/* This program demonstrates various search algorithms. The user 	    */
/* enters a whole number and the program will search it using these   */
/* following search algorithms: the ordered sequential search, the    */
/* probability search, and the binary search. The progress of each    */
/* search will be shown so the efficiency of each search algorithms   */ 
/* can be compared.                                                   */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* printf, scanf                                  */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define ARRAY_SIZE	   15		   /* Array size of data                */
#define COURSE_NUMBER   "CS227"  /* PCC assigned course number        */
#define MAX_INDEX       ARRAY_SIZE - 1
                                 /* The last index of array           */
#define PROGRAM_NUMBER	7        /* Teacher assigned program number   */
#define PROGRAMMER_NAME "Tobias" /* The programmer's last name        */
#define QUIT		      0	      /* Program quit value	             */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the heading                                               */
void print_instructions();
   /* Print the instructions                                          */
void fill_array(int array[], int last_index);
   /* Fill an array with data										             */
void show_array(int array[], int last_index, int search_target);
   /* Show the content of the array						                   */
void print_result(int search_result, int array_index);
   /* Print the result of the search			                         */
int seq_search(int array[], int last_index, int search_target, 
													         int *p_target_location);
   /* The ordered sequential search						                   */
int prb_search(int array[], int last_index, int search_target,
													         int *p_target_location);
   /* The probability search                               			    */
int bin_search(int array[], int last_index, int search_target,
													         int *p_target_location);
   /* The binary search 											             */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
	int bin_array[ARRAY_SIZE], /* Binary search data			          */
		 prb_array[ARRAY_SIZE], /* Probability search data			       */
		 seq_array[ARRAY_SIZE], /* Ordered sequential search data       */
		 search_target,         /* The target from the user    	       */
       target_location;       /* Index of the found target            */
		 	
	/* Print the program heading and instructions                      */
	printf("\n\n\n\n\n\n");
	print_heading();
	print_instructions();
	
	/* Fill the three array with data								          */
	fill_array(seq_array, MAX_INDEX);
	fill_array(prb_array, MAX_INDEX);
	fill_array(bin_array, MAX_INDEX);
	
	/* Loop processing target until the user says to quit              */
	while (printf("\n\n\nEnter an integer search target (%d to quit): ",
              QUIT), scanf("%d", &search_target), search_target != QUIT)
	{
      /* Ordered sequential search									          */
      printf("\n\nOrdered Sequential Search:");
      show_array(seq_array, MAX_INDEX, search_target);
      if (seq_search(seq_array, MAX_INDEX, search_target, 
                                                      &target_location))
         print_result('S', target_location);
      else
         print_result('U', target_location);

      /* Probability search											          */
      printf("\n\nProbability Search:");
      show_array(prb_array, MAX_INDEX, search_target);
      if (prb_search(prb_array, MAX_INDEX, search_target, 
                                                      &target_location))
         print_result('S', target_location);
      else
         print_result('U', target_location);	

      /* Binary search												             */
      printf("\n\nBinary Search:");
      show_array(bin_array, MAX_INDEX, search_target);
      if (bin_search(bin_array, MAX_INDEX, search_target, 
                                                      &target_location))
         print_result('S', target_location);
      else
         print_result('U', target_location);	
   }

   /* Print a goodbye message and terminate the program               */
   printf("\nThanks for searching.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
	
	return 0;
}

/**********************************************************************/
/*                     Print the program heading                      */
/**********************************************************************/
void print_heading()
{
   printf("\n======================================================");
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        PROGRAMMER_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   
   return;
}

/**********************************************************************/
/*                   Print the program instructions                   */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program demonstrates various search algorithms.");
   printf("\nYou enter in any whole number, and the program will");
   printf("\nsearch for it in an ORDERED array of whole numbers");
   printf("\nusing each of the following search algorithms:");
   printf("\n     1. Ordered Sequential Search");
   printf("\n     2. Probability Search");
   printf("\n     3. Binary Search");
   printf("\nThe progress of each search is shown so the efficiency");
   printf("\nof the search algorithms can be compared.");

   return;
}

/**********************************************************************/
/*                     Fill the array with data                       */
/**********************************************************************/
void fill_array(int array[], int last_index)
{
	int array_index; /* Index of every whole numbers   			       */
	
	for (array_index = 0; array_index <= last_index; array_index++)
	   array[array_index] = (array_index * 5) + 10;
		
	return;		
}

/**********************************************************************/
/*                   Show the content of the array                    */
/**********************************************************************/
void show_array(int array[], int last_index, int search_target)
{
   int array_index; /* Index of every whole numbers   			       */

   printf("\n   Array Index: ");
   for (array_index = 0; array_index <= last_index; array_index++)
      printf("[%2d]", array_index);

   printf("\n    Array Data:");
   for (array_index = 0; array_index <= last_index; array_index++)
      printf("  %2d", array[array_index]);

   printf("\n   User Target:  %2d", search_target);

   return;
}

/**********************************************************************/
/*                   Print the result of the search                   */
/**********************************************************************/
void print_result(int search_result, int array_index)
{
   printf("\nSearch Outcome: ");
   switch (search_result)
   {
      case 'U':
         printf("Unsuccessful - target not found");
         break;
      case 'S':
         printf("Successful - target found at index [%2d]",
            array_index);
			break;
      default:
         printf("Undetermined");
         break;
   }

   return;
}

/**********************************************************************/
/*                    The ordered sequential search                   */
/**********************************************************************/
int seq_search(int array[], int last_index, int search_target, 
                                                 int *p_target_location)
{   
   int array_index = 0; /* Index of every whole numbers               */

   printf("\n   Search Path: ");
   if (search_target <= array[last_index])
   {
      while (printf("[%2d]", array_index),
                                     array[array_index] < search_target)
         array_index++;
      *p_target_location = array_index;
   }
   else
   {
      printf("[%2d]", last_index);
      array_index = last_index; 
   }
       
   return search_target == array[array_index];
}

/**********************************************************************/
/*                       The probability search                       */
/**********************************************************************/
int prb_search(int array[], int last_index, int search_target, 
                                                 int *p_target_location)
{
   int array_index = 0, /* Index of every whole numbers data          */
       temporary;       /* Temporary whole number for the swap 	    */

   printf("\n   Search Path: ");
   while (printf("[%2d]", array_index), 
        array_index < last_index && search_target != array[array_index])
      array_index++;
	
   if (search_target == array[array_index])
   {  
	   if (search_target != array[0])
      {
         temporary              = array[array_index];
         array[array_index]     = array[array_index - 1];
         array[array_index - 1] = temporary;  

         array_index--;
	   }    
		
	   *p_target_location = array_index;
   } 

   return search_target == array[array_index];
}

/**********************************************************************/
/*                          The binary search                         */
/**********************************************************************/
int bin_search(int array[], int last_index, int search_target, 
                                                 int *p_target_location)
{
   int first_index = 0, /* Initially index of the first data		    */
       middle_index;    /* Middle index between first index and last  */
                        /*    index                                   */

   printf("\n   Search Path: ");
   while (first_index <= last_index)
   {
      middle_index = (first_index + last_index) / 2;
      printf("[%2d]", middle_index);

      if (search_target > array[middle_index])
         first_index = middle_index + 1;
      else 
      {
         if (search_target < array[middle_index])
            last_index  = middle_index - 1;
         else
            first_index = last_index + 1;   
      }        
   }

   *p_target_location = middle_index;

   return search_target == array[middle_index];
}
