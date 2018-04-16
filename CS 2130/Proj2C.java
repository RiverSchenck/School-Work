import java.io.*;
import java.util.Scanner;
public class Proj2C
{

   public static void main(String args[])
   {
   Scanner in = new Scanner(System.in);
   
   System.out.println("Enter N1: ");
   int N1 = in.nextInt();
   
   System.out.println("Enter N2: ");
   int N2 = in.nextInt();
   
        
   
         for(int i = N1; i <= N2;i++)
         {
            OddInt(i);
            SquareInt(i);
            SymmetricInt(i);
            KNumber(i);
         
            if(KNumber(i) == true)
            {
               System.out.println(i + " is a Knumber");
            }
         }
   }


   public static boolean OddInt(long x)
   {
   boolean logical;
   
      if(x % 2 == 0)
      {
      logical = false;
      }
      else
      {
      logical = true;
      }
   
         return logical;
   
   }
   
   
   public static boolean SquareInt(long x)
   {
      boolean logical;
   
        int sqrt = (int) Math.sqrt(x);
        if(sqrt*sqrt == x) 
        {
            logical = true;
        }
        else
        {
        logical = false;
        }
        
      return logical;
   }
   
   
   
   public static boolean SymmetricInt(long x)
   {
      boolean logical;
   
       
         long y = 0;
         long z = x;
         
         while( z != 0 )
         {
          y = y * 10;
          y = y + z%10;
          z = z/10;
         }
        
            if(y == x)
            {
            logical = true;
            }
            else
            {
            logical= false;
            }

         return logical;
   
   }
   
   
    public static boolean KNumber(long x)
   {
      boolean logical;
   
       if(OddInt(x) == true && SquareInt(x) == true && SymmetricInt(x) == true)
       {
       logical = true;
       }
       else
       {
       logical = false;
       }
        
         return logical;
   
   }
   
   
   
}