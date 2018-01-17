/******************************************************************************
 CLASS INFORMATION
 -----------------
   Program Name: program11 - Encrypt Program
   Programmer:   Benedict Tobias
   Instructor:   Mr. Halsey for CS 214-2, C Programming
   Date Due:     4/20/2010

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
   This program encrypt sentences.
 ******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FLUSH while(getchar() != '\n');

void displayInstructions(void);
int  displayMenu(void);
void openFileError(void);
void readCode(char encodeText[], char decodeText[], FILE *codeTextIn);
void getSentence(char userSentence[]);
void processCode(char userSentence[], char encodeText[], char decodeText[]);
void processDecode(char userSentence[], char encodeText[], char decodeText[]);
void displayResult(char userSentence[]);
int  displayInstructionNewCode(void);
void getNewCode(char encodeText[], char decodeText[]);
int  checkNewCode(char codeText[], char decodeText[]);
void processNewCode(char userSentence[], int newCodeOption);

int main(void)
{
   FILE *codeTextIn;

   int  userOption,
        codeStatus,
        newCodeOption;
   char encodeText[80],
        decodeText[80],
        userSentence[80];

   displayInstructions();
   userOption = displayMenu();

   while(!(userOption == 1 || userOption == 2 || userOption == 3 || userOption == 9))
   {
      printf("Invalid option!\n\n");
      userOption = displayMenu();
   }

   if (!(codeTextIn = fopen("code1.txt", "r")))
      openFileError();

   if(userOption == 1)
   {
      readCode(encodeText, decodeText, codeTextIn);    
 
      getSentence(userSentence);
      processCode(userSentence, encodeText, decodeText);
   }
   else if(userOption == 2)
   {
      readCode(encodeText, decodeText, codeTextIn);
      getSentence(userSentence);
      processDecode(userSentence, encodeText, decodeText);
   }
   else if(userOption == 3)
   {
      do
      {
         displayInstructionNewCode();
         getNewCode(encodeText, decodeText);
         codeStatus = checkNewCode(encodeText, decodeText);

         while(codeStatus == 0)
            codeStatus = displayInstructionNewCode();
      }
      while(codeStatus == 0);

      newCodeOption = displayInstructionNewCode();      
      processNewCode(userSentence, newCodeOption);
   }

   system("PAUSE");
   return 0;
}

void displayInstructions(void)
{
   printf("PASSWORD PROGRAM\n");
 
   return;
}

int  displayMenu(void)
{
   int userOption = 0;

   printf("Please enter your option: \n");
   printf("1. Code\n");
   printf("2. Encode\n");
   printf("3. Make your own code\n");
   printf("9. Quit\n");

   printf("Enter your option > ");
   scanf("%d", &userOption);
   FLUSH

   return userOption;
}

void openFileError(void)
{
   printf("Opening file error!");

   return;
}

void readCode(char encodeText[], char decodeText[], FILE *codeTextIn)
{
   char characterRead;
   int  counter;

   characterRead = fgetc(codeTextIn);

   while(characterRead != EOF)
   {
      for(counter = 0; characterRead != '\n'; counter++)
      {
         encodeText[counter] = characterRead;
         characterRead     = fgetc(codeTextIn);
      }
      
      characterRead = 'z';
   
      for(counter = 0; characterRead != '\n'; counter++)
      {
         characterRead       = fgetc(codeTextIn);
         decodeText[counter] = characterRead;
      }

      characterRead = fgetc(codeTextIn);
   }
   
   return;
}

void getSentence(char userSentence[])
{
   printf("Please enter the sentence: ");
   fgets(userSentence, 80, stdin);

   return;
}

void processCode(char userSentence[], char encodeText[], char decodeText[])
{   
   int reader  = 0,
       counter = 0;
   
   while(userSentence[counter] != '\0')
   {
      for(reader = 0; userSentence[counter] != encodeText[reader]; reader++)
      {}
      printf("%c", decodeText[reader]);

      counter++;
      
   }
   
   return;
}

void processDecode(char userSentence[], char encodeText[], char decodeText[])
{
   int reader  = 0,
       counter = 0;
   
   while(userSentence[counter] != '\0')
   {
      for(reader = 0; userSentence[counter] != decodeText[reader]; reader++)
      {}
      printf("%c", encodeText[reader]);

      counter++;
      
   }
   
   return;
}

int displayInstructionNewCode(void)
{
   printf("BARUU??");

   return 3;
}

void getNewCode(char encodeText[], char decodeText[])
{
   printf("Please enter the new code: ");
   FLUSH
   scanf("%s", encodeText);
   
   printf("Please enter the new decode: ");
   FLUSH
   scanf("%s", decodeText);
   
   return;
}
int  checkNewCode(char codeText[], char decodeText[])
{return 0;}

void processNewCode(char userSentence[], int newCodeOption)
{}
