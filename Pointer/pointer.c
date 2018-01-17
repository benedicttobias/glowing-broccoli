#include <stdio.h>

void get_input( int *a, int *b );

int main()
{

   int height;
   int width;
   int height2;
   int width2;
   int height3;
   int width3;

   get_input(&height,&width);
   get_input(&height2, &width2);
   get_input(&height3, &width3);

   printf(" height = %d and width = %d \n", height, width);
   printf(" height2 = %d and width2 = %d \n", height2, width2);
   printf(" height3 = %d and width3 = %d \n", height3, width3);

}

void get_input( int *a, int *b )
{
   printf("Enter the height = ");
   scanf(" %d", a);

   printf("Enter the width = ");
   scanf(" %d", b);

   return;
}
