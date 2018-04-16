public class P1PartB5
{
  public static void main(String args[])
  {
    long X, Y;
      X = Long.parseLong(args[0]);
      
      Y = Recursion(X);
        System.out.println("Y= " + Recursion(X));
      
    
    return;
  }


  public static long Recursion2(long x)
  {
      
      if (x <= 1)
          return 1;
      else
          return (2* Recursion(x-1));
      

   }
   
     public static long Recursion(long x)
  {
      
      if (x <= 1)
          return 1;
      else
          return (-2*Recursion2(x-2));
      

   }

}
//2*f(X-1) – 2*f(X-2)