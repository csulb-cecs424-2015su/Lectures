using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generics {
   class Program {
      static T Maximum<T>(T val1, T val2) where T : IComparable {
         if (val1.CompareTo(val2) > 0)
            return val1;
         return val2;
      }

      static void Main(string[] args) {
         Console.WriteLine(Maximum(5, 10));
         Console.WriteLine(Maximum("Hello", "Goodbye"));

         List<String> strings = new List<string>();
         strings.Add("Hello");
      }
   }
}
