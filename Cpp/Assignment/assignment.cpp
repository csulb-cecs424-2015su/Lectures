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

}