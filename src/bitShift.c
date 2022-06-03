/****************************************************************************
 File name:  bitShift.c
 Author:     chadd williams
 Date:       Nov 7, 2011
 Class:      CS 300
 Assignment: C Code Examples
 Purpose:    Demonstrate bit shifting
 ****************************************************************************/

#include <stdio.h>

/****************************************************************************
 Function:    	main
 Description: 	Creates an int and does some masking and shifting
 Parameters:  	None
 Returned:    	None
 ****************************************************************************/
int main()
{
	unsigned int i = 0x1231a456;
	unsigned int middle;

	middle = (i & 0x000ff000) >> 12 ;

	printf(" %d %d\n", i, middle);

	printf(" %08x %08x\n", i, middle);
}
