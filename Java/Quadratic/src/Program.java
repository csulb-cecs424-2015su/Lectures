
public class Program {
   public static void main(String[] args) {
      QuadraticSolver solver = new QuadraticSolver();
      solver.setA(3);
      solver.setB(-13);
      solver.setC(-10);
      solver.solve();
      
      if (solver.getNumberOfSolutions() == 0) {
         System.out.println("No solution.");
      }
      else if (solver.getNumberOfSolutions() == 1) {
         System.out.println("One solution: " + solver.getSolution1());
      }
      else {
         System.out.println("Two solutions: " + solver.getSolution1() + ", " +
          solver.getSolution2());
      }
   }

}
