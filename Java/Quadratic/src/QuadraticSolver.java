// Show a terrible horrible way of implementing the quadratic formula.
// MANY of you have written code like this recently!
public class QuadraticSolver {
   private double mA, mB, mC;
   private int mNumberOfSolutions;
   private double mSolution1, mSolution2;
   
   public QuadraticSolver() {}
   
   public void setA(double a) {
      mA = a;
   }
   
   public void setB(double b) {
      mB = b;
   }
   
   public void setC(double c) {
      mC = c;
   }
   
   public void solve() {
      double descriminant = mB * mB - 4 * mA * mC;
      if (descriminant < 0) 
         mNumberOfSolutions = 0;
      else if (descriminant == 0) {
         mNumberOfSolutions = 1;
         mSolution1 = -mB / (2 * mA);
      }
      else {
         mNumberOfSolutions = 2;
         double sqrt = Math.sqrt(descriminant);
         mSolution1 = (-mB + sqrt) / (2 * mA);
         mSolution2 = (-mB - sqrt) / (2 * mA);
      }
   }
   
   public int getNumberOfSolutions() {
      return mNumberOfSolutions;
   }
   
   public double getSolution1() {
      return mSolution1;
   }
   
   public double getSolution2() {
      return mSolution2;
   }
   
}
