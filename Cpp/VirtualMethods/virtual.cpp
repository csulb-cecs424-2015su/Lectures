#include <iostream>
using namespace std;

// Two classes with identical contents, except one has a virtual method.
class A {
public:
   int X;
   void Something() {}
};

class B {
public:
   int X;
   virtual void Something() { cout << "B is something: " << X << endl; }
};

int main() {
   A a;
   a.X = 10;
   B b;
   b.X = 100;

   cout << "sizeof A: " << sizeof(A) << endl;
   cout << "sizeof B:" << sizeof(B) << endl;
   // Why are these not the same???

   cout << "Address of a: " << &a << "; address of a.x: " << &a.X << endl;
   cout << "Address of b: " << &b << "; address of b.x: " << &b.X << endl;
   // Why is there a 4 byte gap between &b and &b.X, but not for &a and &a.X?

}