/****************************************************************************
 File name:  charArraysAndStrings.c
 Author:     chadd williams
 Date:       Sep 8, 2011
 Class:      CS 300
 Assignment: In Class Example
 Purpose:    Demonstrate the use of character arrays as strings in C.
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************
 Function:    printString
 Description: Print the character array
 Parameters:  array - the character array using pointer notation
 Returned:    None
 ****************************************************************************/
void printString (char *pStr)
{
	printf ("printString: %s\n", pStr);
}

/****************************************************************************
 Function:    printCharArray
 Description: Print the character array
 Parameters:  array - the character array
 Returned:    None
 ****************************************************************************/
void printCharArray (char array[])
{
	printf ("printCharArray: %s\n", array);
}

/****************************************************************************
 Function:    main
 Description: Creates two character arrays and passes them to functions for
							printing.  Also removes the null terminator form one array
							to demonstrate the error that occurs.
 Parameters:  None
 Returned:    None
 ****************************************************************************/

int main ()
{
	char *pString = "Hello World";
	char charArray[] = { 'C', 'S', '!', '\0' };

	printString (pString);
	printCharArray (charArray);

	printString (charArray);
	printCharArray (pString);

	/*
	 * The following code, setting charArray[3] to '!',
	 * causes an error.  The null terminator is removed
	 * from the string charArray and printf does not know
	 * when to stop printing characters.
	 */
	charArray[3] = '!';
	printCharArray (charArray);
	printString (charArray);

	return EXIT_SUCCESS;
}
