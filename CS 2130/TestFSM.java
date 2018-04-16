import java.util.*;
public class TestFSM
{
public static void main(String[] args)
{

String A = "ab"; 
int[][] ST = {{1,2,4},     
              {2,1,3},    
              {2,2,2},
              {3,3,3}};
int[] AS   = {0,1,2,4};    
    
boolean result = false;

FSM fsm = new FSM(A, ST, AS);

String string1 = "aabaaaa";
String string2 = "aaabaaaa";
String string3 = "aabaaaab";
String string4 = "baaaaaa";
String string5 = "aaaaabaa";

 
   result = fsm.validString(string1);
   System.out.println("Test string: " + string1 + " Result: " + result);
   System.out.println();
   
   result = fsm.validString(string2);
   System.out.println("Test string: " + string2 + " Result: " + result);
   System.out.println();
   
   result = fsm.validString(string3);
   System.out.println("Test string: " + string3 + " Result: " + result);
   System.out.println();
   
   result = fsm.validString(string4);
   System.out.println("Test string: " + string4 + " Result: " + result);
   System.out.println();
   
   result = fsm.validString(string5);
   System.out.println("Test string: " + string5 + " Result: " + result);
   System.out.println();
   
   
} 
}
