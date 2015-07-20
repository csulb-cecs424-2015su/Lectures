#include <iostream>
using namespace std;

int global = 0;

// In most C-derived languages, conditional statements "short circuit" --
// using rules of logic, as soon as we know the truth of an entire conditional
// expression, we can stop evaluating the remaining portions of it.

int main() {
   int x = 10;
   int y = 100;

   if (x < y || x > 0) {
      // will the second condition actually be evaluated?
   }

   if (x == 0 && y == 100) {
      // will the second condition actually be evaluated?
   }

   // This feature is very useful in practice.
   int *p = 0; // null

   // ...
   // Say I want to dereference p only if it is not null.
   if (p != 0 && *p > 0) {
      // what happens if p is null?
      // what happens if it is not?
   }


   // A more complicated example
   int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
   if (a > b && c > d || e != f) { // remember, && has higher precedence than ||
      // THEN_CLAUSE
   }

   // Given that a CPU can only do one conditional test at a time and then
   // execute a jump in response, how do you suppose the compound conditionals
   // above are compiled into assembly?


   //          if a <= b goto Next
   //          if c > d goto Success
   // Next:    if e == f goto Fail
   // Success: THEN_CLAUSE
   //          goto Done
   // Fail:    ELSE_CLAUSE
   // Done:    



   // Without short circuiting, what would we have to do?
   //          r1 = a > b
   //          r1 = r1 && (c > d)
   //          r1 = r1 || e != f
   //          if r1 == false goto Fail
   //          THEN_CLAUSE
   //          goto Done
   // Fail:    ELSE_CLAUSE
   // Done:



   // How about switch statements?
   switch (a) {
   case 5:
      // clause A
      break;
   case 6:
      // clause B
      break;
   case 8:
   case 9:
   case 10:
      // clause C
      break;
   default:
      // clause D
      break;
   }



}