#ifndef _SALARIEDEMPLOYEE_H_
#define _SALARIEDEMPLOYEE_H_

#include "Employee.h"

#include <iostream>
#include <string>
using namespace std;


class SalariedEmployee : public Employee
{
	public:
		double salary;

	public:
		SalariedEmployee(string a_name, int a_year, int a_month, int a_day, double a_salary)
			: Employee(a_name, a_year, a_month, a_day), salary(a_salary) {}

		virtual double calcPay()
		{
			return salary / 24;
		}

		virtual void display()
		{
			Employee::display();
			cout << "Salary: $" << salary << " Pay: " << calcPay() << endl;
		}

	

		friend ostream& operator<<(ostream& out, SalariedEmployee& me)
		{
			out << (Employee&)me << "Salary: $" << me.salary;
			return out;
		}
};
#endif