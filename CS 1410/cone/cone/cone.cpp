#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	int y = 0;
	int z = 0;

	do
	{
		cout << "Enter number please: ";
		cin >> x;

		y = y + x;
		cout << y << endl;


	} while (x != 1);
	

}