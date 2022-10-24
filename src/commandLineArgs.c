/****************************************************************************
 File name:  commandLineArgs.c
 Author:     chadd williams
 Date:       Oct 21, 2022
 Class:      CS 300
 Assignment: In Class Example
 Purpose:    Demonstrate the use of argv,argc
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit
#include <string.h> // for strlen
#include <stdbool.h>

/****************************************************************************
 Function:    main

 Description: Read command line arguments from argv/arc
 
 Parameters:  argc - the number of command line arguments
              argv - a pointer to an array of null terminated strings
                      these are the command line arguments

 Returned:    EXIT_SUCCESS
 ****************************************************************************/

int main (int argc, char *argv[]) {

  // https://github.com/CS300-PACU/C_CodeExamples
  
  // sometimes the parameters are written as:
  // int main (int argc, char **argv) 
  // Why are these two definitions equivalent?

  int len;
  int intArg;
  bool bIsNumber;

  // check if any arguments are given
  if ( 1 == argc)
  {
    printf("No command line arguments given!\n\n");
  }

  // print each command line argument as a string
  for (int i = 0; i < argc; ++i) {
    printf("argv[%d] = \'%s\'\n", i, argv[i]);
  }

  // find integer command line arguments, 
  // convert to an int, and print
  for (int i = 0; i < argc; ++i) {

    len = strlen(argv[i]);
    bIsNumber = true;

    for (int j = 0; bIsNumber && j < len; ++j) {
      if (!isdigit(argv[i][j]))
      {
        bIsNumber = false;
      }
    }

    if (bIsNumber) {
      intArg = atoi(argv[i]);
      printf("int arg: argv[%i] = %d\n", i, intArg);
    }
  }

  // for complex command line options, use
  // https://www.gnu.org/software/libc/manual/html_node/Getopt.html

  return EXIT_SUCCESS;
}