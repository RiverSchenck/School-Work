import java.util.Random;
import java.util.Scanner;

public class Roulette
{

   public static void main (String[] args)
   {
   
  
   Scanner in = new Scanner(System.in);
   Random r = new Random();
   int number = r.nextInt(35)+1;
   int playagain = ' ';
   betOnce obj = new betOnce();
   do
   {
   obj.betOnce(number);
   System.out.println("Enter 1 to play again, 2 to quit");
   
   playagain = in.nextInt();
   }
   while(playagain ==1);
   
   
  
   
   
   }



}