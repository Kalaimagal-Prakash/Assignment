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
#define NTESTS 6
int ExecProgram (char* exeFilePathAndName, char* inputFilePathAndName, char* outputFilePathAndName);
int CompareFiles (char* outputFile, char* referenceFile);

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

/// <summary> Function to compare two files output and reference.</summary>
int CompareFiles (char* outputFile, char* referenceFile) {
   FILE* Output = fopen (outputFile, "r"), * reference = fopen (referenceFile, "r");
   if (Output == NULL || reference == NULL) {
      printf ("Error opening files.\n");
      return 1;
   }
   int pos = 0, ch1, ch2;
   while ((ch1 = fgetc (Output)) != EOF && (ch2 = fgetc (reference)) != EOF) {
      if (ch1 != ch2) {
         printf ("Error at bit no. %d, Expected %c, Actual %c\n", pos, ch1, ch2);
         fclose (Output); fclose (reference);
         return 1;
      }
      pos++;
   }
   fclose (Output); fclose (reference);
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
   // Declare the test files and corresponding file paths
   char* inputFiles[] = {
       "test1input.txt", "test2input.txt", "test3input.txt", "test4input.txt", "test5input.txt", "test6input.txt"
   };
   char* outputFiles[] = {
       "test1output.txt", "test2output.txt", "test3output.txt", "test4output.txt", "test5output.txt", "test6output.txt"
   };
   char* referenceFiles[] = {
      "test1Ref.txt", "test2Ref.txt", "test3Ref.txt", "test4Ref.txt", "test5Ref.txt", "test6Ref.txt"
   };
   // Iterate through all test cases
   for (int i = 0; i < NTESTS; i++) {
      // Run the FSM program with input redirection and output redirection
      if (ExecProgram (argv[1], inputFiles[i], outputFiles[i]) != 0) {
         printf ("Error executing test %d\n", i + 1);
         continue;  // If execution fails, skip to the next test
      }
      else {
         int result = CompareFiles (outputFiles[i], referenceFiles[i]);
         printf ((result == 0) ? "NO ERROR in this file Test %d PASSED.\n\n" : "Test %d FAILED\n\n", i + 1);
      }
   }
   return 0;
}