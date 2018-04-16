#include <string>
#include <iostream>
using namespace std;

class Beta
{
private:
	double   cost;

public:
	Beta(double a_cost) : cost(a_cost) {}

	void display()
	{

		cout << "Cost is: " << cost << endl;

	}

};


class Gamma
{
private:
	char     id;


public:
	Gamma(char a_id) : id(a_id) {}

	void display()
	{

		cout << "ID: " << id << endl;

	}

};



class Alpha
{
private:
	string	name;
	int      part;
	Beta*	   beta = nullptr;
	Gamma	   gamma;

public:
	Alpha(string a_name, int a_part, char a_id) : name(a_name), part(a_part), gamma(a_id), beta(nullptr) {}

	~Alpha()
	{
		if (beta != nullptr)
			delete beta;
	}


	void setBeta(int a_cost)
	{
		if (beta != nullptr)
			delete beta;
		beta = new Beta(a_cost);
	}


	void display()
	{
		cout << name << endl;
		cout << "Part: " << part << endl;
		gamma.display();
		if (beta != nullptr)
			beta->display();
	}

};



class Delta : public Alpha
{
private:
	string	desc;

public:
	Delta(string a_name, string a_desc, int a_part, char a_id) : Alpha(a_name, a_part, a_id), desc(a_desc) {}

	void display()
	{

		Alpha::display();
		cout << "Desc: " << desc << endl;

	}

};

int main()
{
	Delta d("River Schenck", "It works!", 100, 'A');

		d.setBeta(10);
		d.display();
		

	return 0;

}
