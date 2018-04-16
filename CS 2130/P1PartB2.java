public class P1PartB2
{
  public static void main(String args[])
  {
    long X, Y;
    if(args.length >= 1){
      X = Long.parseLong(args[0]);
      if(X >= 1){
        Y = ReverseNumber(X);
        System.out.println("\n X = " + X + "     Y = " + Y);
      }
    }
    return;
  }

  public static long ReverseNumber(long x)
  {
      long y =0;
   
        while( x != 0 )
      {
          y = y * 10;
          y = y + x%10;
          x = x/10;
      }

      return(y);      
      }
    }
