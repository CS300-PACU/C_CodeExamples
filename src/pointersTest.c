/****************************************************************************
 File name:   pointersTest.c
 Author:      chadd williams
 Date:        Sep 16, 2011
 Class:       CS 300
 Assignment:  C Code Examples
 Purpose:     Demonstrate pointers!
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************
 Function:    	main

 Description: 	Demonstrate pointers
 
 Parameters:  	None
 
 Returned:    	None
 ****************************************************************************/

int main ()
{
  int first = 11;
	int count[2] = {4, 9};
	int index = 9;

	int *pCount;

	pCount = count;
	*pCount = 6;

	printf ("%d  %p %d\n",  *(pCount+0), pCount, *(pCount+1));
	return EXIT_SUCCESS;
}

