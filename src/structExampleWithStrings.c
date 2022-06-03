/****************************************************************************
 File name:		structExampleWithStrigs.c
 Author:			chadd williams
 Date:				June 3, 2022
 Class:				CS300
 Assignment:	In Class Example
 Purpose:    	Demonstrate a struct
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

typedef struct Book
{
  char szTitle [MAX_STR];
  char szAuthor [MAX_STR];
  int yearPublished;
} BookData;


/****************************************************************************
 Function:    	printBook

 Description: 	Print a book, use pass by value (copy)

 Parameters:  	sBook - the book
 
 Returned:    	None
 ****************************************************************************/
void printBook(BookData sBook)
{
  printf("%s %s %d\n", sBook.szAuthor, 
    sBook.szTitle, sBook.yearPublished);
}


/****************************************************************************
 Function:    	removeNewlineFromString

 Description: 	Remove the first newline found in a string
                Replace with a NULL terminator (\0)

 Parameters:  	szData - the string to process
 
 Returned:    	None
 ****************************************************************************/
void removeNewlineFromString(char szData[])
{
  char *pNewline;

  // remove the newline character:
  pNewline = strchr(szData, '\n');
  if ( NULL != pNewline )
  {
    // we found a newline character
    // replace with null character
    *pNewline = '\0';
  }

}


/****************************************************************************
 Function:    	readBook

 Description: 	Read a book from the keyboard
                use pass by reference (pointer)

 Parameters:  	psBook - the book struct to fill with data
 
 Returned:    	None
 ****************************************************************************/
void readBook(BookData *psBook)
{

  // read a string from the keyboard into a char array
  // fgets() will read an entire line, including spaces
  // and newline character!
  //
  // MAX_STR is the max number of characters to read
  // stdin is the keyboard
  //  
  printf("Title: ");
  fgets(psBook->szTitle, MAX_STR, stdin);
  removeNewlineFromString(psBook->szTitle);

  printf("Author: ");
  fgets(psBook->szAuthor, MAX_STR, stdin);
  removeNewlineFromString(psBook->szAuthor);

  // read an int from the keyboard, note the &
  // scanf is a way to read non-string data 
  // from the keyboard
  printf("Year Published: ");
  scanf("%d", &psBook->yearPublished);
}


/****************************************************************************
 Function:    	main

 Description: 	Allocate and use a struct

 Parameters:  	None
 
 Returned:    	None
 ****************************************************************************/
int main ()
{
	
  struct Book sMyFavorite;

  // the typedef allows us to skip
  // the word struct
  BookData sYourFavorite;

  // zero out all the data in the Book struct
  memset(&sMyFavorite, '\0', sizeof(BookData));

  sMyFavorite.yearPublished = 1942;
  strncpy(sMyFavorite.szTitle, "Five Little Pigs", MAX_STR-1);
  strncpy(sMyFavorite.szAuthor, "Christie, Agatha", MAX_STR-1);

  printf("My Favorite: ");
  printBook(sMyFavorite);


  printf("What is your favorite book? ");
  readBook(&sYourFavorite);

  printf("Your Favorite: ");
  printBook(sYourFavorite);

	return EXIT_SUCCESS;
}
