/****************************************************************************
 File name:  pointersWorksheet.c
 Author:     chadd williams
 Date:       Sep 7, 2011
 Class:      CS300
 Assignment: In Class Example
 Purpose:    Demonstrate define, static functions, static variables inside a
 	 	 	 	 	 	 function.  No actual pointers are used.
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10

static unsigned isEven (int n);

/****************************************************************************
 Function:    main
 Description: loops from 1 to MAX_NUMS calling isEven()
 Parameters:  None
 Returned:    None
 ****************************************************************************/
int main ()
{
	int i;
  int evens[MAX_NUMS];

	for (i = 1; i <= MAX_NUMS; ++i)
	{
		evens[i-1] = 0;
		if (isEven (i))
		{
			evens[i-1]=1;
			printf ("Value = %5u %5d\n", isEven (i), i);
		}
	}

	return EXIT_SUCCESS;
}

/****************************************************************************
 Function:    	isEven
 Description:		This function returns true if n is even, false otherwise.
 	 	 	 	 	 	 		Also, a static value is kept to sum all values of n sent to this
 	 	 	 	 	 	 	 	function.  That static value is display each time the function
								is called, after that value is updated.

 Parameters:  	n - the number to check for evenness
 Returned:    	true if n is even, false otherwise
 ****************************************************************************/
static unsigned isEven (int n)
{
	static int sum = 0;

	sum += n;
	printf ("Sum = %i\n", sum);

	return (n % 2 == 0);
}

