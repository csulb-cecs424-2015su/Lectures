#include <stdio.h>

// C does NOT allow nested subroutines, but imagine it did...
void A() {
   int x = 10;

   int B(int param) {
      int local = 5;
      return local * param * x;
   }

   int C(int param) {
      return B(param) + x;
   }

   printf("%d", B(5));
   printf("%d", C(5));
}

/* Answer these questions:
   1. In terms of fp, where is the address of int x on the stack?
   2. When B() is called on line 16, how would it know where x is?
   3. When B() is called on line 13, how would it know where x is?
*/