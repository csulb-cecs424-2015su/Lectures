#include <iostream>
using namespace std;

// Demonstrate a binding with a lifetime longer than the object it is bound to.
int& get_int() {
   int input;
   cout << "Enter an integer: ";
   cin >> input;
   return input;
}

int main() {
   int &ref = get_int();
   int x = pow(2, ref);
   cout << "You entered " << ref << "... or did you?" << endl;
}
