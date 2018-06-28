#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

template <class Type>
struct Node
{
	Type info;
	Node *next;
};


template <class Type>
class OrderedLinkedList
{
public:
	OrderedLinkedList();
	OrderedLinkedList(const OrderedLinkedList& other);
	~OrderedLinkedList();
	
	OrderedLinkedList<Type>& operator=(const OrderedLinkedList<Type>& other);
	
	int insert(const Type&);
	Type* find(int) const;
	Type* get(int) const;
	int remove(int);
    void clear(); //clears and empties
    int size() const;
	void print() const;
	void copyList(const OrderedLinkedList& src);
	Node<Type>* head;
	Node<Type>* tail;
	int pos;
};

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList() {
	pos = 0;
	head = nullptr;
	tail = nullptr;
	
}

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList(const OrderedLinkedList<Type>& other) {

	copyList(other);

}

template <class Type>
OrderedLinkedList<Type>::~OrderedLinkedList() {
	Node<Type> *hold;
	while (head != nullptr) {
		hold = head;
		head = head->next;
		delete hold;
	}
}

template <class Type>
OrderedLinkedList<Type>& OrderedLinkedList<Type>::operator=(const OrderedLinkedList& other) {
	copyList(other);
	return *this;
}

template <class Type>
void OrderedLinkedList<Type>::copyList(const OrderedLinkedList& other) {
MemberDO copy; 


	Node<Type>* position = other.head;
	Node<Type>* hold = nullptr;
	Node<Type>* prev = nullptr;
	
	int i = 0;

	while (position != nullptr) {
		hold = new Node<Type>();

		copy = *other.get(i);
		hold->info.setDues(copy.getDues());
		hold->info.setKey(copy.getKey());
		hold->info.setFirstInitial(copy.getFirstInitial());
		hold->info.setLastName(copy.getLastName());

		i++;

if (prev != nullptr) {
prev->next = hold;
}
else {
head = hold;
}
position = position->next;
prev = hold;
}

	tail = hold;
}

template <class Type>
int OrderedLinkedList<Type>::insert(const Type& item) {
Node<Type> *position;
Node<Type> *afterposition = nullptr;
Node<Type> *thisNode;
bool holding;

thisNode = new Node<Type>;
thisNode->info = item;
thisNode->next = nullptr;

	if (head == nullptr) {
		head = thisNode;
		tail = thisNode;
		pos++;
	}

	else {
		holding = false;
		position = head;
		
		while (position != nullptr && holding != true) {
			if (position->info.getKey() >= item.getKey()) {
				holding = true;
			}
			else {
				afterposition = position;
				position = position->next;
			}
		}
		if (position == head)
		{
			thisNode->next = head;
			head = thisNode;
			pos++;
		}
		else {
			afterposition->next = thisNode;
			thisNode->next = position;

			if (position == nullptr) {
				tail = thisNode;
			}
			pos++;
		}
	}
	return thisNode->info.getKey();

}

template <class Type>
Type* OrderedLinkedList<Type>::get(int dest) const {
	Node<Type> *position;
	position = head;


	int i = 0;
	while (position != nullptr && i <= dest) {
		if (i == dest)
			return &position->info;
			i++;
		position = position->next;
	}
	return nullptr;
}

template <class Type>
Type* OrderedLinkedList<Type>::find(int dest) const {
	bool holding = false;
	Node<Type> *position;
	position = head;

	while (position != nullptr && holding != true) {

if (position->info.getKey() == dest)
	holding = true;
else
	position = position->next;
}
if (holding == true)
	return &position->info;
else {
	return nullptr;
}
}

template <class Type>
int OrderedLinkedList<Type>::remove(int key) {
	Node<Type> *position;
	Node<Type> *afterposition = nullptr;
	bool holding = false;

	if (head == nullptr)
		return -1;
	else {
		position = head;
		holding = false;
		while (position != nullptr && holding != true) {
			if (position->info.getKey() >= key)
				holding = true;
			else {
				afterposition = position;
				position = position->next;
			}
		}
		if (position == nullptr) {
			return -1;
		}
		else {
			if (position->info.getKey() == key) {
				if (head == position) {
					head = head->next;
					if (head == nullptr) {
						tail = nullptr;
					}
					pos--;
					return position->info.getKey();
					delete position;
				}
				else {
					afterposition->next = position->next;
					if (position == tail)
						tail = afterposition;
					pos--;
					return position->info.getKey();
					delete position;
				}
			}
			else {
				return -1;
			}
		}
	}

}

template <class Type>
void OrderedLinkedList<Type>::clear() {
	Node<Type> *hold;
	while (head != nullptr) {
		hold = head;
		head = head->next;
		delete hold;
	}
	tail = nullptr;
	head = nullptr;
	pos = 0;
}


template <class Type>
int OrderedLinkedList<Type>::size() const
{
	return pos;
}

template <class Type>
void OrderedLinkedList<Type>::print() const
{
	Node<Type>* position = head;
	while (position != nullptr) {
		position-> info.print();
		position = position->next;
	}
	delete position;
}
#endif