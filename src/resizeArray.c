/****************************************************************************
 File name:  resizeArray.c
 Author:     chadd williams
 Date:       Oct 28, 2022
 Class:      CS 300
 Assignment: In Class Example
 Purpose:    Demonstrate the use of handles
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memcpy


void resizeArray(int **hArray, int oldSize, int newSize, int fill);

/****************************************************************************
 Function:    main

 Description: Allocate an array, then resize via a function
 
 Parameters:  None

 Returned:    EXIT_SUCCESS
 ****************************************************************************/

int main () {

  // https://github.com/CS300-PACU/C_CodeExamples
  const int ORIG_SIZE = 100;
  const int NEW_SIZE = 150;
  
  int *pArray = malloc (sizeof (int) * ORIG_SIZE);

  for (int i = 0; i < ORIG_SIZE; ++i)
  {
    pArray[i] = i;
  }

  resizeArray (&pArray, ORIG_SIZE, NEW_SIZE, 300);

  for (int i = 0; i < NEW_SIZE; ++i)
  {
    printf ("%d ", pArray[i]);
    if ( (i + 1) % 10 == 0 )
    {
      printf ("\n");
    }
  }

  free (pArray);
  return EXIT_SUCCESS;
}


/****************************************************************************
 Function:    resizeArray

 Description: Resize an int array, fill extra items with the parameter fill
 
 Parameters:  hArray - handle of an int array
              oldSize - the current size of the array
              newSize - the new size of the array
              fill - value to be used to fill the new spots in the array

 Returned:    none
 ****************************************************************************/

void resizeArray(int **hArray, int oldSize, int newSize, int fill)
{
  int *pTempArray = malloc (sizeof (int) * newSize);

  memcpy(pTempArray, *hArray, sizeof (int) * oldSize);

  for (int i = oldSize; i < newSize; ++i)
  {
    pTempArray[i] = fill;
  }

  free (*hArray);
  *hArray = pTempArray;
}
