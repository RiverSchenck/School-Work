#include <iostream>
#include <iomanip>
#include "sterling.h"
using namespace std;


sterling make_sterling(int pd, int sh, int pc)
{
	sterling		temp;
	
	temp.pounds = pd;
	temp.shillings = sh;
	temp.pence = pc;

	return temp;
}


sterling make_sterling(int pn)
{
	sterling temp;

	temp.pounds = pn / 240;
	pn %= 240;
	temp.shillings = pn / 12;
	temp.pence = pn % 12;

	return temp;
}


sterling add(sterling p1, sterling p2)
{
	int		i1 = p1.pounds * 240 + p1.shillings * 12 + p1.pence;
	int		i2 = p2.pounds * 240 + p2.shillings * 12 + p2.pence;

	return make_sterling(i1 + i2);
}

void print(sterling& p)
{
	cout.fill('0');
	cout << (char)156 << p.pounds << "." << setw(2) << p.shillings << "." << p.pence << setw(2) << endl;
}

void read(sterling* p)
{

	cout << "Enter pounds:";
	cin >> p->pounds;

	cout << "Enter shillings:";
	cin >> p->shillings;

	cout << "Enter pence:";
	cin >> p->pence;

}
