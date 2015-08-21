using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dictionaries {
   class Program {
      static void Main(string[] args) {
         var film = new Dictionary<string, object>();
         film["title"] = "Wall-E";
         film["year"] = 2008;
         film["produced-by"] = "Jim Morris";
         film["production-company"] = "Pixar Animation Studios";
         film["budget"] = 180000000;
         film["earnings"] = 521300000;
         film["running-time"] = 98;

         // retrieve a key
         Console.WriteLine(film["title"]);

         var disney = new List<Dictionary<string, object>>();
         disney.Add(film);

         film = new Dictionary<string, object>();
         film["title"] = "Finding Nemo";
         film["year"] = 2003;
         film["produced-by"] = "Graham Walters";
         film["production-company"] = "Pixar Animation Studios";
         film["budget"] = 94000000;
         film["earnings"] = 936700000;
         film["running-time"] = 100;
         disney.Add(film);

         film = new Dictionary<string, object>();
         film["title"] = "The Lion King";
         film["year"] = 1994;
         film["produced-by"] = "Don Hahn";
         film["production-company"] = "Walt Disney Feature Animation";
         film["budget"] = 45000000;
         film["earnings"] = 987500000;
         film["running-time"] = 88;
         disney.Add(film);

         var filtered = new List<Dictionary<string, object>>();
         foreach (var f in disney) {
            if (f["production-company"] .ToString() == "Pixar Animation Studios")
               filtered.Add(f);
         }
         filtered.Sort((a, b) => ((int)a["budget"]).CompareTo(b["budget"]));

         foreach (var f in filtered) {
            Console.WriteLine(f["title"] + ": " + f["budget"]);
         }
         
      }
   }
}
