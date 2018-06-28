//River Schenck
//CS 2420 Fuez
//Hashtables

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stddef.h> //valgrind
#include <string>
#include "DoublyLinkedList.h"

using std::string;
/*GOAL: for this assignment is to comment better so I dont lose easy points*/


/* OBJECTIVE
For this assignment, you will complete functionality for two classes: 
doublyLinkedList and hashTable. The main purpose of the hashTable class 
is to provide a linked list driven hash table to store many key value 
pairs for fast insertion and retrieval. Each linked list referenced by 
the hash table is an instance of the doublyLinkedList class. Many of 
the methods for the hashTable and doublyLinkedList class have already 
been implemented for you.*/

//--------------------------------------------
//Two hash functions for you to complete
//--------------------------------------------
unsigned int hashFunctionInt(const void *void_key) {
    //Get that parameter back into an int pointer.  
    unsigned int *temp = static_cast<unsigned int *>(const_cast<void *>(void_key));
    unsigned int key = *temp;
    // You need to hash the int variable key and return a value between 0 and 999.
	return *temp % 1000;

}

unsigned int hashFunctionString(const void *void_key) {
    string *temp = static_cast<string *>(const_cast<void *>(void_key));
    string key = *temp;

	unsigned int hash = 0;

	//add characters

	for (int i = 0; i < key.size(); i++)
	{
		hash += int(key[i]);
	}

	return hash % 1000;

}
    



//***********************************
//The hash table class
//***********************************
//Complete the methods indicated by TODO below.  Implement a doubly linked list.  These methods must work as specified in the assignment.
template <typename T, typename U>
class hashTable{
public:

    hashTable() {hashFunction = &hashFunctionInt; linkedListArray = new DoublyLinkedList<T, U>[NUMBER_OF_LINKED_LISTS];}
    hashTable(unsigned int(*hashFunction)(const void *));
    hashTable(const hashTable& obj);
    ~hashTable();
    hashTable& operator=( hashTable tmp );

    void add(const T& key, const U& value);
    bool exists(const T& key) const;
    void remove(const T& key);
    U& item(const T& key);
    U& operator[](const T& key);

    //friended so the checkTest function can have access to private data members of this class.
    friend void testSimpleIntHash();
    friend void testHashOfObjects();

protected:

    DoublyLinkedList<T, U> *linkedListArray; //The array of linked lists
    unsigned int hash(const T& key) const;
private:
    int getWorstBucket() const;
    int getTotalCount() const;
    unsigned int(*hashFunction)(const void*);
    static const int NUMBER_OF_LINKED_LISTS = 1000;
};

template <typename T, typename U>
hashTable<T,U>::hashTable(unsigned int (* hashFunction)(const void*)) {

    this->hashFunction = hashFunction;
    //TODO: Initialize an array of 1000 linked lists using the 
    //new keyword, storing the array starting address in the 
    //pointer linkedListArray
	linkedListArray = new DoublyLinkedList<T, U>[1000];

}


//==============================================================
//copy constructor
//==============================================================
template <typename T, typename U>
hashTable<T,U>::hashTable(const hashTable& obj) {
    this->hashFunction = obj.hashFunction;
    if (obj.linkedListArray == NULL) {
        this->linkedListArray = NULL;
    } else {
        this->linkedListArray = new DoublyLinkedList<T, U>[NUMBER_OF_LINKED_LISTS];    
        for (int i = 0; i < NUMBER_OF_LINKED_LISTS; i++) {
            this->linkedListArray[i] = obj.linkedListArray[i];
        }
    }
}

//==============================================================
//assingment operator
//==============================================================
template <typename T, typename U>
hashTable<T,U>& hashTable<T,U>::operator=( hashTable<T,U> tmp ) {
    this->hashFunction = tmp.hashFunction;
	delete [] (this->linkedListArray);
	if (tmp.linkedListArray == NULL) {
        this->linkedListArray = NULL;
    } else { 
		this->linkedListArray = new DoublyLinkedList<T, U>[NUMBER_OF_LINKED_LISTS];
        for (int i = 0; i < NUMBER_OF_LINKED_LISTS; i++) {
            this->linkedListArray[i] = tmp.linkedListArray[i];
        }
    }
    return *this;
}

//==============================================================
//deconstrucor
//==============================================================
template <typename T, typename U>
hashTable<T,U>::~hashTable() {
    if (linkedListArray != NULL) {
        delete[] linkedListArray;
    }

}

//==============================================================
//add function- Add an item to the hashtable
//==============================================================
template <typename T, typename U>
void hashTable<T, U>::add(const T& key, const U& value)  {

	int hold = hash(key);
	linkedListArray[hold].insertLast(key, value);  
}

//==============================================================
//exists function- Returns true if the key is in the hashtable, false otherwise
//==============================================================
template <typename T, typename U>
bool hashTable<T, U>::exists(const T& key) const {

	int hold = hash(key);
	return linkedListArray[hold].nodeWithKeyExists(key);

}

//==============================================================
//item function- Returns the data by reference associated with the key
//==============================================================
template <typename T, typename U>
U& hashTable<T, U>::item(const T& key) {
 
	int hold = hash(key);
	return linkedListArray[hold].searchForKey(key);
}

//==============================================================
//operator function- Returns the data by reference associated with the key
//==============================================================
template <typename T, typename U>
U& hashTable<T, U>::operator[](const T& key) {

	int hold = hash(key);
	return linkedListArray[hold].searchForKey(key);
}


//==============================================================
//remove function- Removes an item from the hash table.
//==============================================================
template <typename T, typename U>
void hashTable<T, U>::remove(const T& key) {
 
	int hold = hash(key);
	return linkedListArray[hold].deleteNodeWithKey(key);
 
}



template <typename T, typename U>
unsigned int hashTable<T, U>::hash(const T& key) const {
    //A helpful method which does all the function pointer work
    //for you so it knows which hash function to call.
    return (*hashFunction)(&key);
}

template <typename T, typename U>
int hashTable<T, U>::getWorstBucket() const{
    int count;
    int highest = 0;
    if (linkedListArray != NULL) {
        for (int i = 0; i < 1000; i++) {
            count = linkedListArray[i].getCount();
            if (count > highest) {
                highest = count;
            }
        }
    }
    return highest;
}

template <typename T, typename U>
int hashTable<T, U>::getTotalCount() const{
    int count;
    int sum = 0;
    if (linkedListArray != NULL) {
        for (int i = 0; i < 1000; i++) {
            count = linkedListArray[i].getCount();
            sum += count;
        }
    }
    return sum;
}

#endif

