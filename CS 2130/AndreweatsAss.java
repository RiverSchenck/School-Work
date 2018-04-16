import java.util.*;

public class AndreweatsAss

{


   public static void main(String args[])
   {
      
      Scanner in = new Scanner(System.in);
   
      double weightInPounds = 0;
      double heightInInches = 0;
      boolean loop = true;
      
      
      
      while(loop){
      
                  System.out.print("Enter height in inches: ");
                 
                  
                   try
                   {
                  
                        in.reset();
                        heightInInches = in.nextDouble();
                        
                        
                           if(heightInInches>0)
                           {
                               break;
                           }
                           
                           else
                           {
                               System.out.println("Invalid Inches value. Must be a positive number.");
                               System.out.println();
                           }
                        
                       
                    }
                    
                    catch (InputMismatchException e)
                    {
                        System.out.println("Invalid Inches value. Must be a decimal number.");
                        System.out.println();
                        
                        in.next();
                    }                
              }//while loop end
                

         while(loop){
   
               System.out.print("Enter weight in pounds: ");
              
               
                try
                {
               
                     in.reset();
                     weightInPounds = in.nextDouble();
                     
                     
                        if(heightInInches>0)
                        {
                            break;
                        }
                        
                        else
                        {
                            System.out.println("Invalid Inches value. Must be a positive number.");
                            System.out.println();
                        }
                     
                    
                 }
                 
                 catch (InputMismatchException e)
                 {
                     System.out.println("Invalid Pounds value. Must be a decimal number.");
                     System.out.println();
                     
                     in.next();
                 }                
           }//while loop end
           
           
           //Output
           System.out.println("Height = " + heightInInches + "\"");
           System.out.println("Weight = " + weightInPounds + "pounds");
           System.out.println("Body mass index = " + ((704 * weightInPounds)/(heightInInches * heightInInches)));

      
   }

}//class end