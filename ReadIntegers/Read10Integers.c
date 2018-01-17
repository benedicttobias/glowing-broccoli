/*

Reads 10 integers from the user and display in certain (see below) format

This program reads 10 integers and prints the first and the last on one line,
the second and the ninth on the next line, the third and the seventh on the next line,
and so forth.
*/

#include<stdio.h>
#include<stdlib.h>

int main (void)
{

   /* Declaring variable */
   int firstNumber,
       secondNumber,
       thirdNumber,
       forthNumber,
       fifthNumber,
       sixthNumber,
       seventhNumber,
       eighthNumber,
       ninthNumber,
       tenthNumber;

   /* Prompt and read 10 integers from the user */
   printf("Please enter 10 numbers: \n");
   scanf("%d %d %d %d %d %d %d %d %d %d",
      &firstNumber, &secondNumber, &thirdNumber, &forthNumber, &fifthNumber,
      &sixthNumber, &seventhNumber, &eighthNumber, &ninthNumber, &tenthNumber);

   /* Display numbers 1st-10th, 2nd-9th, 3rd-8th,... 5th-6th format */
   printf("\n\nYour numbers are: \n");
   printf("%5d %2d\n", firstNumber, tenthNumber);
   printf("%5d %2d\n", secondNumber, ninthNumber);
   printf("%5d %2d\n", thirdNumber, eighthNumber);
   printf("%5d %2d\n", forthNumber, seventhNumber);
   printf("%5d %2d\n", fifthNumber, sixthNumber);

   system("PAUSE");
   return 0;

}
