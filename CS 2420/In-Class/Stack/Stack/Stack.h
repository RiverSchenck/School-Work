#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

template <typename>
class Stack {
private:
	LinkedList<T> stack;

public:
	void push(T value);
	void pop();
	T top();
	bool is_empty();
};

template <typename T>
void Stack<T>::push(T value) {
	stack.push_front(value);
	//stack.append(value) this one change will make it a queue

}

template <typename T>
void Stack<T>::pop() {
	stack.remove(0);
}

template <typename T>
T Stack<T>::top() {
	try {
		return stack.get_at(0);
	}
	catch (out_of_range e) {
		throw out_of_range("Cannot peek at an empty stack");
	}
}

template <typename T>
bool Stack<T>::is_empty() {
	stack.is_empty();
}

#endif
