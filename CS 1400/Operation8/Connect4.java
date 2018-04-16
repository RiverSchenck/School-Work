/****************************************************************

* Connect4.java

* River Schenck

*

* This program plays Connect4 with the computer
*****************************************************************/

import java.util.Scanner;
import java.util.Random;

public class Connect4
{

   public static void main (String[] args)
   {
      Scanner in = new Scanner (System.in);
      Random r = new Random ();
      
      
         String username = ""; //user information
         boolean winner = false; //See if their is a winner
         int sum = ' ';
         int userpick = ' ';
         int comppick = ' ';
         int cc1 = 0;
         int cc2 = 0;
         int cc3 = 0;
         int cc4 = 0;
         int cc5 = 0;
         int cc6 = 0;
         int cc7 = 0;
         
            //Column 1
            int[] c1 = new int[8];
            for (int i = 0; i <= 7; i++) 
            {
            c1[i] = 10;
            }
            
            //Column 2
            int[] c2 = new int[8];
            for (int i = 0; i <= 7; i++) 
            {
            c2[i] = 10;
            }
            
            //Column 3
            int[] c3 = new int[8];
            for (int i = 0; i <= 7; i++) 
            {
            c3[i] = 10;
            }
            
            //Column 4
            int[] c4 = new int[8];
            for (int i = 0; i <= 7; i++) 
            {
            c4[i] = 10;
            }
            
            //Column 5
            int[] c5 = new int[8];
            for (int i = 0; i <= 7; i++) 
            {
            c5[i] = 10;
            }
            
            //Column 6
            int[] c6 = new int[8];
            for (int i = 0; i <= 7; i++) 
            {
            c6[i] = 10;
            }
            
            //Column 7
            int[] c7 = new int[8];
            for (int i = 0; i <= 7; i++) 
            {
            c7[i] = 10;
            }
         
               //Introduction
               System.out.println("Welcome to Connect4! Please enter your name.");
               username = in.nextLine();
               System.out.println();
               int y = 0;
              do
              {
              y++;
              System.out.println(username + " pick a column (1-7).");
              userpick = in.nextInt();
              while(userpick > 7 || userpick < 0)
              {
              System.out.println("Invalid input. Pick a column (1-7).");        
              userpick = in.nextInt();
              }
              
              //check if columns are full
                  
                 if (cc1 > 6)
                 {
                 if(userpick ==1)
                 {do{
                 System.out.println("Column 1 is full.");
                 System.out.println(username + " pick a different column (1-7).");
                 userpick = in.nextInt();
                 }while(userpick ==1);
                 }}
                   if (cc2 > 6)
                 {
                 if(userpick ==2)
                 {do{
                 System.out.println("Column 2 is full.");
                 System.out.println(username + " pick a different column (1-7).");
                 userpick = in.nextInt();
                 }while(userpick ==2);
                 }}
                   if (cc3 > 6)
                 {
                 if(userpick ==3)
                 {do{
                 System.out.println("Column 3 is full.");
                 System.out.println(username + " pick a different column (1-7).");
                 userpick = in.nextInt();
                 }while(userpick ==3);
                 }}
                   if (cc4 > 6)
                 {
                 if(userpick ==4)
                 {do{
                 System.out.println("Column 4 is full.");
                 System.out.println(username + " pick a different column (1-7).");
                 userpick = in.nextInt();
                 }while(userpick ==4);
                 }}
                   if (cc5 > 6)
                 {
                 if(userpick ==5)
                 {do{
                 System.out.println("Column 5 is full.");
                 System.out.println(username + " pick a different column (1-7).");
                 userpick = in.nextInt();
                 }while(userpick ==5);
                 }}
                   if (cc6 > 6)
                 {
                 if(userpick ==6)
                 {do{
                 System.out.println("Column 6 is full.");
                 System.out.println(username + " pick a different column (1-7).");
                 userpick = in.nextInt();
                 }while(userpick ==6);
                 }}
                   if (cc7 > 6)
                 {
                 if(userpick ==7)
                 {do{
                 System.out.println("Column 7 is full.");
                 System.out.println(username + " pick a different column (1-7).");
                 userpick = in.nextInt();
                 }while(userpick ==7);
                 }}
              
                 //Column 1
              
                 if(userpick == 1)
                 {       
                 cc1++;
                 c1[cc1 - 1] = 1;
                 }
 
                 //Column 2
                
                 if(userpick == 2)
                 {       
                 cc2++;
                 c2[cc2 - 1] = 1;
                 }

                 //Column 3
                
                  if(userpick == 3)
                 {       
                 cc3++;
                 c3[cc3 - 1] = 1;
                 }
                 
                 //Column 4
               
                  if(userpick == 4)
                 {       
                 cc4++;
                 c4[cc4 - 1] = 1;
                 }
                 
                 //Column 5
                
                  if(userpick == 5)
                 {       
                 cc5++;
                 c5[cc5 - 1] = 1;
                 }
                 
                 //Column 6
                 
                  if(userpick == 6)
                 {       
                 cc6++;
                 c6[cc6 - 1] = 1;
                 }
                 
                 //Column 7
            
                  if(userpick == 7)
                 {       
                 cc7++;
                 c7[cc7 - 1] = 1;
                 }
                       
        //////////////////Computers turn/////////////////////////
                    comppick = (r.nextInt(7) +1);
                    
                 if (cc1 > 6)
                 {
                 if(comppick ==1)
                 {do{
                 comppick = (r.nextInt(7) +1);
                 }while(comppick ==1);
                 }}
                   if (cc2 > 6)
                 {
                 if(comppick ==2)
                 {do{
                 comppick = (r.nextInt(7) +1);
                 }while(comppick ==2);
                 }}
                   if (cc3 > 6)
                 {
                 if(comppick ==3)
                 {do{
                 comppick = (r.nextInt(7) +1);
                 }while(comppick ==3);
                 }}
                   if (cc4 > 6)
                 {
                 if(comppick ==4)
                 {do{
                 comppick = (r.nextInt(7) +1);
                 }while(comppick ==4);
                 }}
                   if (cc5 > 6)
                 {
                 if(comppick ==5)
                 {do{
                 comppick = (r.nextInt(7) +1);
                 }while(comppick ==5);
                 }}
                   if (cc6 > 6)
                 {
                 if(comppick ==6)
                 {do{
                 comppick = (r.nextInt(7) +1);
                 }while(comppick ==6);
                 }}
                   if (cc7 > 6)
                 {
                 if(comppick ==7)
                 {do{
                 comppick = (r.nextInt(7) +1);
                 }while(comppick ==7);
                 }}
                                 
                 //Column 1
              
                 if(comppick == 1)
                 {       
                 cc1++;
                 c1[cc1 - 1] = 0;
                 }
 
                 //Column 2
                
                 if(comppick == 2)
                 {       
                 cc2++;
                 c2[cc2 - 1] = 0;
                 }

                 //Column 3
                
                  if(comppick == 3)
                 {       
                 cc3++;
                 c3[cc3 - 1] = 0;
                 }
                 
                 //Column 4
               
                  if(comppick == 4)
                 {       
                 cc4++;
                 c4[cc4 - 1] = 0;
                 }
                 
                 //Column 5
                
                  if(comppick == 5)
                 {       
                 cc5++;
                 c5[cc5 - 1] = 0;
                 }
                 
                 //Column 6
                 
                  if(comppick == 6)
                 {       
                 cc6++;
                 c6[cc6 - 1] = 0;
                 }
                 
                 //Column 7
            
                  if(comppick == 7)
                 {       
                 cc7++;
                 c7[cc7 - 1] = 0;
                 }
                 
                 
                 
                 System.out.println();
                 System.out.println("Computer picked " + comppick);
                 
                 
                    //Seeing if there is a winner
                
                 
                 
                 //Column 1
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c1[i + 0] + c1[i + 1] + c1[i + 2] + c1[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!" + sum);
                 }}
                 //Column 2
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c2[i + 0] + c2[i + 1] + c2[i + 2] + c2[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 //Column 3
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c3[i + 0] + c3[i + 1] + c3[i + 2] + c3[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 //Column 4
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c4[i + 0] + c4[i + 1] + c4[i + 2] + c4[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 //Column 5
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c5[i + 0] + c5[i + 1] + c5[i + 2] + c5[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 //Column 6
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c6[i + 0] + c6[i + 1] + c6[i + 2] + c6[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 //Column 7
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c7[i + 0] + c7[i + 1] + c7[i + 2] + c7[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 //C 1,2,3,4
                 for(int i = 0; i <= 5; i++)
                 {
                 sum = (c1[i + 0] + c2[i + 0] + c3[i + 0] + c4[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 //C 2,3,4,5
                 for(int i = 0; i <= 5; i++)
                 {
                 sum = (c2[i + 0] + c3[i + 0] + c4[i + 0] + c5[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 //C 3,4,5,6
                 for(int i = 0; i <= 5; i++)
                 {
                 sum = (c3[i + 0] + c4[i + 0] + c5[i + 0] + c6[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 //C 4,5,6,7
                 for(int i = 0; i <= 5; i++)
                 {
                 sum = (c4[i + 0] + c5[i + 0] + c6[i + 0] + c7[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 //Diagonals
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c1[i + 0] + c2[i + 1] + c3[i + 2] + c4[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c2[i + 0] + c3[i + 1] + c4[i + 2] + c5[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c3[i + 0] + c4[i + 1] + c5[i + 2] + c6[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c4[i + 0] + c5[i + 1] + c6[i + 2] + c7[i + 3]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c4[i + 3] + c5[i + 2] + c6[i + 1] + c7[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c3[i + 3] + c4[i + 2] + c5[i + 1] + c6[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c2[i + 3] + c3[i + 2] + c4[i + 1] + c5[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c1[i + 3] + c2[i + 2] + c3[i + 1] + c4[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 
                 
                 
                 
                 
    //////////////////Seeing if computer won////////////////
                 
                 
                 //Column 1
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c1[i + 0] + c1[i + 1] + c1[i + 2] + c1[i + 3]);                 if(sum == 4)
                 if(sum ==0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 //Column 2
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c2[i + 0] + c2[i + 1] + c2[i + 2] + c2[i + 3]);                 if(sum == 4)
                 if(sum ==0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 //Column 3
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c3[i + 0] + c3[i + 1] + c3[i + 2] + c3[i + 3]);                 if(sum == 4)
                 if(sum ==0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 //Column 4
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c4[i + 0] + c4[i + 1] + c4[i + 2] + c4[i + 3]);                 if(sum == 4)
                 if(sum ==0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 //Column 5
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c5[i + 0] + c5[i + 1] + c5[i + 2] + c5[i + 3]);                 if(sum == 4)
                 if(sum ==0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 //Column 6
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c6[i + 0] + c6[i + 1] + c6[i + 2] + c6[i +3]);                 if(sum == 4)
                 if(sum ==0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 //Column 7
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c7[i + 0] + c7[i + 1] + c7[i + 2] + c7[i + 3]);                 if(sum == 4)
                 if(sum ==0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 //C 1,2,3,4
                 for(int i = 0; i <= 5; i++)
                 {
                 sum = (c1[i + 0] + c2[i + 0] + c3[i + 0] + c4[i + 0]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 //C 2,3,4,5
                 for(int i = 0; i <= 5; i++)
                 {
                 sum = (c2[i + 0] + c3[i + 0] + c4[i + 0] + c5[i + 0]);                 if(sum == 4)
                 if(sum == 4)
                 {
                 winner = true;
                 System.out.println(username + " wins!!!!!");
                 }}
                 
                 //C 3,4,5,6
                 for(int i = 0; i <= 5; i++)
                 {
                 sum = (c3[i + 0] + c4[i + 0] + c5[i + 0] + c6[i + 0]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 //C 4,5,6,7
                 for(int i = 0; i <= 5; i++)
                 {
                 sum = (c4[i + 0] + c5[i + 0] + c6[i + 0] + c7[i + 0]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 //Diagonals
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c1[i + 0] + c2[i + 1] + c3[i + 2] + c4[i + 3]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c2[i + 0] + c3[i + 1] + c4[i + 2] + c5[i + 3]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c3[i + 0] + c4[i + 1] + c5[i + 2] + c6[i + 3]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c4[i + 0] + c5[i + 1] + c6[i + 2] + c7[i + 3]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c4[i + 3] + c5[i + 2] + c6[i + 1] + c7[i + 0]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c3[i + 3] + c4[i + 2] + c5[i + 1] + c6[i + 0]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c2[i + 3] + c3[i + 2] + c4[i + 1] + c5[i + 0]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}
                 
                 for(int i = 0; i <= 2; i++)
                 {
                 sum = (c1[i + 3] + c2[i + 2] + c3[i + 1] + c4[i + 0]);                 if(sum == 4)
                 if(sum == 0)
                 {
                 winner = true;
                 System.out.println("Computer wins!!!!!");
                 }}

                 
                  

                                            
                   
                   
                   
                   
                    }while(!winner);
                    
                   
              
         
      
   
   
   
   
   
   
   
   
   }


}