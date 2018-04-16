import java.util.Scanner;

public class betOnce
{
   
  
   
   public void betOnce (int number)
   {
   
   Scanner in = new Scanner(System.in);

   
   
   
   int userpick = ' ';
   
      
   
      
      //Getting number
      System.out.println("Do you want to bet on 1) low or 2) high?");
      userpick = in.nextInt();
      
      System.out.println("The number was " + number);
      if(number >=19)
      {
      if(userpick == 2)
      {
      System.out.println("You Win!");
      }
      if(userpick == 1)
      {
      System.out.println("You Lose!");
      }
      }
      
      
      
      if(number<19)
      {
      if(number==0)
      {
      System.out.println("You Lose!");
      }
      else
      {
      
      if(userpick == 1)
      {
      System.out.println("You Win!");
      }
      
      else
      {
      System.out.println("You Lose!");
      }
      
      }
      }
      
      System.out.println();
     



   
}
}