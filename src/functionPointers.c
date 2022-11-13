/****************************************************************************
 File name:  functionPointers.c
 Author:     chadd williams
 Date:       Nov 13, 2022
 Class:      CS 300
 Assignment: C Code Examples
 Purpose:    Demonstrate Function Pointers
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// define a function pointer type
typedef void(*intFunc)(int);
// type name: intFunc
// return type of function: void
// parameter list of function: (int)

// a struct that contains function pointers
typedef struct HoldFP {
	intFunc pPrint;
	intFunc pSum;
} HoldFP;

/****************************************************************************
 Function:    printInt

 Description: print the int parameter to the screen
 
 Parameters:  value - the int to print

 Returned:    none
 ****************************************************************************/
void printInt (int value) {
	printf ("%d", value);
}


/****************************************************************************
 Function:    sumInt

 Description: add the parameter int to gSum
 
 Parameters:  value - the int to add

 Returned:    none
 ****************************************************************************/
int gSum = 0;
void sumInt (int value) {
	gSum += value;
}

/****************************************************************************
 Function:    visitInts

 Description: Visit each int in the array and call pFunc on that int
 
 Parameters:  pFunc - the function to call on each int
							array - the array of ints
							size - the size of the array

 Returned:    none
 ****************************************************************************/
void visitInts(intFunc pFunc, int array[], int size) {
	for (int i=0; i< size; ++i) {
		(*pFunc) (array[i]);
	}
}

/****************************************************************************
 Function:    printInts

 Description: Call visitInts with the print function in the struct
 
 Parameters:  sFPs - the struct holding the function pointers
							array - the array of ints
							size - the size of the array

 Returned:    none
 ****************************************************************************/
void printInts(HoldFP sFPs, int array[], int size) {
	visitInts(sFPs.pPrint, array, size);
}

/****************************************************************************
 Function:    sumInts

 Description: Call visitInts with the sum function in the struct
 
 Parameters:  sFPs - the struct holding the function pointers
							array - the array of ints
							size - the size of the array

 Returned:    none
 ****************************************************************************/
void sumInts(HoldFP sFPs, int array[], int size) {
	visitInts(sFPs.pSum, array, size);
}

/****************************************************************************
 Function:    incrInt

 Description: increment the int parameter by one

 Parameters:  value - the int to incr

 Returned:    none
 ****************************************************************************/
void incrInt (int *pValue) {
		(*pValue) ++;
}

/****************************************************************************
 Function:    editInts

 Description: Visit each int in the array and call pFunc on that int
 
 Parameters:  pFunc - the function to call on each int
							array - the array of ints
							size - the size of the array

 Returned:    none
 ****************************************************************************/
void editInts(void (*pFunc)(int*), int array[], int size) {
	for (int i=0; i< size; ++i) {
		(*pFunc) (&array[i]);
	}
}

/****************************************************************************
 Function:    main

 Description: demonstrate function pointers
 
 Parameters:  none

 Returned:    EXIT_SUCCESS indicating knowledge gained!
 ****************************************************************************/
int main () {
	const int SIZE = 7;
	int array[] = {1, 2, 3, 4, 5, 6, 7};

	HoldFP sFPs;

	// array of function pointers
	intFunc fpArray[] = {printInt, sumInt};

	// store function pointers in a struct
	sFPs.pPrint = printInt;
	sFPs.pSum = sumInt;

	printf("CALL visitInts\n");
	visitInts(printInt, array, SIZE);

	printf("\n\nCALL editInts\n");
	editInts(incrInt, array, SIZE);

	printf("\nCALL printInts\n");
	printInts(sFPs, array, SIZE);

	printf("\n\nCALL sumInts\n");
	sumInts(sFPs, array, SIZE);
	printf("gSum: %d\n", gSum);

	printf("\nCall printInt(300) via array\n");
	(*fpArray[0])(300);

	printf("\n\nCall sumInt(300) via array\n");
	(*fpArray[1])(300);
	printf("gSum: %d\n", gSum);

	return EXIT_SUCCESS;
}