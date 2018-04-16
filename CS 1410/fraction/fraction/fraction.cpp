#include "fraction.h"
#include <iostream>
#include<iomanip>
using namespace std;

int gcd(int u, int v);

fraction::fraction(int n, int d) : numerator(n), denominator(d)
{
	int   common = gcd(numerator, denominator);

	numerator /= common;

	denominator /= common;

}

fraction fraction::operator+(fraction f2)
{
	int n = numerator * f2.denominator + f2.numerator * denominator;

	int d = denominator * f2.denominator;

	return fraction(n, d);
}

fraction fraction::operator-(fraction f2)
{
	int n = numerator * f2.denominator - f2.numerator * denominator;
	
	int d = denominator *f2.denominator;

	return fraction(n, d);
}

fraction fraction::operator*(fraction f2)
{
	int n = numerator * f2.numerator;
	
	int d = denominator * f2.denominator;

	return fraction (n, d);
}

fraction fraction::operator/(fraction f2)
{
	int n = numerator * f2.numerator;

	int d = denominator * f2.denominator;

	return fraction(n, d);
}

ostream& operator<<(ostream& out, fraction& f)
{

	cout << endl << f.numerator << "/" << f.denominator << endl;

	return out;
}

istream& operator>>(istream& in, fraction& f)
{
	cout << "Enter Numerator please:";

	cin >> f.numerator;

	cout << "Enter Denominator please:";

	cin >> f.denominator;

	return in;
}

int gcd(int u, int v)
{
	u = (u < 0) ? -u : u;			
	v = (v < 0) ? -v : v;			

	while (u > 0)
	{
		if (u < v)
		{
			int t = u;	
			u = v;
			v = t;
		}

		u -= v;
	}

	return v;				
}
