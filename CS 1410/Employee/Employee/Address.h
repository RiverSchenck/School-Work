#ifndef _ADDRESS_H_
#define _ADDRESS_H_

#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
	string      street;
	string      city;

public:
	Address(string a_street, string a_city) : street(a_street), city(a_city) {}

	void display()
	{
		cout << street << ", " << city << endl;
	}


	friend ostream& operator<<(ostream& out, Address& me)
	{
		out << endl << me.street << ", " << me.city << endl;
		return out;
	}

};

#endif
