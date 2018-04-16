#include <iostream>
#include "fraction.h"
using namespace std;
int main()
{
	char  choice;
	fraction f1;
	fraction f2;

	do
	{
		cout << endl;
		cout << "A\tAdd\n";
		cout << "S\tSub\n";
		cout << "M\tMult\n";
		cout << "D\tDiv\n";
		cout << "E\tExit\n";
		cout << "\nChoice?: ";

		cin >> choice;
		cin.ignore();


	
		switch (choice)
		{
		case 'A':
		case 'a':
			cout << "Fraction#1" << endl;
			cin >> f1;
			cout << "Fraction#2" << endl;
			cin >> f2;

			cout << f1.operator+(f2) << endl;
			break;


		case 'S':
		case 's':
			cout << "Fraction#1" << endl;
			cin >> f1;
			cout << "Fraction#2" << endl;
			cin >> f2;
			cout << f1.operator-(f2) << endl;
			break;

		case 'M':
		case 'm':
			cout << "Fraction#1" << endl;
			cin >> f1;
			cout << "Fraction#2" << endl;
			cin >> f2;
			cout << f1.operator*(f2) << endl;
			break;



		case 'D':
		case 'd':
			cout << "Fraction#1" << endl;
			cin >> f1;
			cout << "Fraction#2" << endl;
			cin >> f2;
			cout << f1.operator/(f2) << endl;
			break;
		

		case 'e':
		case 'E':
			break;
		default:
			cerr << "Unrecognized choice: " <<
				choice << endl;
			break;
		}
	} while (choice != 'e' && choice != 'E');
	return 0;
}