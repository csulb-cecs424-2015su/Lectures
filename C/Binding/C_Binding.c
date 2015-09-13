// Static scope bindings to functions and values in C. 

#include <stdio.h>

int a;

int f(int a) {
   if (a > 10) {
      double b = 3.14;
      return (int)(a * b);
   }
   return a;
}

int g(double a) {
   return a * a;
}

int main() {
   a = 10;
   printf("%d\n", f(5));
   printf("%d\n", g(5.0));
}

/* Questions:
   1. What is the scope of variable "a" on line 5?
   2. What is the scope of variable "b" in function f?
   3. What bindings are in the GLOBAL scope?
   4. What bindings are in the scope of f?
   5. When are these answers determined?
*/