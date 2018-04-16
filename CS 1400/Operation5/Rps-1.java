/****************************************************************

* Rps.java

* River Schenck

*

* This program lets you play Rock Paper Scissors against the computer

*****************************************************************/
import java.util.Scanner;
import java.util.Random;
   
   public class Rps
   {
      public static void main (String[]args)
      {
      
      Scanner in = new Scanner (System.in);
      Random r = new Random ();
      
      int numGames = 0;//Number of games to play
      String userPick = "";
      int cpuNum = 0;
      String cpuPick = "";
      int userWins = 0;
      int cpuWins = 0;
      
      
      
      //Intro
      System.out.println("Welcome to Rock, Paper, Scissors!");
      System.out.println();//space for aesthetics
      System.out.println("Please enter the number of rounds");//split to make it look better
      System.out.println("you would like to play: ");
      numGames = in.nextInt();
      
       if (numGames % 2 == 0)
         {
          do
          {
            System.out.println("Sorry, you need to enter an odd number.");
            System.out.println();
            System.out.println("Please try again: "); //Seperated to make it look better
            numGames = in.nextInt();
          }while (numGames % 2 == 0);
         } 
      
      
      //Flush the buffer
        in.nextLine();
        
        
      //Playing the game
      for (int i = 1; i <= numGames; i++)
      {
        

        //Users Pick
        System.out.println("Rock, Paper, or Scissors?: ");
        userPick = in.nextLine();
         
           //Check if user input is valid
           if (!userPick.equalsIgnoreCase("rock") && !userPick.equalsIgnoreCase("paper") && !userPick.equalsIgnoreCase("scissors"))
           {
           do
           {
               if (userPick.equalsIgnoreCase("spock"))
               {
               System.out.println("Spock is the ultimate, but maintains an");
               System.out.println("unfair advantage and is, therefore, not allowed.");
               System.out.println();
               System.out.println("Rock, Paper, or Scissors?: ");
               userPick = in.nextLine();
               }
               else 
               {
               System.out.println("Sorry, " + userPick + " is not a valid entry.");
               userPick = in.nextLine();
               }
           }while (!userPick.equalsIgnoreCase("rock") && !userPick.equalsIgnoreCase("paper") && !userPick.equalsIgnoreCase("scissors") && !userPick.equalsIgnoreCase("spock"));
           
           }       
           
           
              //Get computers choice
              cpuNum = r.nextInt(3)+1;
              
              if (cpuNum == 1)
              {
              cpuPick = "Rock";
              }
              if (cpuNum == 2)
              {
              cpuPick = "Paper";
              }
              if (cpuNum == 3)
              {
              cpuPick = "Scissors";
              }
             
              
                 //Telling Who won
                 if ((userPick.equalsIgnoreCase("Rock") && cpuPick.equalsIgnoreCase("Scissors")) || (userPick.equalsIgnoreCase("Paper") && cpuPick.equalsIgnoreCase("Rock")) || (userPick.equalsIgnoreCase("Scissors") && cpuPick.equalsIgnoreCase("Paper")))
                 {
                  System.out.println("Computer chooses " + cpuPick + ". You win!");
                  userWins++; 
                 }
                 
                 if ((userPick.equalsIgnoreCase("Scissors") && cpuPick.equalsIgnoreCase("Rock")) || (userPick.equalsIgnoreCase("Rock") && cpuPick.equalsIgnoreCase("Paper")) || (userPick.equalsIgnoreCase("Paper") && cpuPick.equalsIgnoreCase("Scissors")))
                 {
                  System.out.println("Computer chooses " + cpuPick + ". You lose.");
                  cpuWins++;
                 }
                 
                 if ((userPick.equalsIgnoreCase("Scissors") && cpuPick.equalsIgnoreCase("Scissors")) || (userPick.equalsIgnoreCase("paper") && cpuPick.equalsIgnoreCase("paper")) || (userPick.equalsIgnoreCase("Rock") && cpuPick.equalsIgnoreCase("Rock")))
                 {
                  System.out.println("Computer chooses " + cpuPick + ". It's a tie.");
                 }
                 
            }     
                  System.out.println();
                  System.out.println("User Wins: " + userWins);
                  System.out.println();
                  System.out.println("Computer wins: " + cpuWins);
                  System.out.println();
               
                  
                     if (userWins > cpuWins)
                     {
                        System.out.println("User wins the game!");
                     }
                     
                     else
                     {
                        System.out.println("Computer wins the game!");
                     }
            
                     
      
      }
   
   }
