import java.util.*;
import java.io.*;

public class Prime{


public static void main(String args[])
{
   long number = 101; //This is the number that will check if it is prime

   if (isPrime(number))
   {
      System.out.println("Number is prime!");
   }
   else
   {
      System.out.println("Number is not prime!");
   }
}

   static boolean isPrime(long X)
   {
   
   if (X < 2)
      return false;
   if (X == 2) 
      return true;
   if (X % 2 == 0) 
      return false;
   for (long i = 3; i * i <= X; i += 2)
   if (X % i == 0) 
      return false;
      
   return true;

      
   }

}