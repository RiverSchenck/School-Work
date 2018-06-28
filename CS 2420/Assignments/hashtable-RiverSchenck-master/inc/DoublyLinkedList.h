//River Schenck
//CS 2420 Fuez
//Hashtables

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <stddef.h> //valgrind

//--------------------------------------------
//The Node class
//--------------------------------------------
template <typename T, typename U>
class Node{
public:
    T key;
    U data;
    Node *backward;
    Node *forward;

};


//--------------------------------------------
//For error handling
//--------------------------------------------
class Error {};



//--------------------------------------------
//The linked list base class.
//--------------------------------------------
//Complete the methods indicated by TODO below.  Implement a doubly linked list.  These methods must work as specified in the assignment.
template <typename T, typename U>
class DoublyLinkedList{
private:
    int count;
    Node<T, U> *beginning;
    Node<T, U> *last;

    void destroyList();

public:



    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList(); 
    ~DoublyLinkedList();     
    int getCount() const;
    void insertLast(const T&, const U&);
    bool nodeWithKeyExists(const T&) const;
    U& searchForKey(const T&);
    void deleteNodeWithKey(const T&);

};

template <typename T, typename U>
DoublyLinkedList<T, U>::DoublyLinkedList(){
    beginning = NULL;
    last = NULL;
    count = 0;
}

//=============================================================
//copy constructor- given
//=============================================================
template <typename T, typename U>
DoublyLinkedList<T, U>::DoublyLinkedList(const DoublyLinkedList<T,U>& other){

    if (other.beginning != NULL) {
        Node<T,U> *temp = new Node<T,U>();
        temp->key = other.beginning->key;
        temp->data = other.beginning->data;
        temp->backward = NULL;
        temp->forward = NULL;
        this->beginning = temp;
    }
    if (other.beginning == NULL) {
        this->beginning = NULL;
        this->last = NULL;
        count = 0;
        return;
    }
    //start at the second node now
    Node<T,U> *before = other.beginning;
    Node<T,U> *now = other.beginning->forward;
    while (now != NULL) {
        Node<T,U> *temp = new Node<T,U>();
        temp->key = now->key;
        temp->data = now->data;
        temp->backward == before;
        before->forward = temp;
        temp->forward = NULL;
        before = now;
        now = now->forward;

		//memory managment
		delete *temp;
		delete *before;
		delete *now;

    }
    last = before;

    this->count = other.count;

}


template <typename T, typename U>
DoublyLinkedList<T, U>::~DoublyLinkedList(){    
    this->destroyList();
}

//Destroy the list, and reclaim all memory.
template <typename T, typename U>
void DoublyLinkedList<T, U>::destroyList() {
    Node<T, U> *temp;
    while (beginning != NULL) {
        temp = beginning;
        beginning = beginning->forward;
        delete temp;
    }
    last = NULL;
    count = 0;


}

//Returns the number of nodes in this linked list.
template <typename T, typename U>
int DoublyLinkedList<T,U>::getCount() const {
    return count;
}
//Done


//=============================================================
//insert last- Append a node to the end of the list
//=============================================================
template <typename T, typename U>
void DoublyLinkedList<T, U>::insertLast(const T& key, const U& value) {
	Node<T, U> * temp = NULL;
	temp = new Node<T, U>; //make code

	temp->forward = NULL;
	temp->backward = NULL;
	temp->key = key;
	temp->data = value;

	if (last != NULL) { //elements
		last->forward = temp;
		temp->backward = last;
		last = temp;
		count++;
	}

	if (beginning == NULL) { //empty
		beginning = temp;
		last = temp;
		count++;
	}

}


//=============================================================
//node with key exitst - Returns true if a node with key is 
//in the list, false otherwise
//=============================================================
template <typename T, typename U>
bool DoublyLinkedList<T, U>::nodeWithKeyExists(const T& key) const {


	Node<T, U> *temp = beginning; //start at front

	if (temp) { //if NULL return false
		if (temp->key == key) {
		return true;
		}
		else {
			temp = temp->forward;
		}
	}

	return false;
}

//=============================================================
//search for key- Returns the data by reference of the associated
//key. Throws an Error if no key exists
//=============================================================
template <typename T, typename U>
U& DoublyLinkedList<T, U>::searchForKey(const T& key) {

	Node<T, U> *temp = this->beginning;//start at front

	if (temp) { //if NULL return false
		if (key == temp->key) {

			return temp->data;
		}
		else {
			temp = temp->forward;
		}
	}

	
	throw Error(); //error if nothing to delete
}

//=============================================================
//deletes node with key- Deletes the node with the specified key
//=============================================================
template <typename T, typename U>
void DoublyLinkedList<T, U>::deleteNodeWithKey(const T& key) {
	
	Node<T, U> *temp = beginning; //start at front


	while (temp != NULL) { //if NULL, return false
		if (temp->key == key) {

			if (temp->backward != NULL) {
				temp->backward->forward = temp->forward;
			}
			else {
				beginning = temp->forward;
			}
			if (temp->forward != NULL) {
				temp->forward->backward = temp->backward;

			}
			else {
				last = temp->backward;
			}
			delete temp;
			temp = NULL;
			count--;
			break;

		}
		temp = temp->forward;
	}
    
}

#endif

