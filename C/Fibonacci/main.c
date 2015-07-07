#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int get_fib(int);

int main() {
   printf("Which Fibonacci number would you like to know? ");
   int target;
   scanf("%d", &target);
   printf("The #%d Fibonacci number is %d\n", target, get_fib(target));
   return 0;
}

int get_fib(int target) {
   // 0 is the 0th Fibonacci number
   int val1 = 0, val2 = 1;
   for (int i = 0; i < target; i++) {
      int next = val1 + val2;
      val1 = val2;
      val2 = next;
   }
   return val1;
}