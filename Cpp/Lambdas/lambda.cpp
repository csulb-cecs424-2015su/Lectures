#include <iostream>
#include <functional>

using std::cout;
using std::endl;

std::function<int(int)> ReturnFunc();

int main() {
   auto f = []() {
      cout << "Hello from an anonymous function!" << endl;
   };
   // Examine the type of f
   
   f();


   auto g = [](int a) {
      return a + 13;
   };
   // What is the return type of g? How is that determined?

   cout << g(5) << endl;


   // So what's with the square brackets?

   int outer1 = 10, outer2 = 50;
   auto h = [outer1](int a) {
      return a + outer1;
   };

   cout << h(5) << endl;

   // The brackets define a "capture list": explicitly listing which variables
   // from the outer scope should be available inside the lambda.
   // "outer2" cannot be used because it is not captured.

   // What happens if I change outer1 now?
   outer1 = 100;
   cout << h(5) << endl;
   // Still prints 15... why? Think about where outer1 lives, and where h could
   // be returned to (another scope?). So what was actually captured?

   auto i = ReturnFunc();
   cout << i(5) << endl;
}

std::function<int(int)> ReturnFunc() {
   int local = 10;
   auto func = [local](int param) {
      return local * param;
   };

   return func;
}