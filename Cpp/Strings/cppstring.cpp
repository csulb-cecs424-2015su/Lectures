#include <string>
#include <iostream>

using std::cout;
using std::endl;

// demonstrate the std::string class.
int main(int argc, char *argv[]) {
   // In C++, as in C, string literals are const char pointers terminated by 
   // the special character '\0'.

   const char *s = "Hello, world!";

   // The std::string class wraps a mutable C-string.
   std::string str = s; // the std::string constructor can take a C-string

   cout << "C-string is at " << (void*)s << endl;
   cout << "std::string is at " << &str << "; its buffer is at " << (void*)str.c_str() << endl;

   // C++ strings are mutable.
   str.append(" Long string gets appended here.");
   cout << "Now the std::string buffer is at " << (void*)str.c_str() << endl;

   std::string str2 = str;
   cout << "str2 is at " << &str2 << "; its buffer is at " << (void*)str2.c_str() << endl;

   // Because std::strings are mutable, making a copy of a string requires 
   // duplicating its buffer for the new value. This can be time consuming.
   
   // This also applies to substrings.
   std::string str3 = str.substr(0, 4);
   cout << "str3 is at " << &str3 << "; its buffer is at " << (void*)str3.c_str() << endl;

}