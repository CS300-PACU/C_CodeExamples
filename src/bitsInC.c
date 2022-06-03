/****************************************************************************
 File name:  bitsInC.c
 Author:     chadd williams
 Date:       Nov 7, 2011
 Class:      CS 300
 Assignment: C Code Examples
 Purpose:    Demonstrate Bits!
 ****************************************************************************/

#include <stdio.h>



/*

binary (base 2) 0, 1
decimal (base 10) 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
hexadecimal (base 16) 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f


unsigned short is 2 bytes with range 0 to 2^16 - 1
unsigned int is 4 bytes with range 0 to 2^32 - 1
unsigned long is 8 bytes with range 0 to 2^64 - 1



short is 2 bytes with range -(2^15) to (2^15 - 1)
int is 4 bytes with range -(2^31) to (2^31 - 1)
long is 8 bytes with range -(2^63) to (2^63 - 1)



Convert 10 decimal to a) binary 1010  b) hex A
Convert F0 hex to a) binary 11110000  b) decimal 240
Convery 11000011 binary to a) decimal 195  b) hex C3

*/


/****************************************************************************
 Function:    	main

 Description: 	Demonstrate bitwise operators
 
 Parameters:  	None
 
 Returned:    	None
 ****************************************************************************/

int main ()

{

  unsigned short i = 0xa7, j = 8;

  short k = 0x7fff;


	printf("%ld %ld %ld %ld %ld\n", 
	sizeof(char), sizeof(short),
	sizeof(int), sizeof(long),
	sizeof(long long));

  printf ("%04x %04x\n", i, j);



  if (i && j)
  {
		puts ("true");
	}
	else
	{
		puts ("false");
	}



	if (i & j)
  {
		puts ("true");
	}
	else
	{
		puts ("false");
	}


	j >>= 1;


	if (i & j)
  {
		puts ("true");
	}
	else
	{
		puts ("false");
	}

	printf ("%d\n", k);
	++k;
	printf ("%d\n", k);


  return 0;

}

