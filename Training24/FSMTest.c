// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on A6B branch.
// ------------------------------------------------------------------------------------------------
// Create an FSM in C to process bit streams and verify output using a test harness.
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS  1
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <synchapi.h> 
#include <string.h> 
#include <processthreadsapi.h> 
#include <handleapi.h> 
#include <errhandlingapi.h> 
int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName);
int CompareFiles (char* outputFile, char* referenceFile, int testCaseNumber);

/// <summary>
/// This function will execute the FSM providing the input and output file names as arguments
/// </summary>
/// <param name="exeFilePathAndName"></param>
/// <param name="inputFilePathAndName"></param>
/// <param name="outputFilePathAndName"></param>
/// <returns></returns>
int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName) {
   char* cmdline = malloc (strlen (exeFilePathAndName) + strlen (inputFilePathAndName) + strlen (outputFilePathAndName) + 3);
   if (cmdline == NULL) {
      printf ("Unable to allocate memory\n");
      return 1;
   }
   sprintf (cmdline, "%s%s%s%s%s", exeFilePathAndName, " ", inputFilePathAndName, " ", outputFilePathAndName);
   // Set up structures for process information
   STARTUPINFOA si;
   PROCESS_INFORMATION pi;
   // Initialize memory for STARTUPINFO and PROCESS_INFORMATION structures
   ZeroMemory (&si, sizeof (si));
   si.cb = sizeof (si);
   ZeroMemory (&pi, sizeof (pi));
   // Attempt to create the process
   if (!CreateProcessA (
      NULL,             // Application name (NULL if using command line)
      cmdline,          // Command line (path to the executable)
      NULL,            // Process handle not inheritable
      NULL,            // Thread handle not inheritable
      FALSE,           // Set handle inheritance to FALSE
      0,               // No creation flags
      NULL,            // Use parent's environment block
      NULL,            // Use parent's starting directory
      &si,             // Pointer to STARTUPINFO structure
      &pi))            // Pointer to PROCESS_INFORMATION structure
   {
      // If CreateProcess fails, print an error message
      int err = GetLastError ();
      printf ("Failed to start process. Error: %lu\n", GetLastError ());
      free (cmdline);
      return 1;
   }
   // Wait until the process has finished execution
   WaitForSingleObject (pi.hProcess, INFINITE);
   CloseHandle (pi.hProcess);
   CloseHandle (pi.hThread);
   free (cmdline);
   return 0;
}

void Clean (FILE* output, FILE* reference, char* outputBuffer, char* referenceBuffer) {
   if (output) fclose (output);
   if (reference) fclose (reference);
   if (outputBuffer) free (outputBuffer);
   if (referenceBuffer) free (referenceBuffer);
}

/// <summary> Function to compare two files output and reference.</summary>
int CompareFiles (char* outputFile, char* referenceFile, int testCaseNumber) {
   FILE* output = fopen (outputFile, "r"), * reference = fopen (referenceFile, "r");
   if (output == NULL || reference == NULL) {
      printf ("Error opening files.\n");
      return 1;
   }
   fseek (output, 0, SEEK_END);
   long outputSize = ftell (output);
   fseek (output, 0, SEEK_SET);
   fseek (reference, 0, SEEK_END);
   long referenceSize = ftell (reference);
   fseek (reference, 0, SEEK_SET);
   if (outputSize != referenceSize) {
      printf (" Test case %d Fail\n", testCaseNumber);
      return 1;
   }
   char* outputBuffer = (char*)malloc (outputSize);
   char* referenceBuffer = (char*)malloc (referenceSize);
   if (outputBuffer == NULL || referenceBuffer == NULL) {
      printf ("Memory allocation error.\n");
      return -1;
   }
   fread (outputBuffer, 1, outputSize, output);
   fread (referenceBuffer, 1, referenceSize, reference);
   if (memcmp (outputBuffer, referenceBuffer, outputSize) != 0) {
      for (long i = 0; i < outputSize; i++) {
         if (outputBuffer[i] != referenceBuffer[i]) {
            printf ("Error at bit no. %ld, Expected %c, Actual %c\n", i, referenceBuffer[i], outputBuffer[i]);
            break;
         }
      }
      Clean (output, reference, outputBuffer, referenceBuffer);
      return 1;
   }
   Clean (output, reference, outputBuffer, referenceBuffer);
   return 0;
}

/// <summary>
/// Test Harness
/// </summary>
/// <param name="argc"></param>
/// <param name="argv">argv[1] is the name of the FSM</param>
/// <returns></returns>
int main (int argc, char** argv) {
   if (argc != 2) {
      printf ("Usage: %s <FSM executable name>\n", argv[0]);
      return -1;
   }
   printf ("FSM Test Harness\n");
   char* inputFiles[] = {
       "TData/test1input.txt", "TData/test2input.txt", "TData/test3input.txt", "TData/test4input.txt", "TData/test5input.txt", "TData/test6input.txt"
   };
   char* referenceFiles[] = {
       "TData/test1Ref.txt", "TData/test2Ref.txt", "TData/test3Ref.txt", "TData/test4Ref.txt", "TData/test5Ref.txt", "TData/test6Ref.txt"
   };
   char* tempOutputFile = "tempOutput.txt";
   FILE* tempFile = fopen (tempOutputFile, "w");
   if (tempFile == NULL) {
      printf ("Error creating temp output file.\n");
      return -1;
   }
   int numTests = sizeof (inputFiles) / sizeof (inputFiles[0]);
   for (int i = 0; i < numTests; i++) {
      // Execute the program with input file and store the output
      if (ExecProgram (argv[1], inputFiles[i], tempOutputFile) != 0) {
         printf ("Error executing test %d\n", i + 1);
         return -1;
      }
      if (CompareFiles (tempOutputFile, referenceFiles[i], i + 1) != 0) {
         printf ("TEST FAIL at case %d: Output does not match reference\n", i + 1);
         return -1;
      }
   }
   fclose (tempFile);
   printf ("All tests passed.\n");
   return 0;
}