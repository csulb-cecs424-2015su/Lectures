// Static binding to functions and values in C. What is the output of 
// this program?

#include <stdio.h>

int a;

int f(int a) {
   return a;
}

int f(double a) {
   return a * a;
}

int main() {
   a = 10;
   printf("%d\n", f(5));
   printf("%d\n", f(5.0));
}