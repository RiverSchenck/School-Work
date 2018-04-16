import java.util.*;
class Throws
{
public static void main(String[] a)
{
Scanner in = new Scanner(System.in);
System.out.println("Welcome to the dice throwing simulator!");
System.out.println("How many dice rolls would you like to simulate? ");
int k = in.nextInt();
System.out.println("DICE ROLLING SIMULATION RESULTS ");
System.out.println("Each \"*\" represents 1% of the total number of rolls. ");
System.out.println("Total number of rolls = " + k);
displayResults(simulateThrows(k));
System.out.println("Thank you for using the dice throwing simulator. Goodbye! ");
}

private static int[] simulateThrows(int k) {
Random r = new Random();
int[] counts=new int[11];
for(int n=0; n<k; n++)
++counts[r.nextInt(6)+r.nextInt(6)];
return counts;
}

private static void displayResults(int[] counts)
{
for(int i=0; i<counts.length; ++i)
{
System.out.print((i+2) + ":");
for(int n=0; n<counts[i]; ++n)
{
System.out.print('*');
}
System.out.println();
}
System.out.println();
}
}