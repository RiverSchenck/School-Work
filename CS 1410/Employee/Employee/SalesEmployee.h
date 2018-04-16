#ifndef _SALESEMPLOYEE_H_
#define _SALESEMPLOYEE_H_

#include <iostream>
#include <string>
using namespace std;

#include "SalariedEmployee.h"

class SalesEmployee : public SalariedEmployee
{
	private:
		double sales;
		double commission;

	public:
		SalesEmployee(string a_name, int a_year, int a_month, int a_day, double a_salary, double a_commission, double a_sales)
			:SalariedEmployee(a_name, a_year, a_month, a_day, a_salary), commission(a_commission), sales(a_sales) {}
	

		virtual double calcPay()
		{
			return SalariedEmployee::calcPay() + commission*sales;
		}

		virtual void display()
		{
			SalariedEmployee::display();
			cout << "Commission: " << commission << " Sales: " << sales << " Total:  " << calcPay() << endl;

		}

		friend ostream& operator << (ostream& out, SalesEmployee& me)
		{
			out << (SalariedEmployee&)me << endl;
			out << "Sales: " << me.sales << endl;
			out << "Commission: " << me.commission;
			return out;
		}
};

#endif