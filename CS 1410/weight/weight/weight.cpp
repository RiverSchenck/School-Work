#include <iostream>
#include <iomanip>
#include "weight.h"
using namespace std;


weight make_weight(int st, int pd, int ou)
{
	weight		temp;

	temp.stone = st;
	temp.pound = pd;
	temp.ounce = ou;

	return temp;
}


weight make_weight(int on)
{
	weight temp;

	temp.stone = on / 224;
	on %= 224;
	temp.pound = on / 16;
	temp.ounce = on % 16;

	return temp;
}

/*struct weight
{
	int stone;
	int pound;
	int ounce;
};


weight make_weight(int st, int pd, int ou);
weight make_weight(int on);
weight add(weight w1, weight w2);
void print(weight& w);
void read(weight* w);  */


weight add(weight w1, weight w2)
{
	int		i1 = w1.stone * 224 + w1.pound * 16 + w1.ounce;
	int		i2 = w2.stone * 224 + w2.pound * 16 + w2.ounce;

	return make_weight(i1 + i2);
}

void print(weight& w)
{
	cout << w.stone << " stones, " << w.pound << " pounds, " << w.ounce << " ounces " << endl;
}

void read(weight* w)
{

	cout << "Enter stones:";
	cin >> w->stone;

	cout << "Enter pounds:";
	cin >> w->pound;

	cout << "Enter ounces:";
	cin >> w->ounce;

}
