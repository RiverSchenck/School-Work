#include "Infix.h"

using std::stack;
using std::string;

Infix::Infix() {

	ifix = "";
	pfix = "";
}

Infix::Infix(string str) {

	ifix = str;
	operands = 0;
	operators = 0;
	int length = ifix.length();	
	int hold = 0;
	int precedence = 0;
	temp = ifix;

	for (int i = 0; i < length + 1; i++) {
	if (temp[i] == ' ') {
		i++;
	}
	if (temp[i] == '(') {
		tmp.push('(');
	}
	if (temp[i] == ')') {
		while (tmp.top() != '(') {
			if (tmp.empty()) {
				break;
			}
			pfix += tmp.top();
			pfix += ' ';
			tmp.pop();
		}

		}
		if (isdigit(temp[i])) {
			hold = i;
			while (isdigit(temp[hold])) {
				this->pfix += temp[hold];
				hold++;
			}
			operands++;
			pfix += ' ';
			i = --hold;
		}
		if (temp[i] == '^') {
			tmp.push(temp[i]);
			operators++;
			precedence = 3;
		}
		if (temp[i] == '*' || temp[i] == '/') {

			tmp.push(temp[i]);
			operators++;
			precedence = 2;
		}


		if (temp[i] == '+' || temp[i] == '-') {
			if (precedence > 1) {
				if (tmp.top() == '(') {
					tmp.pop();
				}
				else {
					pfix += tmp.top();
					pfix += ' ';
					tmp.pop();

				}
			}
			tmp.push(temp[i]);
			operators++;
			precedence = 1;
		}

	}


	while (tmp.empty() != true) {
		if (tmp.empty()) {
			break;
		}
		if (tmp.top() == '(') {
			tmp.pop();
		}
		else {
			pfix += tmp.top();
			pfix += ' ';
			tmp.pop();

		}

	}


}

void Infix::setInfix(string str) {
	this->clear();
	this->ifix = str;
	operators = 0;
	operands = 0;	
	this->convertToPostFix();
}

void Infix::clear() {

	this->ifix = "";
	this->temp = "";
	operands = 0;
	operators = 0;
	this->pfix = "";
}


string Infix::getPostfix() {

	return pfix;

}

string Infix::getInfix() {

	return ifix;

}

int Infix::getNumberOfOperands() {

	return operands;

}

int Infix::getNumberOfOperators() {

	return operators;

}

void Infix::convertToPostFix() {
	int length = ifix.length();
	int precedence = 0;
	int hold = 0;
	temp = ifix;

	for (int i = 0; i < length + 1; i++) {

		if (temp[i] == ' ') {
			i++;
		}

		if (temp[i] == '(') {
			tmp.push('(');
		}

		if (temp[i] == ')') {
			while (tmp.top() != '(') {
				if (tmp.empty()) {
					break;
				}
				pfix += tmp.top();
				pfix += ' ';
				tmp.pop();
			}

		}

		if (isdigit(temp[i])) {
			hold = i;
			while (isdigit(temp[hold])) {
				this->pfix += temp[hold];
				hold++;
			}
			operands++;
			pfix += ' ';
			i = --hold;
		}

		if (temp[i] == '^') {
			tmp.push(temp[i]);
			operators++;
			precedence = 3;
		}

		if (temp[i] == '*' || temp[i] == '/') {
			tmp.push(temp[i]);
			operators++;
			precedence = 2;
		}

		if (temp[i] == '+' || temp[i] == '-') {
			if (precedence > 1) {
				if (tmp.top() == '(') {
					tmp.pop();
				}
				else {
					pfix += tmp.top();
					pfix += ' ';
					tmp.pop();

				}
			}
			tmp.push(temp[i]);
			operators++;
			precedence = 1;
		}

	}
	while (tmp.empty() != true) {
		if (tmp.empty()) {
			break;
		}
		if (tmp.top() == '(') {
			tmp.pop();
		}
		else {
			pfix += tmp.top();
			pfix += ' ';
			tmp.pop();

		}

	}


}


