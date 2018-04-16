#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a;
	cout << "Please enter a: ";  //prompt
	cin >> a;

		if (a == 0) //Checking for 0
		{
			cout << "Value 'A' of 0 will not work." << endl;
			exit(0);
		}

	double b;
	cout << "Please enter b: ";  //prompt
	cin >> b;

	double c;
	cout << "Please enter c: "; //Prompt
	cin >> c;


		double discrim = ((b*b) - (4 * a*c)); //Checking discriminant
		cout << discrim << endl;

		if (discrim >= 0)
		{
			double x1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);    //x1 calculation
			double x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);    //x2 calculation
			cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
		}
		else
		{
			double xreal = (-b / (2*a));
			double x1imag = (sqrt(-discrim) / (2*a));
			cout << "x1 = " << xreal << " + " << x1imag << "i" << "  x2 = " << xreal << " - " << x1imag << "i" << endl;
		}
		

		return 0;
}