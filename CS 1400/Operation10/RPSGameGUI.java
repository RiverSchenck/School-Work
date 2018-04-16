import javax.swing.JOptionPane;

public class RPSGameGUI
{

	public static void main (String[] args)
	{
		//Creating the RockPaperScissors object
      RockPaperScissors rps = new RockPaperScissors ();  //***Your class
				
		// Create variables to hold data
      int numGames = 0;
		String userChoice = "";
		String cpuChoice = "";
		String winner = "";
		int userWins;
		int cpuWins;
      String playerName = "";
      int playAgain = 0;
      
      //Show input box
      playerName = JOptionPane.showInputDialog(null, "Please enter your name: ");
		
		//Show message box
      JOptionPane.showMessageDialog(null, "Welcome " + playerName);
		
      do
      {
		//Set wins to 0 at beginning of loop.  Will reset to 0 if loop executes again.
      userWins = 0;
      cpuWins = 0;
      
      //Show input box and parse to integer
      numGames = Integer.parseInt(JOptionPane.showInputDialog(null, "Please enter an odd number of games to play: "));
		
		//Validate input
      while (numGames % 2 == 0 || numGames < 1) //Even number or less than 1
		{
			numGames = Integer.parseInt(JOptionPane.showInputDialog(null, "Sorry, number of games must be greater than 1 and odd.  Please try again:"));
		}
		
		//Play the game for the number of rounds the user entered
		for (int i = 1; i <= numGames; i++)
		{
			//Get the user and computer choices
			userChoice = rps.getUserChoice();  //***Your method
			cpuChoice = rps.getCPUChoice();   //***Your method
			
			JOptionPane.showMessageDialog(null, "Computer chooses " + cpuChoice);
			
			//Pick winner
			winner = rps.pickWinner(userChoice, cpuChoice);  //***Your method
			
			if (winner.equalsIgnoreCase("Tie"))
			{
				JOptionPane.showMessageDialog(null, "It's a tie!  Play again.");
				numGames++;
			}
			else
			{
				if (winner.equalsIgnoreCase("User"))
				{
					userWins++;
				}
				else if (winner.equalsIgnoreCase("Computer"))
				{
					cpuWins++;
				}
				else
				{
					JOptionPane.showMessageDialog(null,"Error in picking winner");
				}
				
				JOptionPane.showMessageDialog(null, winner + " wins!");
			}
			
		} //end for
		
		//Print results
		JOptionPane.showMessageDialog(null, playerName + " won " + userWins + " time(s).");
		JOptionPane.showMessageDialog(null, "Computer won " + cpuWins + " time(s).");
		
		if (userWins > cpuWins)
		{
			JOptionPane.showMessageDialog(null, playerName + " won!");
		}
		if (cpuWins > userWins)
		{
			JOptionPane.showMessageDialog(null, "The computer won!");
		}
		
		//Show confirmation box
      playAgain = JOptionPane.showConfirmDialog(null, "\nThank you for playing! \n Would you like to play again?");
	
   } while(playAgain == JOptionPane.YES_OPTION);
      
	} //end main

} //end class