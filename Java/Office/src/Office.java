
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Office {
   private final static ArrayList<String> students = new ArrayList<>();
   private final static ArrayList<String> queue = new ArrayList<>();
   private static boolean helping = false;
   private final static Object helpingLock = new Object();

   public static void main(String[] args) throws InterruptedException {
      String[] names = new String[]{"Ada", "Barbara", "Charlie", "Donald",
         "Elaine", "Frank", "George"};
      Thread[] threads = new Thread[names.length];
      int i = 0;
      for (final String n : names) {
         threads[i++] = new Thread(new Runnable() {
            public void run() {
               try {
                  student(n);
               } catch (InterruptedException ex) {
                  Logger.getLogger(Office.class.getName()).
                   log(Level.SEVERE, null, ex);
               }
            }
         });
      }
      for (Thread t : threads) {
         t.start();
      }
      for (Thread t : threads) {
         t.join();
      }
      System.out.println("All done!");
   }

   private static void student(String name) throws InterruptedException {
      int sleepTime = 0;
      // try to enter the room. 
      while (true) {
         synchronized (students) {
            boolean empty = queue.isEmpty(),
             isFirst = !empty && queue.get(0).equals(name);
            if (students.size() < 3 && (empty || isFirst)) {
               sleepTime = (int) (Math.random() * 7000) + 3000;
               System.out.println(name + " entered the room and will work for "
                + sleepTime + " ms.");

               students.add(name);
               if (isFirst) {
                  queue.remove(0);
               }
               break;
            }
            if (!queue.contains(name)) {
               queue.add(name);
               System.out.println("Queue now: " + queue);
            }
            sleepTime = (1 + queue.indexOf(name)) * 1000;
         }

         System.out.println(name + " tried to enter the room but it was full, "
          + "and must sleep " + sleepTime + " ms.");

         Thread.sleep(sleepTime);
      }

      // at this point, the student has entered the office, either because
      // no one was waiting or because they were first in line.
      Thread.sleep(sleepTime);

      // Ask for help.
      while (true) {
         synchronized (helpingLock) {
            if (!helping) {
               helping = true;
               sleepTime = (int)(Math.random() * 5000 + 2000);
               System.out.println(name + " is getting help for " + sleepTime +
                " ms.");
               break;
            }
            else {
               System.out.println(name + " needs help but has to wait.");
            }
         }
         Thread.sleep(1000);
      }
      
      // Ready to receive help.
      Thread.sleep(sleepTime);
      synchronized(helpingLock) {
         helping = false;
      }

      // Done working, leave the room.
      synchronized (students) {
         students.remove(name);
      }
      System.out.println(name + " left the room.");
   }
}
