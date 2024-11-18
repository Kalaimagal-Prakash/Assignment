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
State nextMealyState (State currentState, int input, int* output) {
   switch (currentState) {
   case S0:
      if (input == 0) {
         *output = 0;
         return S1;  // Transition to S1 after '0' (start of "0110")
      }
      else {
         *output = 0;
         return P1;  // Transition to P1 after '1' (start of "1101")
      }
   case S1:
      if (input == 1) {
         *output = 0;
         return S2;  // Transition to S2 after '01' (start of "0110")
      }
      else {
         *output = 0;
         return S1;  // Stay in S1 if input is '0'
      }
   case S2:
      if (input == 1) {
         *output = 0;
         return S3;  // Transition to S3 after '011' (start of "0110")
      }
      else {
         *output = 0;
         return S1;  // Return to S1 if input is '0'
      }
   case S3:
      if (input == 0) {
         *output = 1;
         return P3;  // Transition to P3 after '011' (start of "0110")
      }
      else {
         *output = 0;
         return P2;  // Return to P2 if input is '0'
      }
   case P1:
      if (input == 1) {
         *output = 0;
         return P2;  // Transition to P2 after '11' (start of "1101")
      }
      else {
         *output = 0;
         return S1;  // Stay in P1 if input is '0'
      }
   case P2:
      if (input == 0) {
         *output = 0;
         return P3;  // Transition to P3 after '110' (start of "1101")
      }
      else {
         *output = 0;
         return P2;  // Return to P2 if input is '1'
      }
   case P3:
      if (input == 1) {
         *output = 1;
         return S2;  // Transition to S2 after '110' (start of "1101")
      }
      else {
         *output = 0;
         return S1;  // Return to S1 if input is '1'
      }
      return S0;  // Default return to initial state
   }
}

static int ProcessFSM (FILE* inputFile, FILE* outputFile) {
   State currentState = S0;  // Start in the initial state
   int input;
   int output = 0;
   while ((input = getc (inputFile)) != EOF) {                                 // Read input from the file and process it until the end of file (EOF)
      currentState = nextMealyState (currentState, input - '0', &output);      // Transition to the next state and calculate the output
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
   // Run the FSM function
   int result = ProcessFSM (inputFile, outputFile);
   if (result == 0) printf ("FSM process completed Output is saved in %s\n", argv[2]);
   else printf ("FSM processing failed.\n");
   // Close the files
   fclose (outputFile);
   fclose (inputFile);
   return 0;
}