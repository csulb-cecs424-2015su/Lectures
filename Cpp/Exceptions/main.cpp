#include <iostream>
#include <stdexcept>
#include <string>

void B(int a) {
   int local;
   throw std::out_of_range("this is an exception");
}

void A(int x) {
   try {
      int y;
      B(x);
   }
   catch (std::string &ex) {
      std::cout << "Caught in A()" << std::endl;
   }
}

int main() {

   try {
      A(10);
   }
   catch (std::exception &ex) {
      std::cout << "Caught in main()" << std::endl;
   }
}
