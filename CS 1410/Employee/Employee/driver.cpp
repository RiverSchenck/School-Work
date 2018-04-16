#include "Employee.h"
#include "SalariedEmployee.h"
#include "SalesEmployee.h"
#include "WagedEmployee.h"
#include "Date.h"
#include "Address.h"
#include "CList.h"
#include <iostream>
#include <string>

using namespace std;

void prompt(const char* message, string& variable);
void prompt(const char* message, int& number);
void prompt(const char* message, double& number);

int main()
{
	CList<Employee> clist;
	while (true)
	{
		cout << endl;
		cout << "1. Waged Employee" << endl;
		cout << "2. Salaried Employee" << endl;
		cout << "3. Sales Employee" << endl;
		cout << "4. List" << endl;      
		cout << "5. Exit" << endl << endl;
		cout << "Choose an Employee or an Action: ";

		char   c;
		cin >> c;
		cin.ignore();


		string   name;           
		int   year;
		int   month;
		int   day;
		string   street;
		string   city;


		switch (c)
		{
		case '1':   
		{
			double   wage;
			double   hours;
			prompt("Name", name);
			prompt("Wage", wage);
			prompt("Hours", hours);
			prompt("Year", year);
			prompt("Month", month);
			prompt("Date", day);
			prompt("Street", street);
			prompt("City", city);
			WagedEmployee* we = new WagedEmployee(name, year, month, day, wage, hours);
			we->setAddress(street, city);
			clist.insert(we);
			//cout << *we << endl;
			//we->display();
			break;
		}


		case '2':  
		{
			double   salary;
			prompt("Name", name);
			prompt("Salary", salary);
			prompt("Year", year);
			prompt("Month", month);
			prompt("Date", day);
			prompt("Street", street);
			prompt("City", city);
			SalariedEmployee* se = new SalariedEmployee(name, year, month, day, salary);
			se->setAddress(street, city);
			clist.insert(se);
			//cout << *se << endl;
			//se->display();
			break;
		}


		case '3':  
		{
			double   salary;
			double   commission;
			double   sales;
			prompt("Name", name);
			prompt("Salary", salary);
			prompt("Commission", commission);
			prompt("Sales", sales);
			prompt("Year", year);
			prompt("Month", month);
			prompt("Date", day);
			prompt("Street", street);
			prompt("City", city);
			SalesEmployee* se = new SalesEmployee(name, year, month, day, salary, commission, sales);
			se->setAddress(street, city);
			clist.insert(se);
			//cout << *se << endl;
			//se->display();
			break;
		}


		case '4':
		{

			clist.list();
			break;

		}


		case '5':
			exit(0);
		}
	}
	return 0;
}

void prompt(const char* message, string& variable)
{
	cout << message << ": ";
	getline(cin, variable);
}

void prompt(const char* message, int& number)
{
	cout << message << ": ";
	cin >> number;
	cin.ignore();       
}
void prompt(const char* message, double& number)
{
	cout << message << ": ";
	cin >> number;
	cin.ignore();     
}