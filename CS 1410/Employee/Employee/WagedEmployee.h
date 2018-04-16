#ifndef _WAGEDEMPLOYEE_H_
#define _WAGEDEMPLOYEE_H_

#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class WagedEmployee : public Employee
{
	private:
		double wage;
		double hours;

	public:
		WagedEmployee(string a_name, int a_year, int a_month, int a_day, double a_wage, double a_hours)
			: Employee(a_name, a_year, a_month, a_day), wage(a_wage), hours(a_hours) {}



		virtual double calcPay()
		{
			return hours*wage;
		}


		virtual void display()
		{
			Employee::display();
			cout << "Hourly: $ " << wage << " Hours:  " << hours << " Total: $ " << calcPay() << endl;

		}


		friend ostream& operator << (ostream& out, WagedEmployee& me)
		{
			out << (Employee &)me << "wage: $" << me.wage << " Hours:" << me.hours;
			return out;
		}

};
#endif