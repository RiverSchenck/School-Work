import java.util.*;

public class GCD
{
  public static void main(String args[])
  {
  
   Scanner input = new Scanner(System.in);
   
    long x, B, y;
    System.out.println("Enter x1: ");
      x = input.nextInt();
    System.out.println("Enter base: ");
      B = input.nextInt();
      
      long z = 0,i = 0;
      double d = 0;
      
      while (x != 0)
      {
         i++;
         z = x%B;
         x = x/B;
         d = d + (z*Math.pow(10,i -1));
         System.out.println(d);
      }
    
  
    y = (new Double(d)).longValue();
    System.out.println(y);
 
  }
}
