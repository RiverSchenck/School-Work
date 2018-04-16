#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int random;
	int input;

	srand((unsigned)time(NULL));  //Getting Random
	random = (rand() % 100);  // Between 0-99

		cout << "Guess a number between 0 and 99: ";
		cin >> input;

			while (input != random)
			{

				if (input < 0)
				{
					exit(0);
				}
				else
				{
					if (input > random)
					{
						cout << "Your guess is too high!" << endl;
					}
					else
					{
						cout << "Your guess is too low!" << endl;
					}
				}

				cout << "Guess again: " << endl;
				cin >> input;
			

			}

			cout << "You Win!!!" << endl;

						return 0;

}