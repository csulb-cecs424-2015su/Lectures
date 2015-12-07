#include <stdio.h>
#include <stdbool.h>

struct Element {
   char name[2];
   int atomic_number;
   double atomic_weight;
   bool metallic;
};


int main() {
   int temp;
   struct Element gold;
   gold.name[0] = 'A';
   gold.name[1] = 'u';
   gold.atomic_number = 79;
   gold.atomic_weight = 196.966569;
   gold.metallic = true;

   printf("Element struct is %d bytes\n", sizeof(struct Element));

   printf("gold is at \t%p\n\n", &gold);
   printf("name: \t\t%p; \nnumber: \t%p; \nweight: \t%p; \nmetallic: \t%p\n",
      &gold.name, &gold.atomic_number, &gold.atomic_weight, &gold.metallic);
   printf("\nlocal temp is at \t%p\n\n", &temp);
   // What does gold look like in memory?
   // How do each of the lines above know where their corresponding values are?
}