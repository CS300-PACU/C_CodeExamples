/****************************************************************************
 File name:  handles.c
 Author:     chadd williams
 Date:       Sep 29, 2011
 Class:      CS 300
 Assignment: C Code Examples
 Purpose:    Demonstrate Handles
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void allocInt(int **hTheInt)
{
	int *pInt;

	pInt = (int*) malloc(sizeof(int));

	*hTheInt = pInt;

	*pInt = 42;
	return;
}

/****************************************************************************
 Function:    	main

 Description: 	Demonstrate a handle
 
 Parameters:  	None
 
 Returned:    	None
 ****************************************************************************/
int main()
{

	int *pTheInt;
	int actualInt = 9;


	allocInt(&pTheInt);
	printf("%d %d\n", *pTheInt, actualInt);

	return EXIT_SUCCESS;
}

