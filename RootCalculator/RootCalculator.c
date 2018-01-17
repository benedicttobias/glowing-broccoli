/******************************************************************************
 CLASS INFORMATION
 -----------------
   Program Name: program06 - Calculates the root of an equation
   Programmer:   Benedict Tobias
   Instructor:   Mr. Geary for CS 214-2, C Programming
   Date Due:     3/23/10

 PLEDGE STATEMENT
 ---------------- 
   I pledge that all of the code in this program is my own _original_ work for 
   the spring 2010 semester. None of the code in this program has been copied 
   from anyone or anyplace unless I was specifically authorized to do so by my
   CS 214 instructor. This program has been created using properly licensed 
   software.
                                     Signed: ________________________________

 DOCUMENTATION
 -------------
   This program calculates an equation from the user using quadratic formula
   and displays the results.
 ******************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void  displayInstructions(void);
void  getVariable(float *variableA, float *variableB, float *variableC);
float calculateDiscriminate(float variableA, float variableB, float variableC);
int   checkAvailability(float variableA, float variableB, float variableC,
                        float discriminate);
void  displayEquation(float variableA, float variableB, float variableC);
void  calculateOneRoot(float variableC, float variableB);
void  calculateTwoRoots(float variableA, float variableB, float discriminate);
void  calculateEquation(int availability, float variableA, float variableB, 
                        float variableC, float discriminate);

int main (void)
{
   float discriminate,
         variableA,
         variableB,
         variableC;
   int   availability;

   displayInstructions();
   getVariable(&variableA, &variableB, &variableC);

   discriminate = calculateDiscriminate(variableA, variableB, variableC);
   availability = checkAvailability(variableA, variableB, variableC, discriminate);

   displayEquation(variableA, variableB, variableC);
   calculateEquation(availability, variableA, variableB, variableC,
                     discriminate);   
 
   system("PAUSE");
   return 0;
}
/******************************************************************************
 Displays the instruction of the program
*******************************************************************************/
void displayInstructions(void)
{
   printf("This program calculates the root of an equation using quadratic");
   printf("formula.\n");
   printf("Please enter the value of the variable based on the format below.\n\n");
   printf("                       ax² + bx + c                                \n");
}

/******************************************************************************
 Check the availability of an equation to use quadratic formula
*******************************************************************************/
int checkAvailability(float variableA, float variableB, float variableC, 
                      float discriminate)
{
   if (variableA == 0 && variableB == 0)
      return 1;
   if (variableA == 0)
      return 2;
   if (discriminate < 0)
      return 3; 
   
   return 4;
}

/******************************************************************************
 Prompt the user to get three variable values
*******************************************************************************/
void  getVariable(float *variableA, float *variableB, float *variableC)
{
   printf("Variable a > ");
   scanf("%f", variableA);

   printf("Variable b > ");
   scanf("%f", variableB);

   printf("Variable c > ");
   scanf("%f", variableC);
}

/******************************************************************************
 Calculates the discriminate from the variables
*******************************************************************************/
float calculateDiscriminate(float variableA, float variableB, float variableC)
{
   return (variableB * variableB) - (4 * variableA * variableC);
}

/******************************************************************************
 Displays the equation from the user input
*******************************************************************************/
void  displayEquation(float variableA, float variableB, float variableC)
{
   printf("\nThe result of %.2fx² + %.2fx + %.2f:\n", 
            variableA, variableB, variableC);
}

/******************************************************************************
 Calculates equation when highest degree is zero
*******************************************************************************/
void calculateOneRoot(float variableC, float variableB)
{
   printf("There is one root only.");
   printf(" X = %.2f.\n", - variableC / variableB);
}

/******************************************************************************
 Calculates equation with quadratic formula
*******************************************************************************/
void calculateTwoRoots(float variableA, float variableB, float discriminate)
{
   printf("First root is %.2f and ", 
         (-variableB + sqrtf(discriminate)) / (2 * variableA));
   printf("second root is %.2f.\n", 
         (-variableB - sqrtf(discriminate)) / (2 * variableA));
}

/******************************************************************************
 Calculates equation with quadratic formula based on availability
*******************************************************************************/
void  calculateEquation(int availability, float variableA, float variableB, 
                        float variableC, float discriminate)
{
   switch (availability)
   {
      case 1:  printf("There is no solution.\n");
               break;    
      case 2:  calculateOneRoot(variableC, variableB);
               break;
      case 3:  printf("There are no real roots\n");
               break;
      case 4:  calculateTwoRoots(variableA, variableB, discriminate);
               break;
      default: printf("ERROR");
               break;
   }
}
