#define READ_H
#include <iostream>
#include "sterling.h"
using namespace std;

int main(int pd, int sh, int pc)
{

	sterling p;
	read(&p);

	sterling pn;
	read(&pn);
	
	
	sterling u = add(p, pn);
	

	print(add(p, pn));

	return 0;


}