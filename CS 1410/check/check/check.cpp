#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	string file;


	cout << "Enter file: ";
	getline(cin, file);


	ifstream in(file.c_str());


	if (!in.is_open())
	{
		cout << "Unable to open: " << file << endl;


		exit (1);
	}

	
	cout.setf(ios::fixed);

	cout.precision(2);

	string kind;
	string date;
	string name;
	double amount;
	double total = 0;

	cout << "--------------------------------------------------------------------------" << endl;


	while (true)
	{
		getline(in, kind, ':'); 

		if (in.eof())
		{

			break;

		}

		getline(in, date, ':');

		getline(in, name, ':');

		in >> amount;

		in.ignore(256, '\n');


		if (kind == "deposit")
		{
			total += amount;
		}
		else
		{
			total -= amount;
		}

		cout << setw(15) << left << kind;
		cout << setw(15) << left << date;
		cout << setw(30) << left << name;
		cout << "$" << setw(10) << right << amount << endl;

	}


	cout << "--------------------------------------------------------------------------" << endl;


	

	cout << setw(60) << "Balance:  $" << setw(11) << right << total << endl;

	return 0;
}