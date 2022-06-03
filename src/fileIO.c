/****************************************************************************
 File name:  fileIO.c
 Author:     chadd williams
 Date:       Sep 13, 2011
 Class:      CS300
 Assignment: In Class Example
 Purpose:    Demonstrate how to use fopen/fclose/fgetc/perror
 ****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h> // gives access to isspace(), isdigit(), etc.
/****************************************************************************
 Function:    main
 Description: demonstrates file IO and the use of errno
 Parameters:  None
 Returned:    None
 ****************************************************************************/

int main()
{
	/* open a file in read only mode */
	FILE * fPtr = fopen("data/file.txt", "r");

	char letter;

	/* if the file pointer is NULL, an error occured */
	if( NULL == fPtr)
	{
		/* perror will display the most recent error and the string
		 * given as an argument
		 */
		perror("File did not open");
		return -1;
	}

	/* fgetc gets a single character
	 * whitespace is retrieved by this function
	 */

	letter = fgetc(fPtr);

	/* if EOF is returned, the End Of File has been reached */
	if( EOF != letter)
	{
		if( isspace(letter))
		{
			printf("It is a whitespace!\n");
		}
		else if(isdigit(letter))
		{
			printf("It is a digit!\n");
		}
		printf("%c", letter);
	}

	/* close the file */
	fclose(fPtr);

	return EXIT_SUCCESS;
}
