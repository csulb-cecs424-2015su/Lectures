#include <iostream>
#include <stdexcept>

void B(int a) {
   int local;
   throw std::out_of_range("this is an exception");
}

void A(int x) {
   int y;
   B(x);
}

int main() {

   try {
      A(10);
   }
   catch (std::exception &ex) {
      std::cout << ex.what() << std::endl;
   }
}
