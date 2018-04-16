import java.util.Scanner;

public class Permutations
{

public static long holding(long in)
   {
   int holding = 1;
   
      for(int i=1; i <= in; i++)
      {
      holding = holding * i;
      }
      
   return holding;
   }
   
public static void main(String args[])
   {
   long n;
   long x;
   Scanner in = new Scanner(System.in);
   System.out.print("Please enter n: ");
   n = in.nextInt();
   System.out.print("Please enter x: ");
   x = in.nextInt();
   System.out.print("Permutations = " + (holding(n)/(holding(n-x))));
   }
   
}