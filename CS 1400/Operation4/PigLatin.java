/****************************************************************

* PigLatin.java

* River Schenck

*

* This program translates from english to piglatinhapp

*****************************************************************/

import java.util.Scanner;

public class PigLatin
{
   public static void main (String[]args)
   {
      Scanner in = new Scanner (System.in);
      String userWord = ""; //This is the original word
      String pigWord = ""; // This is the piglatin word
      String f = " ";
      String n = " ";
      String corrected = " ";
      int index = 0;
      char ch = ' '; //Temp character holder
      
      
      //Welcoming statement
      System.out.println("Welcome to the Pig Latin Translator!");
      
      //Gettng user input
      System.out.println("");//Extra line just to make it look good
      System.out.println("Please enter a word:");
      userWord = in.nextLine();
          
         do
         {       
         //Getting first letter        
         f = userWord.substring(0,1); 
         corrected = userWord;
         
         
            if(!(f.equalsIgnoreCase("a")
            || f.equalsIgnoreCase("e")
            || f.equalsIgnoreCase("i")
            || f.equalsIgnoreCase("o")
            || f.equalsIgnoreCase("u")
            || f.equalsIgnoreCase("y")))
            {
   
            do
            {   
            index++;     
            corrected = corrected.substring(1);
            n = corrected.substring(0,1);
            
                   
            }while(!(n.equalsIgnoreCase("a")
            || n.equalsIgnoreCase("e")
            || n.equalsIgnoreCase("i")
            || n.equalsIgnoreCase("o")
            || n.equalsIgnoreCase("u")
            || n.equalsIgnoreCase("y")));
               
               System.out.println("The translation is: " + corrected + userWord.substring(0,index) + "ay");
        
            }
            
            
            
                   else
                   {
                   System.out.println("The translation is: " + userWord + "way");
                   }
                     System.out.println(" "); //spacing for aesthetics
                     System.out.println("Enter another word to be translation (or press Q to quit): ");
                     userWord = in.nextLine();                   
                     
                     index = 0;
      }while(!userWord.equalsIgnoreCase("Q"));
      
            }
}