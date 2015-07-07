#include <stdio.h>

// Global variables are statically allocated.
int global;

int f() {
   return global * 10;
}

// Functions can declare static variables that are initialized once statically
// and retain their value across invocations of the function.
int g() {
   static int s = 1;
   return s++ * global;
}

int main() {
   global = 10;
   printf("%d\n", f());
   printf("%d\n", g());
   printf("%d\n", g());
   printf("%d\n", g());
}