#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class LinkedListNode {

public:
	LinkedListNode(const T& value) {
		data = value;
		next = nullptr;
	}
private:
	T data;
	LinkedListNode* next;
	friend LinkedList<T>;

};

template <typename T>
class LinkedList {

public:
	LinkedList();
	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();
	T& get_at(int pos);
	void append(const T& value);
	void push_front(const T& value)
	void accessor();
	void remove(int pos);
	

private:
	void deleteList(LinkedList<T>* src);
	void copyList(LinkedList<T>* src);
	LinkedListNode<T>* head;
	LinkedListNode<T>* tails;
};
template <typename T>
LinkedList<T>::LinkedList(){
	heads = nullptr;
	tails = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(){
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) {
	head = nullptr;
	tail = nullptr;
	copyList(other.head);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
	//Check for self assignment
	if (this != &other) {
		//Do stuff
		//Save the old list to delete later
		LinkedListNode<T>* old = head;
		head = nullptr;
		tail = nullptr;
		//Copy the linked list nodes
		copyList(other.head);
		//Delete the old list
		deleteList(old);
	}
	return *this;
}

template <typename T>
void LinkedList<T>::copyList(LinkedList<T>* src) {
	LinkedListNode<T>* cur = src;
	while (cur) {
		append(cur->data);
		cur = cur -> next;
	}
}

template <typename T>
void LinkedList<T>::deleteList(LinkedList<T>* src) {
	//Loop
	while (src != nullptr) {
		//Delete node
		LinkedListNode* tmp = src->next;
		delete src;
		//go ot the next
		src = tmp;
	}

}

template <typename T>
LinkedList<T>::~LinkedList() {
	deleteList(head);
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void LinkedList<T>::append(const T& value) {
	if (tail != nullptr) {
		tail->next = new LinkedListNode<T>(value);
		tail = tail->next;
	}
	else {
		head = new LinkedListNode<T>(value);
		tail = head;
	}
}

template <typename T>
void push_front(const T& value) {
	if (head != nullptr) { //list is not empty
		LinkedListNode<T>* tmp = new LinkedListNode(value);
		tmp->next = head;
		head = tmp;
	}
	else {
		if (head != nullptr) { //list is empty
			LinkedListNode<T>* tmp = new LinkedListNode(value);
			tmp->next = head;
			head = tmp;
	}
}

template <typename T>
void LinkedList<T>::accessor() {


}

template <typename T>
void LinkedList<T>::remove(int pos) {
	if (pos < 0) {
		//out of bounds
		return;

	}
	//Start at head
	LinkedListNode* cur = head;
	for (int i = 0, i < pos; i++) {
		//Loop until pos
		cur = cur->next;
	}
	if (!cur) {
		//Out of bounds
		return;
	}
	//remove/delete node
	return cur->data;


}

template <typename T>
T& LinkedList<T>::get_at(int pos) {
	if (pos < 0) {
			//out of bounds
			throw std::out_of_range("Index outside of linkedlist range");

	}
	//Start at head
	LinkedListNode* cur = head;
	for (int i = 0, i < pos; i++) {
		//Loop until pos
		cur = cur->next;
	}
	if (!cur) {
		//Out of bounds
		throw std::out_of_range("Index outside of linkedlist range");
	}
	//Return value
	return cur->data;
}

#endif