#include "expressionTree.h"
#include <string>


using std::string;
using std::endl;


ExpressionTree::ExpressionTree() : BinaryTree() //empty expression tree
{
	
}

ExpressionTree::ExpressionTree(std::string exp) : BinaryTree() //expression tree
{
	build(exp);
}

void ExpressionTree::setExpression(std::string exp) //destroys old tree, makes new
{
	destroy();
	build(exp);
}

double ExpressionTree::getResult() //eval then returns
{
	return eval();
}

void ExpressionTree::printParseTreeInOrder(std::ostream& os)  //inOrderTraversal.
{
	inOrderTraversal(os);
}

void ExpressionTree::printParseTreePostOrder(std::ostream& os)  //postOrderTraversal
{
	postOrderTraversal(os);
}

double ExpressionTree::eval() const
{
	return eval(root);
}

double ExpressionTree::eval(BinaryTreeNode<string>* node) const
{
	double number;

	if (node == NULL)//null return 0
		return 0;

	if (isdigit(node->data[0])) //result should be the number
	{
		string string = node->data;
		number = stod(string);
		return number;
	}

	double left = eval(node->leftside);//left tree
	double right = eval(node->rightside);//right tree

	if (node->data == "-")
		return left - right;

	if (node->data == "+")
		return left + right;

	if (node->data == "/")
		return left / right;

	if (node->data == "*")
		return left * right;

	if (node->data == "^")
		return pow(left, right);

	else
		return 0;
}

