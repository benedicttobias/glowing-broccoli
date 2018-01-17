/******************************************************************************
 CLASS INFORMATION
 -----------------
   Program Name: program08 - The loan payment program
   Programmer:   Benedict Tobias
   Instructor:   Mr. Halsey for CS 214-2, C Programming
   Date Due:     4/6/2010

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
   This program calculates the loan payment table. The user will provide the data
   such as principal, interest per year, and number of years. The results of 
   calculation will be display.
 ******************************************************************************/

#include <stdio.h>
#include <math.h>

void  displayInstructions(void);
void  getUserData(float *principal, float *interestPerYear, int *numberOfYears);
float calculateMonthlyPayment(float principal, float interestPerYear,
                              int numberOfYears);
void  printAmortizationTable(float principal, float interestPerYear, 
                             int numberOfYear, float monthlyPayment);
void  printMonthlyDetails(float principal, float interestPerYear, int numberOfYear, 
                          float monthlyPayment);

int main(void)
{
   float interestPerYear,
         monthlyPayment,
         principal;       
   int   numberOfYear;
         
   displayInstructions();
   getUserData(&principal, &interestPerYear, &numberOfYear);   
   
   monthlyPayment = calculateMonthlyPayment(principal, interestPerYear,
                    numberOfYear);
   monthlyPayment = ceilf(monthlyPayment * 100) / 100;

   printAmortizationTable(principal, interestPerYear, numberOfYear, monthlyPayment);
   printMonthlyDetails(principal, interestPerYear, numberOfYear, monthlyPayment);

   system("PAUSE");
   return 0;
}

/******************************************************************************
 Displays the instruction of the program.
*******************************************************************************/
void displayInstructions(void)
{
   printf("\n\nWELCOME TO THE LOAN PAYMENT PROGRAM\n");
   printf("This program calculates the monthly payment for loans.\n\n");

   return;
}

/******************************************************************************
 Gets the principal, interest per year, and number of year from the user.
*******************************************************************************/
void getUserData(float *principal, float *interestPerYear, int *numberOfYear)
{
   printf("Please enter the amount of the loan (principal) > ");
   scanf("%f", principal);
   printf("Please enter the interest rate per year (percent). 0-100 > ");
   scanf("%f", interestPerYear);
   printf("Please enter the number of years > ");
   scanf("%d", numberOfYear);

   return;
}

/******************************************************************************
 Displays the heading of the payment table.
*******************************************************************************/
void printAmortizationTable(float principal, float interestPerYear, 
                            int numberOfYear, float monthlyPayment)
{
   printf("The amount of the loan (principle): $%.2f\n", principal);
   printf("Interest of the year              : %.2f%%\n", interestPerYear);
   printf("Interest of the month             : %.6f%%\n", 
      (interestPerYear / 12) / 100);
   printf("Number of years                   : %d\n", numberOfYear);
   printf("Number of month                   : %d\n", numberOfYear * 12);
   printf("Monthly payment                   : %.2f\n\n", monthlyPayment);

   return;
}

/******************************************************************************
 Calculates the monthly payment.
*******************************************************************************/
float calculateMonthlyPayment(float principal,  float interestPerYear, 
                              int numberOfYears)
{
   float interestPerMonth,
         p,
         q;
   int   numberOfMonth;

   interestPerMonth = (interestPerYear / 12) / 100;
   numberOfMonth    = numberOfYears * 12; 
   p                = pow((1 + interestPerMonth), numberOfMonth);
   q                = p / (p - 1);      
   
   return (principal * interestPerMonth * q);
}

/******************************************************************************
 Displays the monthly payment details.
*******************************************************************************/
void printMonthlyDetails(float principal, float interestPerYear, int numberOfYear,
                         float monthlyPayment)
{
   int   monthCounter = 1;                 
   float interestPaid, 
         interestPerMonth,
         principalPaid, 
         totalAmountPaid = 0;
   
   interestPerMonth = (interestPerYear / 12) / 100;
     
   printf("            Old     Monthly  Interest Principal    New\n");
   printf("Month     Balance   Payment    Paid     Paid     Balance\n");
   
   do
   {
      interestPaid   = interestPerMonth * principal;
      principalPaid  = monthlyPayment - interestPaid;
      monthlyPayment = interestPaid + principalPaid; 
          
      printf("%5d %11.2f %9.2f %8.2f %8.2f %10.2f\n", monthCounter, principal, 
         monthlyPayment, interestPaid, principalPaid, principal - principalPaid);
   
      principal -= principalPaid;   
      totalAmountPaid += monthlyPayment;
      monthCounter++;
   }
   while(principal > monthlyPayment);

   interestPaid   = interestPerMonth * principal;
   principalPaid  = principal;
   monthlyPayment = interestPaid + principalPaid;
   
   printf("%5d %11.2f %9.2f %8.2f %8.2f %10.2f\n", monthCounter, principal, 
      monthlyPayment, interestPaid, principalPaid, principal - principalPaid);

   totalAmountPaid += monthlyPayment;
   printf("\nTotal amount paid: %.2f\n", totalAmountPaid);  
   
   return;
}
