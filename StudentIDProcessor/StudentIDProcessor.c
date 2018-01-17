/**********************************************************************/
/*                                                                    */
/* Program Name: program6 - Maintain Student by Their Id Number	      */
/* Author:       Benedict Tobias                                      */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 27, 2010                                    */
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
/* This program maintains the list of students by the their id 		  */
/* number. After enters the id number it sort into the ascending      */
/* order and removes all the duplicates.		                 	  */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   	"CS227" /* PCC assigned course number     */
#define HEADER_ALLOC_ERROR 	1		/* Header allocation error		  */
#define LIST_HEADER     	MINIMUM_ID - 1
									/* Lowest possible student ID	  */
#define LIST_TRAILER    	MAXIMUM_ID + 1
									/*	Highest possible student ID   */
#define MAXIMUM_ID			999999  /* Maximum student ID   		  */
#define MINIMUM_ID      	1		/* Minimum student ID			  */
#define PROGRAM_NUMBER		6       /* Teacher assigned program number*/
#define PROGRAMMER_NAME 	"Tobias" 
								    /* The programmer's last name     */
#define STUDENT_ALLOC_ERROR 3		/* Student allocation error	      */
#define TRAILER_ALLOC_ERROR 2		/* Trailer allocation error       */
#define QUIT		    	0	    /* Program quit value	          */

/**********************************************************************/
/*                         Program Structures                         */
/**********************************************************************/
/* Linked list student 										          */
struct student
{
   int            student_id;      /* Id of the student				  */
   struct student *p_next_student; /* Points to the next student	  */
};
typedef struct student STUDENT;

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Print the heading                                               */
void print_instructions();
   /* Print the instructions                                          */
char get_response();
   /* Get the user response to either continue or quit                */
STUDENT *create_list();
   /* Create an empty linked student with students header and trailer */
void insert_student_id(STUDENT *p_student_list, int student_id);
   /* Insert a new student next to the list header					  */
void print_list(STUDENT *p_student_list);
   /* Print all students from a list								  */
int count_list(STUDENT *p_student_list);
   /* Count number of students in the list		    				  */
void sort_ascending(STUDENT *p_student_list);
   /* Sort the list into the ascending order						  */
void remove_duplicates(STUDENT *p_student_list);
   /* Remove the duplicates student id in the list					  */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
   STUDENT *p_student_list, /* Points to the student linked list	  */
		   *p_temporary;    /* Temporary student for release		  */
   int 	    student_id;     /* Id number of the new student           */
   	
   /* Print the program heading and instructions                      */
   print_heading();

   /* Loop processing students until the user says to quit 		 	  */
   while (print_instructions(), get_response() == 'y')
   {
	   /* Create a new linked list with student header and trailer    */
	   p_student_list = create_list();
		
	   /* Loop processing student id until the users says to quit	  */
	   while (printf("Enter the next student id(%d to quit):", QUIT),
					 scanf("%d", &student_id), student_id > LIST_HEADER)
	   {
	      if (student_id > LIST_TRAILER)
		     printf("    Id rejected - it cannot exceed %d\n", MAXIMUM_ID);
		  else
		     insert_student_id(p_student_list, student_id);
	   }
		
	   /* Print the student list									  */	
	   printf("\nThe unsorted student id list, as entered, is:");
	   print_list(p_student_list);
	   printf("\nThe length of the unsorted student id list is: %d",
	      count_list(p_student_list));
		
	   /* Sort the student list and print it                          */	
	   printf("\n\nThe student id list, sorted ascending by id, is:");
	   sort_ascending(p_student_list);
	   print_list(p_student_list);
	   printf("\nThe length of the sorted student id list is: %d",
	      count_list(p_student_list));
		
	   /* Remove all the duplicates and print it					  */	
	   printf("\n\nThe student id list, with duplicate id's removed,");
	   printf(" sorted ascending by id, is:");
	   remove_duplicates(p_student_list);
       print_list(p_student_list);
	   printf("\nThe length of the unsorted student id list is: %d",
	      count_list(p_student_list));
		  
	   /* Release the student linked list							  */
	   while (p_student_list != NULL)
       {
	      p_temporary = p_student_list->p_next_student;
	      printf("\nFreeing list address %p", p_student_list);
	      free(p_student_list);
	      p_student_list = p_temporary;
       }
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
   printf("\n\n\n\n\n\n");
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
   printf("\n\n    This program maintains a list of students by their");
   printf("\n    id number.  After entry of all id's, it sorts them");
   printf("\n    into ascending order, then removes all duplicates.");

   return;
}

/**********************************************************************/
/*      Get response if the user want to process a range or not       */
/**********************************************************************/
char get_response()
{
   char response[2]; /* User's response to either continue or quit    */
   
   do
   {
      printf("\n\nDo you want to process another range (y or n): ");
      scanf ("%1s", response);
      response[0] = tolower(response[0]);
   }
   while (response[0] != 'y' && response[0] != 'n');

   return response[0];   
}

