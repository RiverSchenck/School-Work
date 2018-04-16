#ifndef _Date_H_
#define _Date_H_

#include <iostream>
using namespace std;

class Date
{

private:

	int year;
	int month;
	int day;

public:
	Date(int a_year, int a_month, int a_day)
		: year(a_year), month(a_month), day(a_day) {}

	void display()
	{
		cout << month << "/" << day << "/" << year << endl;

	}

	friend ostream& operator<<(ostream& out, Date& me)
	{
		out << me.month << "/" << me.day << "/" << me.year << endl;
		return out;
	}

};

#endif
