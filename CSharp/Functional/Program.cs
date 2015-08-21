using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Functional {
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

         
         // Sum the budgets of the films
         var budgetSum = disney.Select(f => (int)f["budget"]).Aggregate((sum, next) => sum + next);
         Console.WriteLine("Budgets: {0}", budgetSum);
         
         // Sort the Pixar films by budget
         var pixarSorted = disney
            .Where(f => (string)f["production-company"] == "Pixar Animation Studios")
            .OrderBy(f => (int)f["budget"]);

         var pixar = (
            from f in disney
            where f["production-company"] == "Pixar"
            orderby (int)f["budget"]);
      }
   }
}
