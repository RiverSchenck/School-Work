/****************************************************************

* Higherlower.java

* River Schenck

*

* This program randomly picks a number and you have to guess it.

*****************************************************************/

import java.util.Scanner;
import java.util.Random;

public class Higherlower
   {
     public static void main (String[] args)
     {
      
         Scanner in = new Scanner (System.in);
         Random r = new Random ();
      
          int userPick = 0;  //User picks number 1-100          
          int numberoftries = 0; //Number of tries it takes
          int randomNumber = r.nextInt(99) + 1; //Random Number   
                  
          System.out.println("Welcome to the Higher / Lower game!");
          System.out.println("Try to guess the number between 1 and 100."
);
          //Playing the game         
        
            do{
            //Getting User Selection
            System.out.println("Enter your guess: ");
            userPick = in.nextInt();
            
               //Check for valid input                     
               while (userPick<1 || userPick>=101)
               {
               System.out.println("Sorry, the guess needs to be a number");
               System.out.println("between 1 and 100. Please try again: ");
               userPick = in.nextInt();            
               }    
                      
                  //Calculate if above or below and increase count             
                  numberoftries++;              
                  if (randomNumber > userPick)
                  {
                  System.out.println("The number is higher");               
                  }
                  if (randomNumber < userPick)
                  {
                  System.out.println("The number is Lower");              
                  }
                  if (randomNumber == userPick)
                  {
                  System.out.println("The number was " + randomNumber + "! You guessed correctly! It took you " + numberoftries + " tries.");
                  }          
                               
                  } while (userPick != randomNumber);
         
     }
        
}
      
   