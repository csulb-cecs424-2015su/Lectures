
import java.util.ArrayList;

// Perform the same work as FibSerial, but in three different threads, then
// collect the results.
public class FibParallel {

   public static int fibonacci(int n) {
      if (n == 0 || n == 1) {
         return 1;
      }
      return fibonacci(n - 1) + fibonacci(n - 2);
   }

   public static void main(String[] args) {
      final ArrayList<Integer> results = new ArrayList<>();

      ArrayList<Thread> threads = new ArrayList<>();
      threads.add(getThread(results));
      threads.add(getThread(results));
      threads.add(getThread(results));
      for (Thread t : threads) {
         t.start();
      }
      for (Thread t : threads) {
         try {
            t.join();
         } catch (InterruptedException ex) {
         }
      }
      System.out.println("Results: " + results.size());
      for (Integer n : results) {
         System.out.println(n);
      }
   }

   // Create, but do not start, a thread to run one fib calculation.
   public static Thread getThread(ArrayList<Integer> results) {
      return new Thread(new FibThread(results));
   }

   // This class encapsulates a method to calculate one fib number, with a 
   // reference to an ArrayList where the result should be saved.
   static class FibThread implements Runnable {

      private final ArrayList<Integer> results;

      public FibThread(ArrayList<Integer> results) {
         this.results = results;
      }

      @Override
      public void run() {
         int n = fibonacci(42);
         synchronized (results) {
            results.add(n);
         }
      }
   }

}
