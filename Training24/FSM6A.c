// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Classiclibrary.c
// Program on A6B branch.
// ------------------------------------------------------------------------------------------------
// Create an FSM in C to process bit streams and verify output using a test harness.
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

/// See File: // FSMDiagram.png
/// <summary>Define states of the Mealy machine.</summary>
typedef enum {
   S0,  // Initial state
   S1,  // After '0'
   S2,  // After '01'
   S3,  // After '011'
   P1,  // After '1'
   P2,  // After '11'
   P3,  // After '110'
} State;

/* Demo program to implement a Mealy machine.
*  This machine detects a pattern 0110 or 1101 in an input stream.
*/
static State NextMealyState (State currentState, int input, int* output) {
   *output = 0;
   switch (currentState) {
   case S0: return (input == 0) ? S1 : P1;
   case S1: return (input == 1) ? S2 : S1;
   case S2: return (input == 1) ? S3 : S1;
   case S3: *output = !input; return (input == 0) ? P3 : P2;
   case P1: return (input == 1) ? P2 : S1;
   case P2: return (input == 0) ? P3 : P2;
   case P3: *output = input; return (input == 1) ? S2 : S1;
   default: return S0;
   }
}

static int ProcessFSM (FILE* inputFile, FILE* outputFile) {
   State currentState = S0;  // Start in the initial state
   int input;
   int output = 0;
   while ((input = getc (inputFile)) != EOF) {                                 // Read input from the file and process it until the end of file (EOF)
      currentState = NextMealyState (currentState, input - '0', &output);      // Transition to the next state and calculate the output
      fprintf (outputFile, "%d", output);                                      // Write the output value to the output file
   }
   return 0;
}

int main (int argc, char* argv[]) {
   // Check if the correct number of arguments are passed
   if (argc < 3) {
      printf ("Usage: <FSM Executable> <testin.txt> <testout.txt>\n");
      return -1;
   }
   FILE* inputFile = fopen (argv[1], "r");
   FILE* outputFile = fopen (argv[2], "w");
   if (!inputFile || !outputFile) {
      printf ("Error opening files.\n");
      return -2;
   }
   int result = ProcessFSM (inputFile, outputFile);
   if (result == 0) printf ("FSM process completed Output is saved in %s\n", argv[2]);
   else printf ("FSM processing failed.\n");
   fclose (outputFile);
   fclose (inputFile);
   return 0;
}