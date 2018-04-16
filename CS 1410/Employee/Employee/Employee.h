#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "address.h"
#include "date.h"

#include <string>
#include <iostream>
using namespace std;


class Employee
{

	private:
		string      name;
		Address*    address; 
		Date        date;   

	public:


		Employee(string a_name, int a_year, int a_month, int a_day)
			: date(a_year, a_month, a_day), name(a_name), address(NULL) {}

		~Employee()
		{
			if (address != NULL)
			{
				delete address;
			}
		}

		virtual double calcPay() = 0;

		string getName()
		{
			return name;
		}

		void setAddress(string a_street, string a_city)
		{
			if (address != NULL)
			{
				delete address;
			}

			address = new Address(a_street, a_city);
		}


		virtual void display()
		{
			address->display();
			date.display();
			
		}


		friend ostream& operator<<(ostream& out, Employee& me)
		{
			out << endl << me.name << endl;
			if (me.address != NULL)
			return out;
		}

};

#endif                  