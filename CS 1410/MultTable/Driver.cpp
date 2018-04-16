#include "MultTable.h"
#include <iostream>


using std::cout;
using std::endl;

int main() {

	cout << "Testing default constructor" << endl;
	MultTable table1;
	table1.printTable();

	cout << "Testing copy constructor" << endl;
	MultTable table2(table1);
	table2.printTable();
	//table2.setValue(i, j, value);

	cout << "Testing size constructor" << endl;
	MultTable table3(5);
	table3.printTable();
	cout << "Testing assignment operator" << endl;
	table3 = table2;
	table3.printTable();
	
	cout << "Testing copy constructor/Destructor" << endl;
	MultTable* tablePtr = new MultTable(table1);
	tablePtr->printTable();
	delete tablePtr;
	tablePtr = nullptr;
	table1.printTable();

}