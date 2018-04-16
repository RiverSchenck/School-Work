#define READ_H
#include <iostream>
#include "weight.h"
using namespace std;

int main(int st, int pd, int ou)
{

	weight w;
	read(&w);

	weight on;
	read(&on);


	weight u = add(w, on);


	print(add(w, on));

	return 0;


}