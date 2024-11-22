// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Classiclibrary.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>

void board () {
   for (int i = 0; i < 3; i++) {
      wprintf (L"\u250F\u2501\u2501\u2533\u2501\u2501\u2533\u2501\u2501\u2513\n");
      wprintf (L"\u2503  \u2503  \u2503  \u2503\n");
      wprintf (L"\u2523\u2501\u2501\u254B\u2501\u2501\u254B\u2501\u2501\u252B\n");
      wprintf (L"\u2503  \u2503  \u2503  \u2503\n");
      wprintf (L"\u2523\u2501\u2501\u254B\u2501\u2501\u254B\u2501\u2501\u252B\n");
      wprintf (L"\u2503  \u2503  \u2503  \u2503\n");
      wprintf (L"\u2517\u2501\u2501\u253B\u2501\u2501\u253B\u2501\u2501\u251B\n");
      return 0;
   }
}


int main () {
   void board ();
   int num;
   printf ("Enter the number (1-9):");
   scanf_s ("%d", &num);
   return 0;
}