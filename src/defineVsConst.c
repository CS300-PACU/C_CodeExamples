/****************************************************************************
 File name:  	defineVsConst.c
 Author:     	Chadd Williams
 Date:       	9/7/11
 Class:      	CS300
 Assignment: 	In Class Example
 Purpose:    	Display how #define and const int differs in a compile.
							The following code is annotated with compiler errors produced
							when using #define vs const int.
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DEFINE 10
#define MAX_DEFINE_BIGGER  MAX_DEFINE + 1

const int MAX_CONST = 11;

// error: initializer element is not constant
// const int MAX_CONST_BIGGER = MAX_CONST + 1;

enum define_values
{
	VAL_DEFINE_11 = MAX_DEFINE
};

// error: enumerator value for ‘VAL_CONST_11’ is not an integer constant
enum const_values
{
	VAL_CONST_11 = MAX_CONST
};

/****************************************************************************
 Function:    main
 Description: demonstrates various usages of #DEFINED values and
							const int values
 Parameters:  None
 Returned:    None
 ****************************************************************************/
int main ()
{
	int arrayDefine[MAX_DEFINE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//error: variable-sized object may not be initialized
	//int arrayConst[MAX_CONST] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	int value = 2;

	printf ("size of DEFINE %lx\n", sizeof(MAX_DEFINE));
	printf ("size of CONST %lx\n", sizeof(MAX_CONST));

	switch (value)
	{
		case MAX_DEFINE:
			printf ("DEFINE");
			break;

			// error: case label does not reduce to an integer constant
			/*case MAX_CONST:
			 printf("CONST");
			 break;*/
	}
	return EXIT_SUCCESS;
}
