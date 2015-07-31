#include <stdio.h>
#include <time.h>

#define DIM 4096
int main() {
   int (*large)[DIM] = malloc(sizeof(int) * DIM * DIM);
   
   clock_t start, end;
   long sum;
   
   start = clock();
   sum = 1;
   for (int i = 0; i < DIM; i++) {
      for (int j = 0; j < DIM; j++) {
         large[i][j] = i * j;
         
      }
   }
   end = clock();
   printf("Row major access took %f seconds\n", (end - start) / (double)CLOCKS_PER_SEC);

   start = clock();
   sum = 1;
   for (int j = 0; j < DIM; j++) {
      for (int i = 0; i < DIM; i++) {
         large[i][j] = i * j;
      }
   }
   end = clock();
   printf("Column major access took %f seconds\n", (end - start) / (double)CLOCKS_PER_SEC);
   system("pause");
}