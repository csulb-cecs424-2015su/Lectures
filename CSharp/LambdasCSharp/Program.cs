using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LambdasCSharp {
   class Program {
      static void Main(string[] args) {
         // an Action is a method with a void return type.
         Action f = () => { Console.WriteLine("Hello from an anonymous function!"); };
         f();

         // a Func is a method with a non-void return type.
         Func<int, int> g = (a) => { return a + 13; };
         Console.WriteLine(g(5));

         // Do not need to explicitly capture variables from outside scope.
         int outer1 = 10;
         Func<int, int> h = (a) => { return a + outer1; };

         Func<int, int> i = ReturnFunction();
         Console.WriteLine(i(5)); // how is this different than the C++ example? Can you explain?
      }

      static Func<int, int> ReturnFunction() {
         int local = 10;
         return (a) => { return a * local; };
      }
   }
}
