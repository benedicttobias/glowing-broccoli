// Calculate the circle

#include<stdio.h>
#include<stdlib.h>
#define PI 3.1416

float calculateCircleArea ( int rad );
float calculateCircleCirc ( int rad );

int main (void)
{
   char  status;
   int   radius;

   do
   {
      system("cls");

      printf("Enter the radius of a circle: ");
      scanf("%d", &radius);

      printf("\n\nRESULT: \n");
      printf("Radius        : %11d  \n", radius);
      printf("Circumference : %11.3f\n", calculateCircleCirc ( radius ));
      printf("Area          : %11.3f\n", calculateCircleArea ( radius ));

      printf("\nRestart the program? Y/N : ");
      scanf(" %c", &status);
   }
   while ( status == 'y' || status == 'Y' );

   return 0;
}

float calculateCircleArea ( int rad )
{
   float area = PI * rad  * rad;
   return area;
}

float calculateCircleCirc ( int rad )
{
   float circ = 2  * PI   * rad;
   return circ;
}
