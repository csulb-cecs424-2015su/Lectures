public class Strings {
   public static void main(String[] args) {
      // In Java, strings are also internally arrays of characters, but Java
      // uses Unicode encoding (2 bytes for each character; the char type in
      // Java is 2 bytes). 
      
      // Java "interns" string literals into static memory, though we can't
      // really see its address.
      String s = "Hello";
      String s2 = "Hello";
      
      // comparing strings with == tests if they point to the same string in 
      // memory, so this statement should be true:
      if (s == s2) {
         System.out.println("The strings are equal!");
      }
      
      // But if we do this
      String s3 = "He" + "ll" + "o";
      if (s == s3) {
         
         
      }
      
      // How about this?
      String sub = s3.substring(0, 3) + "lo";
      if (s == sub) {
         System.out.println("What about this one?");
      }
   }
   
}
