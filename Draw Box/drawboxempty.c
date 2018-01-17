// Draw Box Empty
// Benedict Tobias
// 2009.2.April. 14.26

/******************************************************************
*                    D R A W   B O X  E M P T Y                   *
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

void opening();
void input(int *a, int *b, int *c);
void drawbox(int a, int b, int c);

/******************************************************************
*                    M A I N   P R O G R A M                      *
******************************************************************/
int main()
{
   int height;
   int width;
   int times;

   opening();

   input(&height, &width, &times);

   drawbox(height, width, times);

   return 0;
}

/******************************************************************
*             O P E N I N G   S E C T I O N   P R I N T           *
******************************************************************/
void opening()
{
   system("cls");
   printf("\t\t\tSIMPLE PROGRAM TO DRAW AN EMPTY BOX\n"
          "\t\t\t===================================\n"
          "\t\t\t          P C C   2 0 0 9        \n\n" );
}

/******************************************************************
*                     I N P U T   S E C T I O N                   *
******************************************************************/
void input(int *a, int *b, int *c)
{
   printf("Enter the height : ");
   scanf( " %d", a);

   printf("Enter the width : ");
   scanf( " %d", b);

   printf("how many times it will draw the box : ");
   scanf( " %d", c);
}

/******************************************************************
*                   D R A W  B O X  S E C T I O N                 *
******************************************************************/
void drawbox(int a, int b, int c)
{
   int row;
   int colom;
   int times;

   printf("\n");
   for (times = 0; times < c; times++)
      {
         /**********************************
         *  P R I N T  S T A R T   R O W   *
         **********************************/
         for (colom = 0; colom < b; colom++)
            {
               printf("*");
            }
         printf("\n");

         /**********************************
         *  P R I N T  S I D E   R O W     *
         **********************************/

         for (row = 0; row < (a - 2); row++)
            {
               printf("*");
               for (colom = 0; colom < (b-2); colom++)
               {
                  printf(" ");
               }
               printf("*\n");
            }

         /**********************************
         *  P R I N T   E N D   R O W      *
         **********************************/
         for (colom = 0; colom < b; colom++)
            {
               printf("*");
            }
         printf("\n\n");
      }
   system("PAUSE");
}
