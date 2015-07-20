#include <iostream>
using namespace std;

int main() {
   int val1 = 100;
   int val2 = val1;

   val1 = 200; // what is val2?
               // how was the assignment on line 6 performed?


   int &ref1 = val1;
   ref1 = 300; // what is val1?
               // how was the assignment on line 12 performed?

   int *ptr1 = &val1;
   ptr1 = &val2;
   *ptr1 = 400; // what is val1? val2?
                // is this also "assign by reference"?

}