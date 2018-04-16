/****************************************************************

* Retire.java

* River Schenck

*

* This program calculates when you will retire.

*****************************************************************/
import java.util.*;

   public class Retire  {

      public static void main (String[] args)   {
   
         Scanner input = new Scanner(System.in);
      
           String iMonth="";//Month Born
           int iDay=0;//Day Born
           int iYear=0;//Year Born
           int iRetire=0;//Year Retiring
        
               //Input (Month Born, Day Born, Year Born)
               System.out.print("Enter the month you were born: ");
               iMonth= input.nextLine();
               System.out.print("Enter the day you were born: ");
               iDay= input.nextInt();
               System.out.print("Enter the year you were born: ");
               iYear= input.nextInt();
               
                  //Calculation and Output
                  iRetire= (iYear + 67);
                  System.out.println("You will retire on " + iMonth + " " + iDay+","+ iRetire + ".");
            
         
      }

}
         