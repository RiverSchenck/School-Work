import java.util.Scanner;
import java.util.Random;

public class BankAccount
{
	private String name;
	private int accountNum;
	private double balance;
	
   public static void main(String[]args)
   {  
      //imports
      Scanner in = new Scanner (System.in);
      Random r = new Random();
      
      //Variables
      String nameinfo = "";
      int accountnumber = ' ';
      int choice = ' ';
      int deposit = ' ';
      int withdrawal = ' ';
      
      //Introduction
      System.out.println("Welcome to the River Bank!");
      System.out.println("Please enter your name to create an account: ");
      
      
      //info to pass
      nameinfo = in.nextLine();
      accountnumber = r.nextInt(10000000);
      BankAccount obj = new BankAccount(nameinfo, accountnumber);
      System.out.println();
      
      //loop until quit
      do
      {
      
      //Choices
      System.out.println("Press 1 to make a deposit.");
      System.out.println("Press 2 to make a withdrawal");
      System.out.println("Press 3 to get account information.");
      System.out.println("Press 4 to quit.");
      choice = in.nextInt();
      
         //Making sure valid choice
         if((choice > 4) || (choice < 1))
         {
            do
            {
            System.out.println("Invalid choice, please try again: ");
            choice = in.nextInt();
            
            }while((choice > 4) || (choice < 1));
            
         }
         
            
               //if 1
               if (choice == 1)
               {
                  System.out.println();
                  System.out.println("Please enter amount you would lke to deposit: ");
                  deposit = in.nextInt();
                  System.out.println();
                  
                  obj.deposit(withdrawal);
                  
               }//end if
               
               
               //if 2
               if (choice == 2)
               {
                  do
                  {
                     System.out.println();
                     System.out.println("Please enter the amount of the withdrawal: ");
                     withdrawal = in.nextInt();
                     System.out.println();
                     
                     
                     //extra credit
                     if ( withdrawal > obj.getBalance())
                     {
                        System.out.println("You are tyring withdrawal more than what in account");
                        
                     }
                  }while(withdrawal > obj.getBalance());
                   
                  
                  obj.withdraw(withdrawal);
                  
               }
               
               
               //if 3
               if (choice ==3)
               {
                  System.out.println();
                  System.out.println("Name: " + obj.getName() + " " + "Account #: " + obj.getAccountNum() + " " + "Balance: " + obj.getBalance());
                  System.out.println();
               }
               
               
               
            }while((choice == 1) || (choice == 2) || (choice ==3));
      
               //if 4
               if (choice ==4)
               {
                  System.out.println();
                  System.out.println(obj.getName() + " thank you for your business!");
               }
      
   }//end main

   
   
	//Constructor that sets the customer name and account number when account is created
	public BankAccount (String n, int a)
	{
		this.name = n;
		this.accountNum = a;
      
	}
	
	//Increases the account balance by the amount of the deposit
	public void deposit (double amount)
	{
		this.balance = balance + amount;
	}
	
	//Reduces the account balance by the amount of the withdrawal
	public void withdraw (double amount)
	{
		this.balance = balance - amount;
	}
	
	//Returns the account balance
	public double getBalance ()
	{
		return this.balance;
	}
	
	//Returns the account holder's name
	public String getName ()
	{
		return this.name;
	}
	
	//Returns the account holder's account number
	public int getAccountNum ()
	{
		return this.accountNum;
	}
	
}