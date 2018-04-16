import java.util.Scanner;
import java.util.Random;

public class RockPaperScissors
{

   public String getUserChoice()
   {
      
      Scanner in = new Scanner (System.in);
      
      String UserChoice = "";
      
      System.out.println("Rock, Paper, or Scissors?");
      UserChoice = in.nextLine();
      
      if (!UserChoice.equalsIgnoreCase("Rock") && !UserChoice.equalsIgnoreCase("Paper") && !UserChoice.equalsIgnoreCase("Scissors"))
      {
         do
         {
         
            System.out.println("Not Valid Input. Try again. Rock, Paper, or Scissors?");
            UserChoice = in.nextLine();
         }
         while(!UserChoice.equalsIgnoreCase("Rock") && !UserChoice.equalsIgnoreCase("Paper") && !UserChoice.equalsIgnoreCase("Scissors"));
      }//end if
   
         
         return UserChoice;
   
   
   }//end method


///////////////////////////////////////////////////
   public String getCPUChoice()
   {
      Random r = new Random();
      int CPUnum = ' ';
      String CPUChoice = "";
      
      //Getting Random #
      CPUnum = r.nextInt(2);
      
         if (CPUnum == 0)
         {
            CPUChoice = "Rock" ;
         }
         
         if (CPUnum == 1)
         {
            CPUChoice = "Paper";
         }
         
         if (CPUnum == 2)
         {
            CPUChoice = "Scissors";
         }
       
         return CPUChoice;
   
   
   }//end method
   
  
///////////////////////////////////////////////////////
   public String pickWinner(String CPUChoice, String UserChoice)
   {
      String winner = "";
      
                 if ((UserChoice.equalsIgnoreCase("Rock") && CPUChoice.equalsIgnoreCase("Scissors")) || (UserChoice.equalsIgnoreCase("Paper") && CPUChoice.equalsIgnoreCase("Rock")) || (UserChoice.equalsIgnoreCase("Scissors") && CPUChoice.equalsIgnoreCase("Paper")))
                 {
                  winner = "User";
                 }
                 
                 if ((UserChoice.equalsIgnoreCase("Scissors") && CPUChoice.equalsIgnoreCase("Rock")) || (UserChoice.equalsIgnoreCase("Rock") && CPUChoice.equalsIgnoreCase("Paper")) || (UserChoice.equalsIgnoreCase("Paper") && CPUChoice.equalsIgnoreCase("Scissors")))
                 {
                  winner = "Computer";
                 }
                 
                 if ((UserChoice.equalsIgnoreCase("Scissors") && CPUChoice.equalsIgnoreCase("Scissors")) || (UserChoice.equalsIgnoreCase("paper") && CPUChoice.equalsIgnoreCase("paper")) || (UserChoice.equalsIgnoreCase("Rock") && CPUChoice.equalsIgnoreCase("Rock")))
                 {
                  winner = "Tie";
                 }
                 
                 return winner;
   
   
   
   
   
   
   }//end method


}//end class