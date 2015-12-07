#include <iostream>

using namespace std;

int global = 1;

int F() {
   global *= 2;
   return global;
}

int G() {
   global += 5;
   return global;
}

void H(int a, int b) {
   cout << a * b << endl;
}

int main() {
   cout << F() * G() << endl;
   
   global = 1;
   H(F(), G());

   // Why the difference?




   // Why is this a feature of C++?




   // WWJD? (What Would Java Do?)





}