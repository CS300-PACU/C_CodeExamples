/*******************************************************************************
 File name:  main.c
 Author:     Computer Science, Pacific University
 Date:			 8/30/17
 Class:      CS300
 Assignment: Exam Stats
 Purpose:    To create a program that will give you the mean for a given set of
  					 exams.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_EXAM_SCORES 50
#define MIN_EXAM_SCORES 1
#define MAX_SCORE 100

static void getExamScores (int aExamScores[], int numExamScores);
static void getExamScore (int *pExamScore, int whichScore);
static void printExamScores (const int aExamScores [], int numExamScores);
static float calculateMean (const int aExamScores[], int numExamScores);

/*******************************************************************************
 Function:    main

 Description: Driver for entering exam scores and finding/printing the exam
              scores and the mean of the exam scores.

 Parameters:  None

 Returned:    Exit Status
*******************************************************************************/

int main ()
{
	int numExamScores;
	int *pExamScores;

	printf ("Exam Stats \n\n");

	do
	{
		printf ("Enter Number of Exams: ");
		scanf ("%d", &numExamScores);
	} while (numExamScores < MIN_EXAM_SCORES ||
	         numExamScores > MAX_EXAM_SCORES);

	pExamScores = (int *) malloc (sizeof (int) * numExamScores);

	if (NULL == pExamScores)
	{
		printf ("Error: Cannot Allocate Memory\n\n");
		exit(EXIT_FAILURE);
	}

	printf ("\n");
	getExamScores (pExamScores, numExamScores);

	printf ("\n");
	printExamScores (pExamScores, numExamScores);

	printf ("\n\n");
	printf ("Mean is %6.2f", calculateMean (pExamScores, numExamScores));

	free (pExamScores);

	return EXIT_SUCCESS;
}

/*******************************************************************************
 Function:    getExamScores

 Description: Enters exam scores into an array and then calls insert which
							places the exams in increasing order;

 Parameters:  aExamScores    - an array of exam scores
							numExamScores  - the number of exams scored

 Returned:    None
*******************************************************************************/

static void getExamScores (int aExamScores[], int numExamScores)
{
	int i;

	for (i = 0; i < numExamScores; ++i)
	{
		getExamScore (&aExamScores[i], i + 1);
	}
}

/*******************************************************************************
 Function:    getExamScore

 Description: Gets an exam score and checks it's between the allowed values.

 Parameters:  pExamScore - a pointer to an exam score
							whichScore - the number of the scored exam

 Returned:    None
*******************************************************************************/

static void getExamScore (int *pExamScore, int whichScore)
{
	do
	{
		printf ("Enter Exam Score %d: ", whichScore );
		scanf ("%d", pExamScore);
	}while (*pExamScore < 0 || *pExamScore > MAX_SCORE);
}

/*******************************************************************************
 Function:    printExamScores

 Description: Displays the exam scores in order from the array

 Parameters:  aExamScores    - an array of exam scores
							numExamScores  - the number of exams scored

 Returned:    None
*******************************************************************************/

static void printExamScores (const int aExamScores [], int numExamScores)
{
	const int NUMS_PER_ROW = 5;
	int i;

	printf ("Exam Summary Output\n\n");

	printf ("Exam Scores\n");

	for ( i = 0; i < numExamScores; ++i)
	{
		if ( 0 == i % NUMS_PER_ROW )
		{
			printf ("\n");
		}

		printf ("%4d", aExamScores[i]);
	}
}

/*******************************************************************************
 Function:    calculateMean

 Description: Calculates the mean of an array of exam scores

 Parameters:  aExamScores    - an array of exam scores
							numExamScores  - the number of exams scored

 Returned:    the average of the exam scores;
*******************************************************************************/

static float calculateMean (const int aExamScores[], int numExamScores)
{
	int i;
	float mean = 0.0;
	float sumOfScores = 0;

	for (i = 0; i < numExamScores; ++i)
	{
		sumOfScores += aExamScores[i];
	}

	if (numExamScores != 0 )
	{
		mean = sumOfScores / numExamScores;
	}

	return mean;
}
