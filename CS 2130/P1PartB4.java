public class P1PartB4
{
  public static void main(String args[])
  {
    long X, B, Y;
      X = Long.parseLong(args[0]);
      B = Long.parseLong(args[1]);
      
        Y = BaseB(X,B);
        System.out.println("\n X,  New Base = " + X + ", " + B + "     Y = " + Y);
      
    
    return;
  }

  public static long BaseB(long x,long b)
  {
      long y = 0, z = 0, i = 0;
      double d = 0;
      
      while (x != 0)
      {
         i++;
         z = x%b;
         x = x/b;
         d = d + (z*Math.pow(10,i -1));
      }
    
  
    y = (new Double(d)).longValue();
   

      return(y);   

   }
}
