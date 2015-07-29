#include <iostream>
#include <memory>

using std::cout;
using std::endl;

void A();
std::shared_ptr<int> B();

int main() {
   A();
   
   std::shared_ptr<int> x = B();
   // A shared_ptr uses reference counting to delete the heap value when all
   // references to it are lost.

   if (true) {
      std::shared_ptr<int> y = x;
      // now there are two references to the int 100.
      // when y goes out of scope, the reference count to the int is reduced.
      // but because there is still one reference, it is not freed.
   }
}

void A() {
   std::unique_ptr<int> pi(new int(10));
   cout << *pi << endl;

   // pi is on the stack, pointing to a value on the heap. when pi goes out of
   // scope, the value it points to will be automatically deleted.
   // This is in contast to raw pointers to values on the heap.
}

std::shared_ptr<int> B() {
   return std::shared_ptr<int>(new int(100));
}