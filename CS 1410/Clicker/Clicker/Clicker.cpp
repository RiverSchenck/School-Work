#include <iostream>

using namespace std;

class Clicker
{
	private:

		int counter = 0;	//initializer list to initialize counter to 0

	public:

		void click()
		{
			counter++;		//incrementing counter
		}

		void reset()
		{
			counter = 0;	//Reset counter to 0
		}

		void display()
		{
			cout << "You have " << counter << " clicks" << endl;	//print the value of counter
		}
};

/* int main()	 
{
	


}*/