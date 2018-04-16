import java.io.*;
public class Proj2A2
{
public static void main(String args[])
{
int F = 0;
int T = 1;
System.out.println("x  y  z  w  f");
System.out.println("-------------");

LCircuit(0,0,0,0);
LCircuit(0,0,0,1);
LCircuit(0,0,1,0);
LCircuit(0,0,1,1);
LCircuit(0,1,0,0);
LCircuit(0,1,0,1);
LCircuit(0,1,1,0);
LCircuit(0,1,1,1);
LCircuit(1,0,0,0);
LCircuit(1,0,0,1);
LCircuit(1,0,1,0);
LCircuit(1,0,1,1);
LCircuit(1,1,0,0);
LCircuit(1,1,0,1);
LCircuit(1,1,1,0);
LCircuit(1,1,1,1);
}

public static char LCircuit(int x, int y, int z, int w)
{

      int f =  ORgate(ORgate(ORgate(ANDgate(z,NOTgate(y)),
               ANDgate(x,NOTgate(y))),
               ANDgate(ANDgate(NOTgate(x),y),NOTgate(z))),
               ANDgate(ANDgate(y,NOTgate(z)),w));

      
      
   System.out.println(x + "  " + y + "  " + z + "  " + w + "  " + f);
  
   return 0;
}

public static int NOTgate(int x)
{

   if(x == 0)
   {
   x = 1;
   }
   else
   {
   x = 0;
   }  
    
       return x;
}


public static int ORgate(int a, int b)
{


   if(a == 0 && b == 0)
   {
   a = 0;
   }
   else
   {
   a = 1;
   }
     
        return a;
   
}


public static int ANDgate(int d, int e)
{


   if(d == 0 || e == 0)
   {
   d = 0;
   }
   else
   {
   d = 1;
   }
    
        return d;

}



}
