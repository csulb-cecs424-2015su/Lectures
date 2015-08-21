#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
   // in C, a string is a character pointer to a sequence of character values,
   // terminated by the special '\0' character.

   const char *s = "Hello";
   // s is a pointer on the stack, but the 6-character string "Hello" (why 6?)
   // is typically in static memory.

   printf("s is at %p; it points to a string at %p\n", &s, s);

   // C uses ASCII encoding for characters; we can get integer values easily.
   printf("The ASCII value for %c is %d\n", s[0], (int)s[0]);
   printf("The ASCII value for '\\0' is %d\n\n", (int)s[5]);

   // Because string literals are allocated statically, it doesn't make sense
   // to have more than one copy of any single literal in static memory.
   const char *s2 = "Hello";
   
   printf("s2 is at %p; it points to a string at %p\n", &s2, s2);

   // In most C implementations, statically allocated strings are immutable.
   // The next line is not allowed because s is const; if we made s non-const,
   // it could crash the program depending on the implementation.
   // s[0] = 'C';

   // To make mutable dynamically sized strings, we use dynamic memory.
   char *m = (char*)malloc(6 * sizeof(char)); // 6!!!
   printf("Enter a string of AT MOST 5 LETTERS!!!\n");
   scanf("%s", m);
   printf("You entered %s\n", m);

   // I can mutate a dynamic string
   m[0] = 'X';
   printf("I mutated it to %s\n", m);

   // The C library has many functions for working with strings.
   printf("The length of what you entered is %d\n", strlen(m));
}