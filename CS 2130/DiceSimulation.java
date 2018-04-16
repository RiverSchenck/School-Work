import java.util.Random;
import java.util.Scanner;

public class DiceSimulation {
    public static int[] frequency;
    public static int totalrolls=0;
    public static void main(String[] args) {
        String input="";
        int diceroll=0;
        int additional=0;
        System.out.println("Welcome to the dice throwing simulator!");
        System.out.println("");
        
         Scanner scan = new Scanner(System.in);
         
                while(true){
                    System.out.print("How many dice rolls would you like to simulate? ");
                    try{
                        diceroll=scan.nextInt();
                        if(diceroll>0){
                            break;
                        }
                        else{
                            System.out.println("Please enter a positive number and try again!");
                        }
                    }
                    catch (Exception e){
                        System.out.println("Please enter a valid number(only integer will be accepted) and try again!");
                    }
                }
                
                newSimulation(diceroll);
    
    public static void newSimulation(int diceroll) 
    {
        frequency=new int[13];
        Random ra = new Random();
        totalrolls=diceroll;
        for(int i=0;i<diceroll;i++){
            int first = ra.nextInt(6);
            int second = ra.nextInt(6);
            int total= first+second+2;
            frequency[total]=frequency[total]+1;
        }
    }

    public static void additionalRolls(int additional){
        Random ra = new Random();
        for(int i=0;i<additional;i++){
            totalrolls++;
            int first = ra.nextInt(6);
            int second = ra.nextInt(6);
            int total= first+second+2;
            frequency[total]=frequency[total]+1;
        }
    }
    public static void printReport(){
        System.out.println("");
        System.out.println("DICE ROLLING SIMULATION RESULTS");
        System.out.println("Each \"*\" represents 1% of the total number of rolls");
        System.out.println("Total number of rolls = "+totalrolls+".");
        System.out.println("");
        for(int i=2;i<13;i++){
            String output="";
            int percent=100*frequency[i]/totalrolls;
            for(int j=0;j<percent;j++){
                output+="*";
            }
            System.out.printf("%2d : %s\n",i,output);
        }
        System.out.println();
    }
}
