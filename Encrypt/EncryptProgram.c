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
   This program asked the user choose either encode or decode mode. the key code is
   on code1.txt file. The user also able to make his own code. 
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FLUSH while(getchar() != '\n');
#define MAX_STRING_SIZE 81

int  displayMenu(void);
void openFileError(void);
void readCode(char encodeText[], char decodeText[], FILE *codeTextIn);
void getSentence(char userSentence[]);
int  checkSentence(char userSentence[], char codeUsed[]);
void encodeSentence(char userSentence[], char encodeText[], char decodeText[]);
void decodeSentence(char userSentence[], char encodeText[], char decodeText[]);
void displayResult(char userSentence[]);
int  displayInstructionNewCode(void);
void getNewCode(char encodeText[], char decodeText[]);
int  checkNewCode(char codeTextOne[], char codeTextTwo[]);
void processNewCode(char userSentence[], int userOption, char encodeText[],
                    char decodeText[]);
int  promptRestartProgram(void);
void checkCloseFileStatus(int status);

int main(void)
{
   FILE *codeTextIn;

   int  codeStatusEncode,
        codeStatusDecode,
        closeStatus,
        newCodeOption,
        sentenceStatus,
        userOption;
   char encodeText[80],
        decodeText[80],
        userSentence[80];
   do
   {
      userOption = displayMenu();

      while(!(userOption == 1 || userOption == 2 || userOption == 3 || 
              userOption == 9))
         userOption = displayMenu();

      if (!(codeTextIn = fopen("code2.txt", "r")))
         openFileError();

      if(userOption == 1)
      {
         readCode(encodeText, decodeText, codeTextIn); 
         do
         {         
            getSentence(userSentence);  
            sentenceStatus = checkSentence(userSentence, encodeText);
         }         
         while(sentenceStatus == 0);

         encodeSentence(userSentence, encodeText, decodeText);
      }   
      else if(userOption == 2)
      {
         readCode(encodeText, decodeText, codeTextIn);
         do  
         {          
            getSentence(userSentence);
            sentenceStatus = checkSentence(userSentence, decodeText);
         }         
         while(sentenceStatus == 0);

         decodeSentence(userSentence, encodeText, decodeText);
      }
      else if(userOption == 3)
      {
         do
         {
            getNewCode(encodeText, decodeText);

            codeStatusDecode = checkNewCode(encodeText, decodeText);
            if(codeStatusDecode == 0)
               continue;
   
            codeStatusEncode = checkNewCode(decodeText, encodeText);
         }
         while(codeStatusDecode == 0 || codeStatusEncode == 0);

         newCodeOption = displayInstructionNewCode();      
         processNewCode(userSentence, newCodeOption, encodeText, decodeText);
      }
      else
         exit(100);
   }
   while(promptRestartProgram() == 1);

   closeStatus = fclose(codeTextIn);
   checkCloseFileStatus(closeStatus);

   return 0;
}