/**********************************************************************/
/*                     Fill the array with data                       */
/**********************************************************************/
STUDENT *create_list()
{
   STUDENT *p_student_list;
   
   if ((p_student_list = (STUDENT *) malloc(sizeof(STUDENT))) == NULL)								
   {
       printf("\nError number %d occurred in main().",
          HEADER_ALLOC_ERROR);
       printf("\nUnable to allocate memory for the student header.");
       printf("\nThe program is aborting.");
       exit  (HEADER_ALLOC_ERROR);
   }
   p_student_list->student_id = LIST_HEADER;
   
   if ((p_student_list->p_next_student = 
						   (STUDENT *) malloc(sizeof(STUDENT))) == NULL)							
   {
       printf("\nError number %d occurred in main().",
          TRAILER_ALLOC_ERROR);
       printf("\nUnable to allocate memory for the student trailer.");
       printf("\nThe program is aborting.");
	   exit  (TRAILER_ALLOC_ERROR);
   }
   p_student_list->p_next_student->student_id = LIST_TRAILER;
   p_student_list->p_next_student->p_next_student = NULL;
   
   return p_student_list;
}

/**********************************************************************/
/*                     Fill the array with data                       */
/**********************************************************************/
void insert_student_id(STUDENT *p_student_list, int student_id)
{
   STUDENT *p_new_student;
	
   if ((p_new_student = (STUDENT *) malloc(sizeof(STUDENT))) == NULL)								
   {   
       printf("\nError number %d occurred in main().",
          STUDENT_ALLOC_ERROR);
       printf("\nUnable to allocate memory for the new student.");
       printf("\nThe program is aborting.");
       exit  (STUDENT_ALLOC_ERROR);
   }
   p_new_student->student_id 	  = student_id;
   p_new_student->p_next_student  = p_student_list->p_next_student;
   p_student_list->p_next_student = p_new_student;
	
   return;
}

/**********************************************************************/
/*                     Fill the array with data                       */
/**********************************************************************/
void print_list(STUDENT *p_student_list)
{
   if (p_student_list->p_next_student->p_next_student == NULL)
      printf("\nEMPTY LIST!");
   else
   {
      while (p_student_list = p_student_list->p_next_student, 
							 p_student_list->student_id != LIST_TRAILER)
	     printf("\n%25d", p_student_list->student_id);
   }
	
   return;
}

/**********************************************************************/
/*                     Fill the array with data                       */
/**********************************************************************/
int count_list(STUDENT *p_student_list)
{
   int student_amount = 0; /* The students amount in the list		  */
	
   while (p_student_list = p_student_list->p_next_student, 
							 p_student_list->student_id != LIST_TRAILER)
      student_amount++;
		
   return student_amount;
}

/**********************************************************************/
/*                     Fill the array with data                       */
/**********************************************************************/
void sort_ascending(STUDENT *p_student_list)
{
   STUDENT *p_student, /* Points to each student in the list		  */
		   temporary;  /* Temporary student for the swap			  */
	int    counter;	   /* Counts thru every student in the list		  */
	
   for (counter = 0; counter < count_list(p_student_list) - 1; 
															  counter++)
   {
	   p_student = p_student_list;
	   
       while (p_student->p_next_student->p_next_student->student_id !=
														   LIST_TRAILER)
	   {
		  if (p_student->p_next_student->student_id > 
				  p_student->p_next_student->p_next_student->student_id)
		  {
		     temporary.p_next_student 				   = 
							  p_student->p_next_student->p_next_student;
			 p_student->p_next_student->p_next_student = 
			                   temporary.p_next_student->p_next_student;
			 temporary.p_next_student->p_next_student  = 
											  p_student->p_next_student;
			 p_student->p_next_student   			   = 
											   temporary.p_next_student;
		  }
		  p_student = p_student->p_next_student;
	   }
   }
   
}

/**********************************************************************/
/*                     Fill the array with data                       */
/**********************************************************************/
void remove_duplicates(STUDENT *p_student_list)
{
   STUDENT *p_current  = p_student_list->p_next_student->p_next_student, 
								   /* Points to each student    	  */
   		   *p_previous = p_student_list->p_next_student;                 
								   /* Points to previous student 	  */
								   
 		
	   while (p_current->student_id != LIST_TRAILER)
		  if(p_previous->student_id == p_current->student_id)
		  {
		     printf("\nDeleting the duplicate student id %d",
			    p_current->student_id);
			 p_previous->p_next_student = p_current->p_next_student;
			 free(p_current);
			 p_current = p_previous->p_next_student;
		  }
		  else
		  {
			 p_previous = p_current;
			 p_current  = p_current->p_next_student;
		  }  
   return;	
}
