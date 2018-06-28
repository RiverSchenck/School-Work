#include <string>
#include <stack>

class Infix
{

private:
	std::string ifix;
	std::string temp;
	std::string pfix;
	int operands;
	int operators;
	std::stack <char> tmp;

public:

	Infix();
	Infix(std::string str);
	void setInfix(std::string str);
	int getNumberOfOperators();
	int getNumberOfOperands();
	std::string getInfix();
	std::string getPostfix();
	void clear();
	void convertToPostFix();



};

