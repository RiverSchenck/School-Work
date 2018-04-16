#include <iostream>
#include <string>
using namespace std;



int main()
{

	string input;
	
	cout << "Enter words: ";
	getline(cin, input);

	string r;

	for (int i = 0; i < input.length(); i++)
		while (input[i] == ' ')
			input.erase(i, 1);


	string test_reverse;

	for (int i = 0; i < input.length(); i++)
		test_reverse += input[input.length() - 1 - i];


	string test_input = input;


	if (test_reverse == test_input)
	{
		cout << endl << "Input is a palindrome!" << endl;
	}
	else
	{
		cout << endl <<"Input is not a palindrome!" << endl;
	}

}




