import java.io.*;
public class Proj2A
{
public static void main(String args[])
{
char F = 'F';
char T = 'T';
System.out.println("(~q ^ r ^ ~p) v (~(r v ~p))");
System.out.println();
System.out.println("x  y  z  f");
System.out.println("-------------");
LProp(F, F, F);
LProp(F, F, T);
LProp(F, T, F);
LProp(F, T, T);
LProp(T, F, F);
LProp(T, F, T);
LProp(T, T, F);
LProp(T, T, T);
}

public static char LProp(char p, char q, char r)
{

      char f = ORlogic(ANDlogic(ANDlogic(NOTlogic(p), NOTlogic(q)), r), 
   NOTlogic(ORlogic(NOTlogic(p), r)));
   
   System.out.println(p + "  " + q + "  " + r + "  " + f);
   
   return 0;
}

public static char NOTlogic(char x)
{

   if(x == 'F')
   {
   x = 'T';
   }
   else
   {
   x = 'F';
   }  
          
          return x;
}


public static char ORlogic(char a, char b)
{
char c;

   if(a == 'F' && b == 'F')
   {
   c = 'F';
   }
   else
   {
   c = 'T';
   }
     
         return c;

}


public static char ANDlogic(char d, char e)
{
char f;

   if(d == 'F' || e == 'F')
   {
   f = 'F';
   }
   else
   {
   f = 'T';
   }
    
         return f;

}



}
