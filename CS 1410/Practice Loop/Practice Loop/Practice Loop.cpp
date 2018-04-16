#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int y = 0;

	do
	{
		cout << "Enter number please: ";
		cin >> x;
		
		if (x != -1)
		{
			y = y + x;
		}

			cout << "Total: " << y << endl;
		
	} while (x != -1);


}