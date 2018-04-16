// Program to calculate the sum of the divisors
// of a positive integer.
public class P1PartB
{
  public static void main(String args[])
  {
    long X, Y;
    if(args.length >= 1){
      X = Long.parseLong(args[0]);
      if(X >= 1){
        Y = SumOfDivisors(X);
        System.out.println("\n X = " + X + "     Y = " + Y);
      }
    }
    return;
  }

  public static long SumOfDivisors(long x)
  {
    long y = 1;
   
    

      for(int i = 2;i * i <= x; ++i)
	   {
		int p = 1;
      
		   while(x % i == 0)
		   {
			   p = p * i + 1;
			   x /= i;	
		   }

		y *= p;
	   }

	   if(x > 1)     
		   y *= 1 + x;
      
      
	  return(y);      
      }
    }
  
