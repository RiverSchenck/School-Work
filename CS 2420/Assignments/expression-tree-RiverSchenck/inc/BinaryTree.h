#ifndef H_BinaryTree
#define H_BinaryTree
#include <iostream>
#include <ostream>
#include <cstddef>
using std::string;

template <class T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode<T> *leftside;
	BinaryTreeNode<T> *rightside;

	BinaryTreeNode()
	{
		leftside = NULL;
		rightside = NULL;
	}
	BinaryTreeNode(T value)
	{
		data = value;
		leftside = NULL;
		rightside = NULL;
	}
};

template <class T>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree<T> &otherTree);
	const BinaryTree<T>& operator= (const BinaryTree<T> &otherTree);
	~BinaryTree();
	void destroy();
	bool isOperator(char op);
	void inOrderTraversal(std::ostream& out) const;
	void postOrderTraversal(std::ostream& out) const;
	int numnode() const;
	void build(BinaryTreeNode<T>* node, T value);
	void build(T value);
protected:
	BinaryTreeNode<T> *root;

private:
	int pos;
	void destroy(BinaryTreeNode<T>* &p);	
	void copyTree(BinaryTreeNode<T>* &copyRoot, BinaryTreeNode<T>* Root);
	void inOrder(BinaryTreeNode<T> *tree, std::ostream& out) const;
	void postOrder(BinaryTreeNode<T> *tree, std::ostream& out, int& count) const;
	int numnode(BinaryTreeNode<T>* tree) const;
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
	pos = 0;
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &otherTree)//copy constructor
{
	pos = otherTree.pos;
	if (otherTree.root == NULL)
	{
		root = NULL;

		pos = 0;
	}

	else
		copyTree(root, otherTree.root);
}

template<class T>
void BinaryTree<T>::copyTree(BinaryTreeNode<T>* &copyRoot, BinaryTreeNode<T>* Root  )//copy constructor method for deep copy
{
	if (Root == NULL) {
		
			copyRoot = NULL;
	}

	else
	{
		copyRoot = new BinaryTreeNode<T>;
		copyRoot->data = Root->data;
		copyTree(copyRoot->rightside, Root->rightside);
		copyTree(copyRoot->leftside, Root->leftside);		
		pos = 0;
	}

}

template <class T>
BinaryTree<T>::~BinaryTree()//Calls destroy
{
	destroy(root);
}

template <class T>
void BinaryTree<T>::destroy(BinaryTreeNode<T>* &tree)
{
	//destroy tree
	if (tree != NULL)
	{
		destroy(tree->leftside);
		destroy(tree->rightside);
		delete tree;
		tree = NULL;
		pos = 0;
	}
}

template <class T>
void BinaryTree<T>::destroy()
{

	destroy(root);

}

template <class T>
const BinaryTree<T>& BinaryTree<T>:: operator=(const BinaryTree<T> &otherTree)
{

	if (root != NULL) { //not empty,destroy tree

		destroy(root);
	}

	if (otherTree.root == NULL) {//other is empty

		root = NULL;
	}

	else
		copyTree(root, otherTree.root);
	
	return *this;
}

template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *tree, std::ostream& out) const
{
	//in order
	if (tree != NULL)
	{
		inOrder(tree->leftside, out);//left
		out << tree->data;		  
		inOrder(tree->rightside, out);//right
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *tree, std::ostream& out, int& count) const
{
	//postorder
	int num = numnode();

	if (tree != NULL)
	{
		postOrder(tree->leftside, out, count);//left
		postOrder(tree->rightside, out, count);//right

		if (tree != NULL && count >= num)
		{
			out << tree->data;				//whitespace
			return;
		}
		count++;
		out << tree->data << " ";			
	}
}

template <class T>
void BinaryTree<T>::inOrderTraversal(std::ostream& out) const
{
	inOrder(root, out);
}

template <class T>
void BinaryTree<T>::postOrderTraversal(std::ostream& out) const
{
	int count = 1;
	postOrder(root, out, count);
}

template <class T>
void BinaryTree<T>::build(BinaryTreeNode<T>* node, T value)
{
	string tmp;

	while (value[pos])
	{
		if (value[pos] == '(')
		{
			node->leftside = new BinaryTreeNode<T>();//new left node
			pos++;

			if (node->leftside)
			{
				build(node->leftside, value);//go left
			}
		}
		else if (isdigit(value[pos]))
		{
			tmp = "";
			while (isdigit(value[pos]))
			{
				tmp += value[pos];
				pos++;
			}
			node->data = tmp;
			return;
		}

		else if (isOperator(value[pos]))
		{
			string val(1, value[pos]);
			node->data = val;
			node->rightside = new BinaryTreeNode<T>();//new node right
			pos++;
			if (node->rightside)
			{
				build(node->rightside, value);//go right
			}
		}

		else if (value[pos] == ')')
		{
			pos++;
			return;
		}
	}
}

template <class T>
void BinaryTree<T>::build(T val)
{
	if (root) {
		build(root, val);
	}
	else
	{
		root = new BinaryTreeNode<T>(val);//null, new node
		build(val);
	}
}

template <class T>
bool BinaryTree<T>::isOperator(char operat) //is char an operator
{
	if (operat == '/' || operat == '*' || operat == '-' || operat == '+' || operat == '^')
		return true;
	else
		return false;
}

template <class T>
int BinaryTree<T>::numnode() const
{
	return numnode(root);
}

template <class T>
int BinaryTree<T>::numnode(BinaryTreeNode<T>* tree) const
{
	if (tree != NULL)
	{
		return numnode(tree->leftside) + numnode(tree->rightside) + 1;
	}
	else
		return 0;
}
#endif