/******************************************************************************
 Displays the option of the program.
*******************************************************************************/
int displayMenu(void)
{
   int userOption = 0;

   printf("\x1b[2J\x1b[H");
   printf("Welcome to Encrypt Program!\n");
   printf("This program will encrypt a sentence.\n\n\n");
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

/******************************************************************************
 Displays that an error in opening file.
*******************************************************************************/
void openFileError(void)
{
   printf("Opening file error on code1.txt!");

   return;
}

/******************************************************************************
 Reads the key code from the file.
*******************************************************************************/
void readCode(char encodeText[], char decodeText[], FILE *codeTextIn)
{
   char characterRead;

   characterRead = fgetc(codeTextIn);

   while(characterRead != EOF)
   {
      for(int counter = 0; (characterRead != '\n'); counter++)
      {
         encodeText[counter] = characterRead;
         characterRead     = fgetc(codeTextIn);
      }
      
      characterRead = 'z';
   
      for(int counter = 0; characterRead != '\n'; counter++)
      {
         characterRead       = fgetc(codeTextIn);
         decodeText[counter] = characterRead;
      }

      characterRead = fgetc(codeTextIn);
   }
   
   return;
}

/******************************************************************************
 Gets a sentence from the user and capitalizes all letter.
*******************************************************************************/
void getSentence(char userSentence[])
{
   printf("Please enter the sentence: ");
   fgets(userSentence, MAX_STRING_SIZE, stdin);

   for(int counter = 0; (userSentence[counter] != '\n'); counter++)
      userSentence[counter] = toupper(userSentence[counter]);
  
   return;
}

/******************************************************************************
 Checks the sentence if the sentence available in code that used.
*******************************************************************************/
int checkSentence(char userSentence[], char codeUsed[])
{
   int counter = 0,
       reader;

   while(userSentence[counter] != '\n')
   {
      reader = 0;

      while(userSentence[counter] != codeUsed[reader])
      {
         if(codeUsed[reader] == '\0')
         {
            printf("\nInvalid Input!\n");
            return 0;
         }
         
         reader++;
      }

      counter++;
   }

   return 1;
}

/******************************************************************************
 Encodes the user's sentence.
*******************************************************************************/
void encodeSentence(char userSentence[], char encodeText[], char decodeText[])
{   
   int reader;  
 
   printf("\nYour sentence has been encoded!\n");
   printf("Encoded sentence: ");
   for(int counter = 0; (userSentence[counter] != '\n'); counter++)
   {
      reader = 0;
  
      while(userSentence[counter] != encodeText[reader])
         reader++;

      printf("%c", decodeText[reader]); 
   }
   
   printf("\n\n\n");

   return;
}

/******************************************************************************
 Decodes the user's sentence.
*******************************************************************************/
void decodeSentence(char userSentence[], char encodeText[], char decodeText[])
{
   int reader;

   printf("\nYour sentence has been decoded!\n");
   printf("Decoded sentence: ");
   for(int counter = 0; userSentence[counter] != '\n'; counter++)
   {
      reader = 0;
  
      while(userSentence[counter] != decodeText[reader])
         reader++;

      printf("%c", encodeText[reader]); 
   }

   printf("\n\n\n");

   return;
}

/******************************************************************************
 Displays the instruction of the new code.
*******************************************************************************/
int displayInstructionNewCode(void)
{
   int newCodeOption = 0;

   printf("\n\nPlease enter your new code option: \n");
   printf("1. Code\n");
   printf("2. Encode\n");
   printf("9. Quit\n");

   printf("Enter your option > ");
   scanf("%d", &newCodeOption);
   FLUSH

   return newCodeOption;
}

/******************************************************************************
 Gets new decode and encode from the user.
*******************************************************************************/
void getNewCode(char encodeText[], char decodeText[])
{
   printf("Please enter the new encode: ");
   scanf("%s", encodeText);

   for(int counter = 0; (encodeText[counter] != '\0'); counter++)
      encodeText[counter] = toupper(encodeText[counter]);
   FLUSH
   
   printf("Please enter the new decode: ");
   scanf("%s", decodeText);

   for(int counter = 0; (decodeText[counter] != '\0'); counter++)
      {decodeText[counter] = toupper(decodeText[counter]);}
   FLUSH
   
   return;
}

/******************************************************************************
 Checks the user's code validity.
*******************************************************************************/
int checkNewCode(char codeTextOne[], char codeTextTwo[])
{
   int counter = 0,
       letterExist = 0,
       reader = 0;

   if(strlen(codeTextOne) != strlen(codeTextTwo))
   {
      printf("\nBoth code not in the same length!\n");
      return 0;
   }

   while(codeTextOne[counter] != '\0')
   {
      while(codeTextTwo[reader] != '\0')
      {
         if(codeTextOne[counter] == codeTextTwo[reader])
            letterExist++;

         reader++;
      }

      if(letterExist >= 2)
      {
         printf("\nThere is duplicate! Make sure it is no duplicate both code.\n");
         return 0;
      }
   
      counter++;
      letterExist = 0;
      reader      = 0;
   } 
   
   return 1;
}

/******************************************************************************
 Process the new sentence using new code from the user.
*******************************************************************************/
void processNewCode(char userSentence[], int userOption, char encodeText[], 
                    char decodeText[])
{
   int sentenceStatus;

   if(userOption == 1)
      { 
         do
         {
            getSentence(userSentence);  
            sentenceStatus = checkSentence(userSentence, encodeText);
         }         
         while(sentenceStatus == 0);

         encodeSentence(userSentence, encodeText, decodeText);
      }   
      else if(userOption == 2)
      {
         do
         {
            getSentence(userSentence);
            sentenceStatus = checkSentence(userSentence, decodeText);
         }         
         while(sentenceStatus == 0);

         decodeSentence(userSentence, encodeText, decodeText);
      }

   return;
}

/******************************************************************************
 Prompt the user if he want to restart the program.
*******************************************************************************/
int promptRestartProgram(void)
{
   char userSelect;

   printf("Do you want to restart the program? Y/N >");
   scanf(" %c", &userSelect);

   if(userSelect == 'Y' || userSelect == 'y')
      return 1;
   else
      return 0;
}

/******************************************************************************
 Checks the close file status.
*******************************************************************************/
void checkCloseFileStatus(int status)
{
   if(status == EOF)
      printf("Error in closing code1.txt file!\n\a");

   return;
}
