// Draw Box 2
// Benedict Tobias

/******************************************************************
*                    D R A W   B O X  2                           *
******************************************************************/

#include <stdio.h>


int main()
{
   int *p_iv,
       iv,
       jv = 0;

   iv = 5;
   
   p_iv = &iv;

   printf("\nBEFORE EXP");
   printf("\niv = %d", iv);
   printf("\np_iv = %p", p_iv);
   printf("\njv = %d", jv);

   jv = *p_iv++;

   printf("\n\n\nAFTER EXP");
   printf("\niv = %d", iv);
   printf("\np_iv = %p", p_iv);
   printf("\njv = %d\n\n", jv);

   system("PAUSE");
   return 0;
}
