public class P1PartB3
{
  public static void main(String args[])
  {
    long X1, X2, Y;
      X1 = Long.parseLong(args[0]);
      X2 = Long.parseLong(args[1]);
      
        Y = GreatesCommonDivisor(X1,X2);
        System.out.println("\n X1, X2 = " + X1 + ", " + X2 + "     Y = " + Y);
      
    
    return;
  }

  public static long GreatesCommonDivisor(long x1,long x2)
  {
      long y = 1;
      long i = 0;
     
         for (i = 1;i<= x1 && i <= x2; i++)
         {
           if (x1 % i == 0 && x2 % i == 0)
           {
           y =i;
           }
         }     
      return(y);
   }
}
