/****************************************************************

* Encrypt.java

* River Schenck

*

* This program encryptes and decryptes files

*****************************************************************/

import java.io.File;
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.util.ArrayList;

public class encrypt
{

   public static void main (String[] args)
   {
   
   Scanner in = new Scanner (System.in);
   File f;
   Scanner fileIn2;
   Scanner fileIn;
   
   String userinput = "";
   String fileName = "";
   String hold = "";
   String newhold = "";
   boolean t = true;
   ArrayList<String>words = new ArrayList<String>();
   
   
   try
   {
      
      
   
      //Get file name from the user to build the File object
      System.out.println("Please enter the name of the file: ");
      
      fileName = in.nextLine();
      
      
      //Find if encrpyt or decrypt
      
      System.out.println("Would you like to encrypt or decrypt?:");
      
      userinput = in.nextLine();
      
      
      //Build the File and attatch a Scanner to it
      f = new File (fileName);
      
      fileIn = new Scanner (f);
      
      if(userinput.equalsIgnoreCase("encrypt"))
      {
      
      PrintWriter fileOut = new PrintWriter ("Encrypted.txt");
        
        while(fileIn.hasNext())
        {
         words.add(fileIn.next());
         }
      
       
           
          for (int i= 0; i < words.size(); i++)
          {
           
           hold = words.get(i);
          
           
           for (int p = 0; p <= hold.length() + 1; p++)
           {
           try
           {
              newhold = "";
              
              newhold = hold.substring(p-1,p);
              
               if (newhold.equalsIgnoreCase("!"))
              {
              fileOut.print("!");
              }
              if (newhold.equalsIgnoreCase("."))
              {
              fileOut.print(".");
              }
              if (newhold.equalsIgnoreCase("?"))
              {
              fileOut.print("?");
              }
              if (newhold.equalsIgnoreCase("a"))
              {
              fileOut.print("b");
              }
              if (newhold.equalsIgnoreCase("b"))
              {
              fileOut.print("c");
              }
              if (newhold.equalsIgnoreCase("c"))
              {
              fileOut.print("d");
              } 
              if (newhold.equalsIgnoreCase("d"))
              {
              fileOut.print("e");
              }
              if (newhold.equalsIgnoreCase("e"))
              {
              fileOut.print("f");
              }
              if (newhold.equalsIgnoreCase("f"))
              {
              fileOut.print("g");
              }
              if (newhold.equalsIgnoreCase("g"))
              {
              fileOut.print("h");
              }
              if (newhold.equalsIgnoreCase("h"))
              {
              fileOut.print("i");
              }
              if (newhold.equalsIgnoreCase("i"))
              {
              fileOut.print("j");
              }
              if (newhold.equalsIgnoreCase("j"))
              {
              fileOut.print("k");
              }
              if (newhold.equalsIgnoreCase("k"))
              {
              fileOut.print("l");
              }
              if (newhold.equalsIgnoreCase("l"))
              {
              fileOut.print("m");
              }
              if (newhold.equalsIgnoreCase("m"))
              {
              fileOut.print("n");
              }
              if (newhold.equalsIgnoreCase("n"))
              {
              fileOut.print("o");
              }
              if (newhold.equalsIgnoreCase("o"))
              {
              fileOut.print("p");
              }
              if (newhold.equalsIgnoreCase("p"))
              {
              fileOut.print("q");
              }
              if (newhold.equalsIgnoreCase("q"))
              {
              fileOut.print("r");
              }
              if (newhold.equalsIgnoreCase("r"))
              {
              fileOut.print("s");
              }
              if (newhold.equalsIgnoreCase("s"))
              {
              fileOut.print("t");
              }
              if (newhold.equalsIgnoreCase("t"))
              {
              fileOut.print("u");
              }
              if (newhold.equalsIgnoreCase("u"))
              {
              fileOut.print("v");
              }
              if (newhold.equalsIgnoreCase("v"))
              {
              fileOut.print("w");
              }
              if (newhold.equalsIgnoreCase("w"))
              {
              fileOut.print("x");
              }
              if (newhold.equalsIgnoreCase("x"))
              {
              fileOut.print("y");
              }
              if (newhold.equalsIgnoreCase("y"))
              {
              fileOut.print("z");
              }
              if (newhold.equalsIgnoreCase("z"))
              {
              fileOut.print("a");
              }



                            
              }
               catch(Exception e)
               {
                fileOut.print("");
               }
              
           
               }
               fileOut.print(" ");
           
           
           }
           fileOut.close();
           
         System.out.println("File has been encrypted to Encrypted.txt");
           
           }
           
           
           
      
         if (userinput.equalsIgnoreCase("decrypt"))
         {
      
      PrintWriter fileOut2 = new PrintWriter ("Decrypted.txt");
      
            while(fileIn.hasNext())
            {
            words.add(fileIn.next());
            }
            
          
           
          for (int i= 0; i < words.size(); i++)
          {
           
           hold = words.get(i);
          
           
           for (int p = 0; p <= hold.length() + 1; p++)
           {
           try
           {
              newhold = "";
              
              newhold = hold.substring(p-1,p);
              
              if (newhold.equalsIgnoreCase("!"))
              {
              fileOut2.print("!");
              }
              if (newhold.equalsIgnoreCase("."))
              {
              fileOut2.print(".");
              }
              if (newhold.equalsIgnoreCase("?"))
              {
              fileOut2.print("?");
              }

              if (newhold.equalsIgnoreCase("b"))
              {
              fileOut2.print("a");
              }
              if (newhold.equalsIgnoreCase("c"))
              {
              fileOut2.print("b");
              }
              if (newhold.equalsIgnoreCase("d"))
              {
              fileOut2.print("c");
              } 
              if (newhold.equalsIgnoreCase("e"))
              {
              fileOut2.print("d");
              }
              if (newhold.equalsIgnoreCase("f"))
              {
              fileOut2.print("e");
              }
              if (newhold.equalsIgnoreCase("g"))
              {
              fileOut2.print("f");
              }

              if (newhold.equalsIgnoreCase("h"))
              {
              fileOut2.print("g");
              }
              if (newhold.equalsIgnoreCase("i"))
              {
              fileOut2.print("h");
              }
              if (newhold.equalsIgnoreCase("j"))
              {
              fileOut2.print("i");
              }
              if (newhold.equalsIgnoreCase("k"))
              {
              fileOut2.print("j");
              }
              if (newhold.equalsIgnoreCase("l"))
              {
              fileOut2.print("k");
              }
              if (newhold.equalsIgnoreCase("m"))
              {
              fileOut2.print("l");
              }
              if (newhold.equalsIgnoreCase("n"))
              {
              fileOut2.print("m");
              }
              if (newhold.equalsIgnoreCase("o"))
              {
              fileOut2.print("n");
              }
              if (newhold.equalsIgnoreCase("p"))
              {
              fileOut2.print("o");
              }
              if (newhold.equalsIgnoreCase("q"))
              {
              fileOut2.print("p");
              }
              if (newhold.equalsIgnoreCase("r"))
              {
              fileOut2.print("q");
              }
              if (newhold.equalsIgnoreCase("s"))
              {
              fileOut2.print("r");
              }
              if (newhold.equalsIgnoreCase("t"))
              {
              fileOut2.print("s");
              }
              if (newhold.equalsIgnoreCase("u"))
              {
              fileOut2.print("t");
              }
              if (newhold.equalsIgnoreCase("v"))
              {
              fileOut2.print("u");
              }
              if (newhold.equalsIgnoreCase("w"))
              {
              fileOut2.print("v");
              }
              if (newhold.equalsIgnoreCase("x"))
              {
              fileOut2.print("w");
              }
              if (newhold.equalsIgnoreCase("y"))
              {
              fileOut2.print("x");
              }
              if (newhold.equalsIgnoreCase("z"))
              {
              fileOut2.print("y");
              }
              if (newhold.equalsIgnoreCase("a"))
              {
              fileOut2.print("z");
              }
             
            
              
                            
              }
               catch(Exception e)
               {
                fileOut2.print("");
               }
           
               }
               fileOut2.print(" ");
           
           }
           fileOut2.close();
           
           System.out.println("File has been decrypted to Decrypted.txt");
            
       }
           
           
                      
            
      
      
   }
   catch(FileNotFoundException e)
   {
      System.out.println("Sorry file not valid");
   }
   
   
   
   
   
   
   
   
   
   }





}