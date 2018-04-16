#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a;
	cout << "Please enter a: ";  //prompt
	cin >> a;

	double b;
	cout << "Please enter b: ";  //prompt
	cin >> b;

	double c;
	cout << "Please enter c: "; //Prompt
	cin >> c;

	double x1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);    //x1 calculation
	double x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);    //x2 calculation
	cout << "x1 = " << x1 << ", x2 = " << x2 << endl;

	return 0;
}