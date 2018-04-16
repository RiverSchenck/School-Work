#include<iostream>
using namespace std;

class fraction
{


private:
	int numerator;
	int denominator;



public:
				fraction (int n = 0, int d = 1);
				fraction operator+(fraction f2);
				fraction operator-(fraction f2);
				fraction operator*(fraction f2);
				fraction operator/(fraction f2);



	
		friend	ostream& operator<< (ostream& out, fraction& f);
		friend	istream& operator>>(istream& in, fraction& f);


	


};