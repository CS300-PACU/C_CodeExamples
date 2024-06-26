//***************************************************************************
// File name:		main.c
// Author:			chadd williams
// Date:				September 24, 2021
// Class:				CS 360
// Purpose:			Demonstrate strncat and snprintf
//***************************************************************************

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

/****************************************************************************
 Function:		myPrintf
 
 Description:	Print the characters in the array until the \0
 
 Parameters:	szStr - the string to print

 Returned:		none
****************************************************************************/
void myPrintf(char *szStr)
{
  int length = strlen(szStr);
  int index;

  for (index = 0; index < length; ++index)
  {
    printf("%c", szStr[index]);
  }

}

/****************************************************************************
 Function:		printCharArray
 
 Description:	Print out each character of the string
 
 Parameters:	szName - the name of the array being printed
              szStr - the string to print
              size  - the size of the array

 Returned:		none
****************************************************************************/
void printCharArray(char *szName, char *szStr, int size)
{
  int index;
  
  printf("\n\nNAME  : %s\n", szName);
  myPrintf("PRINTF: ");
  myPrintf(szStr);
  printf("\n");
  printf("ARRAY : ");

  for (index = 0; index < size; ++index)
  {
    printf("|");
    if ('\0' == szStr[index])
    { 
      printf("\\0");
    }
    else
    {
      printf("%c", szStr[index]);
    }
  }
  printf("|\n");
}


/****************************************************************************
 Function:		main
 
 Description:	Use strncat and snprintf to build null termianted strings
 
 Parameters:	none

 Returned:		EXIT_SUCCESS
****************************************************************************/
int main()
{
  const int BUFFER_SIZE = 1024;
  const int SMALL_ST_SIZE = 15;
  const int NAME_SIZE = 8;


  char szBuffer[BUFFER_SIZE];
  char szSmallString[SMALL_ST_SIZE];
  char szName[NAME_SIZE];

  // copy data into szName
  strncpy(szName, "CS360", NAME_SIZE);

  printCharArray("szName", szName, NAME_SIZE);
  printf("\n");

  // set the first position to the null terminator
  szName[0] = '\0';
  printCharArray("szName", szName, NAME_SIZE);
  printf("\n");

  // null terminate both empty strings
  szBuffer[0] = '\0';
  szSmallString[0] = '\0';

  // printCharArray("szBuffer", szBuffer, BUFFER_SIZE);
  // printf("\n");

  printCharArray("szSmallString", szSmallString, SMALL_ST_SIZE);
  printf("\n");

  printf("memset\n");
  memset(szSmallString, '\0', SMALL_ST_SIZE);

  printCharArray("szSmallString", szSmallString, SMALL_ST_SIZE);
  printf("\n");

  // destination: szSmallString
  // source: "Hello:"
  // number of characters to copy from src to dest:
  // Size of the dest string MINUS ONE
  // the minus one is to reserve space for the NULL '\0'
  // character.
  strncat(szSmallString, "Hello:", SMALL_ST_SIZE - 1);

  printf("szSmallString: %s\n\n", szSmallString);

  // Now, szSmallString contains data so 
  // strncat will put the new string, " CS360!", after
  // the existing data in szSmallString
  //
  // Since there is already data in szSmallString we 
  // can copy fewer bytes over from the src string.
  strncat(szSmallString, " CS360!", (SMALL_ST_SIZE - strlen(szSmallString)) - 1 );

  printf("szSmallString: %s\n\n", szSmallString);


  // destination: szBuffer
  // size: BUFFER_SIZE
  // format string: "MSG TXT ..."
  // variables: szSmallString
  snprintf(szBuffer, BUFFER_SIZE, "MSG TXT 1.1\r\n%s\r\n", szSmallString);

  printf("szBuffer: \n>|%s|<\n\n", szBuffer);

  return EXIT_SUCCESS;
}