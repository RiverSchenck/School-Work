import java.util.Scanner;
class ReverseNumber
{
   public static void main(String args[])
   {
      int x, y = 0;
      System.out.println("Enter the number to reverse");
      Scanner in = new Scanner(System.in);
      x = in.nextInt();
      while( x != 0 )
      {
          y = y * 10;
          y = y + x%10;
          x = x/10;
      }
      System.out.println("Reverse of entered number is "+y);
   }
}