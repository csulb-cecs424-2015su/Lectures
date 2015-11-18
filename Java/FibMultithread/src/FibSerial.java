
import java.util.ArrayList;
// Calculate a large fibonacci number three times in serial (one after 
// the other).
public class FibSerial {
   // Standard non-tail call recursive fibonacci method.
   public static int fibonacci(int n) {
      if (n == 0 || n == 1)
         return 1;
      return fibonacci(n-1) + fibonacci(n-2);
   }

   public static void main(String[] args) {
      // Goal: end up with a list of 3 numbers, each being the same large
      // fibonacci number.
      ArrayList<Integer> results = new ArrayList<>();
      
      // As a single-threaded application, each line will finish before
      // proceeding to the next.
      results.add(fibonacci(42));
      results.add(fibonacci(42));
      results.add(fibonacci(42));
      
      System.out.println("Got " + results.size() + " results.");
   }
}
