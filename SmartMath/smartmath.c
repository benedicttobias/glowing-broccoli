/*******************************************************
*          S M A R T   M A T H   P R O G R A M         *
********************************************************
     Benedict Tobias - 113878 - March 21st, 2009
*******************************************************/

#include <stdio.h>
#include <stdlib.h>

float searchy (int fungsi1[20], int fungsi2[20]);
float searchx (int fungsi1[20], int fungsi2[20]);

int main ()
{
   /*****************************************
   *H O U S E K E E P I N G   S E C T I O N *
   *****************************************/
   
   float x = 0;
   float y = 0;
   int function1[20];
   int function2[20]; 
   
   /****************************************
   *  I N P U T   A L L   V A R I A B L E  *
   ****************************************/
   printf("\nEnter the 1's function with this template : ax + by = c\n");
   printf("a = ");
   scanf(" %d", &function1[0]);
   printf("b = ");
   scanf(" %d", &function1[1]);
   printf("c = ");
   scanf(" %d", &function1[2]);

   printf("Enter the 2's function with this template : ax + by = c\n");
   printf("a = ");
   scanf(" %d", &function2[0]);
   printf("b = ");
   scanf(" %d", &function2[1]);
   printf("c = ");
   scanf(" %d", &function2[2]);
   /**********************************************
   *   P R I N T   T H E   F U N C T I O N S     *
   ***********************************************/
   printf("\nFunctions Are :  %dx + %dy = %d \n\t\t %dx + %dy = %d\n", function1[0], function1[1], function1[2], function2[0], function2[1], function2[2]);
   
   /*************************************************************************
   * C A L C U L A T E   S E C T I O N   C A L L  A N D   P R I N T   I T   *
   *************************************************************************/
   x = searchx(function1, function2);
   y = searchy(function1, function2);
   printf("\n\n(X,Y) = (%.2f,%.2f)\n\n",x ,y );
   if ( x == 0 && y == 0 )
   printf("\nFunction is Imposibble");

   system("PAUSE");
   return 0;
}

   /**********************************************
   *   C A L C U L A T E   V A R I A B L E  X    *
   ***********************************************/
float searchx (int fungsi1[20], int fungsi2[20])
{
   float x = 0;
   int y = 0;
   int multiplyresult_1 = 0;
   int multiplyresult_x = 0;
   int multiplyresult_c = 0;
   
   fungsi1[10] = fungsi1[1];
   fungsi2[10] = fungsi2[1];
   
   
   fungsi1[0] = fungsi1[0] * fungsi2[10];
   fungsi1[1] = fungsi1[1] * fungsi2[10];
   fungsi1[2] = fungsi1[2] * fungsi2[10];
   fungsi2[0] = fungsi2[0] * fungsi1[10];
   fungsi2[1] = fungsi2[1] * fungsi1[10];
   fungsi2[2] = fungsi2[2] * fungsi1[10];


   printf("\nMultiply with both coeficient for search the X\n");
   printf("Now the functions are :  %dx + %dy = %d \n\t\t\t %dx + %dy = %d\n", fungsi1[0], fungsi1[1], fungsi1[2], fungsi2[0], fungsi2[1], fungsi2[2]);

   printf("%dx - %dx = %dx\n",fungsi1[0], fungsi2[0], fungsi1[0] - fungsi2[0]);
   printf("%d - %d = %d\n",fungsi1[2], fungsi2[2], fungsi1[2] - fungsi2[2]);

   multiplyresult_1 = fungsi1[0] - fungsi2[0];
   multiplyresult_c = fungsi1[2] - fungsi2[2];

   printf("X = %d / %d\n", multiplyresult_c, multiplyresult_1);   
   x = multiplyresult_c / multiplyresult_1;
   printf("X = %f\n\n", x);
   return x;

}
   /**********************************************
   *    C A L C U L A T E   V A R I A B L E  Y   *
   ***********************************************/
float searchy (int fungsi1[20], int fungsi2[20])
{
   
   float y = 0;
   int multiplyresult_1 = 0;
   int multiplyresult_x = 0;
   int multiplyresult_c = 0;
   
   fungsi1[10] = fungsi1[0];
   fungsi2[10] = fungsi2[0];
   
   
   fungsi1[0] = fungsi1[0] * fungsi2[10];
   fungsi1[1] = fungsi1[1] * fungsi2[10];
   fungsi1[2] = fungsi1[2] * fungsi2[10];
   fungsi2[0] = fungsi2[0] * fungsi1[10];
   fungsi2[1] = fungsi2[1] * fungsi1[10];
   fungsi2[2] = fungsi2[2] * fungsi1[10];


   printf("\nMultiply with both coeficient for search the Y from the previous function\n");
   printf("Now the functions are :  %dx + %dy = %d \n\t\t\t %dx + %dy = %d\n", fungsi1[0], fungsi1[1], fungsi1[2], fungsi2[0], fungsi2[1], fungsi2[2]);
   
   printf("%dx - %dx = %dx\n",fungsi1[1], fungsi2[1], fungsi1[1] - fungsi2[1]);
   printf("%d - %d = %d\n",fungsi1[2], fungsi2[2], fungsi1[2] - fungsi2[2]);

   multiplyresult_1 = fungsi1[1] - fungsi2[1];
   multiplyresult_c = fungsi1[2] - fungsi2[2];

   printf("Y = %d / %d\n", multiplyresult_c, multiplyresult_1);
   y = multiplyresult_c / multiplyresult_1;
   printf("Y = %f", y);
   return y;
 
}
