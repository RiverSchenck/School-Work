#include <iostream>
using namespace std;

int main()
{

	int tall;
	int slashspaces;
	int spaces;

	cout << "How tall should the tree be?: ";
	cin >> tall;

	if (tall >= 3 && tall <= 15)
	{
		for (int level = 0; level < tall; level++)
		{
			for (int spaces = 0; spaces < tall - level - 1; spaces++)
				cout << ' ';

			cout << '/';

			for (int slashspaces = 0; slashspaces < level * 2; slashspaces++)
				cout << ' ';

			cout << "\\ ";

			cout << endl;


		}




		for (int length = 0; length < (tall * 2); length++)
		{
			cout << "-";
		}

		cout << endl;



		for (int level = 0; level <= (tall / 2) - (tall % 2); level++)
		{

			for (int spaces = 0; spaces < tall - 1; spaces++)
			{
				cout << ' ';
			}

			cout << "||" << endl;
		}



		return 0;
	}
	else
	{
		cout << "ERROR" << endl;
	}
}