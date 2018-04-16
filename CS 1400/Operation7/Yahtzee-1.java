/****************************************************************

* Yahtzee.java

* River Schenck

*

* This program plays Yahtzee
*****************************************************************/

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Random;


public class Yahtzee
{

   public static void main (String[] args)
   {
   
      Scanner in = new Scanner (System.in);
      Random r = new Random ();
      
      Integer[] dice = new Integer[5];
      
      dice[0] = (r.nextInt(6) +1);
      dice[1] = (r.nextInt(6) +1);
      dice[2] = (r.nextInt(6) +1);
      dice[3] = (r.nextInt(6) +1);
      dice[4] = (r.nextInt(6) +1);
      
      String userroll = "";
      String userinput = "";
      int usernumber = ' ';
      int dicelength = 5;
      
      //Welcoming the user
      System.out.println("Welcome to the Yahtzee game!");
      System.out.println("Prepare yourself for the first roll!");
      System.out.println();
      
           
      //Printing dice rolls
      for (int i = 0; i < dice.length; i++)
      {
      System.out.println("Dice " + (i+1) + ": " + dice[i]);
      }
      
      //Another small delay
      try 
      {
        Thread.sleep(2000);
      } 
      catch (InterruptedException ie)
      {
        System.out.println("Scanning...");
      } 
      
      
      //Go for 3 rounds
      for (int t = 0; t < 3; t++)
      {      
      
         //Reroll Options Print
         System.out.println();
         System.out.println("There are 5 dice. Pick which die");
         System.out.println("you would like to reroll.");
         System.out.println("Type 1,2,3,4,5 to pick.");     
         
         //Seeing which dice to reroll
         userroll = in.nextLine();
         
            //Checking each die for reroll
            if (userroll.contains("1"))
            {
               dice[0] = (r.nextInt(6) +1);
            }
            
            if (userroll.contains("2"))
            {
               dice[1] = (r.nextInt(6) +1);
       
            }
            
             if (userroll.contains("3"))
            {
               dice[2] = (r.nextInt(6) +1);
            }
            
              if (userroll.contains("4"))
            {
               dice[3] = (r.nextInt(6) +1);
            }
            
             if (userroll.contains("5"))
            {
               dice[4] = (r.nextInt(6) +1);
            }
               
               for (int i = 0; i < dice.length; i++)
               {
                  System.out.println("Dice " + (i+1) + ": " + dice[i]);
               }
      }               
     
      
      //Cheater Mode
      System.out.println();
      System.out.println("Cheater Mode? Enter Y or N.");
      
      userinput = in.nextLine();
      
      while (!userinput.equalsIgnoreCase("Y") && !userinput.equalsIgnoreCase("N"))
      {
         System.out.println("Unknown. Enter Y or N.");
         userinput = in.nextLine();
      } 
      
      
      
      if (userinput.equalsIgnoreCase("Y"))
      {
         //Dice 1
         System.out.println("Enter Dice 1:");
         usernumber = in.nextInt();
         dice[0] = usernumber;

         
         //Dice 2
         System.out.println("Enter Dice 2:");
         usernumber = in.nextInt();
         dice[1] = usernumber;
      
         //Dice 3
         System.out.println("Enter Dice 3:");
         usernumber = in.nextInt();
         dice[2] = usernumber;
         
         //Dice 4
         System.out.println("Enter Dice 4:");
         usernumber = in.nextInt();
         dice[3] = usernumber;
         
         //Dice 5
         System.out.println("Enter Dice 5:");
         usernumber = in.nextInt();
         dice[4] = usernumber;         
         }			
      
         //Determining What Was Won
         int one = 0;
         int two = 0;
         int three = 0;
         int four = 0;
         int five = 0;
         int six = 0;

         
         for(int i=0; i < dicelength; i++)
         {
            if(dice[i] == 1)
            {
               one++; 
            }
            else if(dice[i] == 2)
            {
               two++;
            }
             else if(dice[i] == 3)
            {
               three++;
            }
             else if(dice[i] == 4)
            {
               four++;
            }
             else if(dice[i] == 5)
            {
               five++;
            }
             else if(dice[i] == 6)
            {
               six++;
            }                    
         }
             
             
             if (one == 5 || two == 5 || three == 5 || four == 5 || five == 5 || six == 5)
             {
               System.out.println("YAHTZEE!!!!!");
             }
             
             else if ((one == 1 && two == 1 && three == 1 && four == 1 && five == 1) || (two == 1 && three == 1 && four == 1 && five == 1 && six == 1))
             {
               System.out.println("LARGE STRAIGHT!");
             }
             
             else if ((one == 1 && two == 1 && three == 1 && four == 1) || (two == 1 && three == 1 && four == 1 && five == 1) || (three == 1 && four == 1 && five == 1 && six == 1))
             {
               System.out.println("SMALL STRAIGHT!");
             }
             
             else if (one == 4 || two == 4 || three == 4 || four == 4 || five == 4 || six == 4)
             {
               System.out.println("Four Of A Kind!");
             }
             
             if ((one == 3 || two == 3 || three == 3 || four == 3 || five == 3 || six == 3) && (one == 2 || two == 2 || three == 2 || four == 2 || five == 2 || six == 2))
             {
               System.out.println("Full House!");
             }
             else if (one == 3 || two == 3 || three == 3 || four == 3 || five == 3 || six == 3)
             {
               System.out.println("Three Of A Kind!");
             }
             
                 
                     
                     
            
      
      
   
   
   }


}