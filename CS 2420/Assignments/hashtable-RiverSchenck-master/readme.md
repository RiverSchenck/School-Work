# LinkedList Hash Table

Hashtables are used when you want to find items effeciently.  In this assignment you will implement a hashtable which resloves collisions using chaining (via a doubly-linked list).  Some code has been provided to help you get started.

## Goals:
The goal of this assignment is to implement hashtables with chaining, understand the importance of hash functions, and practice with complex multi-class projects.

## Requirements:
For this assignment, you will complete functionality for two classes: *doublyLinkedList* and *hashTable*. The main purpose of the *hashTable*  class is to provide a linked
list driven hash table to store many key value pairs for fast insertion and retrieval. Each linked list referenced by the hash table is an instance of the *doublyLinkedList* class. Many of the methods for the hashTable and doublyLinkedList class have already been implemented for you.

### HashTable class

Non member functions:
+ hashFunctionInt //hashes a int key to a value in the range from 0-999 (inclusive)
+ hashFunctionString //hashes a string key to a value in the range from 0-999 (inclusive)

Public data members: 
+ hashTable() {/* some constructor code */}
+ hashTable(unsigned int(*hashFunction)(const void *));
+ hashTable(const hashTable& obj);
+ ~hashTable();
+ hashTable& operator=( hashTable tmp );

+ void add(const T& key, const U& value); // Add an item to the hashtable
+ bool exists(const T& key) const; // Returns true if the key is in the hashtable, false otherwise
+ void remove(const T& key); //Removes an item from the hash table. 
+ U& item(const T& key); //Returns the data by reference associated with the key
+ U& operator[](const T& key); //Returns the data by reference associated with the key

Friended so the checkTest function can have access to private data members of this class.
+ friend void testSimpleIntHash();
+ friend void testHashOfObjects();

Protected data members:
+ DoublyLinkedList<T, U> *linkedListArray; //The array of linked lists
+ unsigned int hash(const T& key) const;
Private data members:
+ int getWorstBucket() const;
+ int getTotalCount() const;
+ unsigned int(*hashFunction)(const void*);
+ static const int NUMBER_OF_LINKED_LISTS = 1000;

### Doubly-linked list class

Public data members:
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList(); 
    ~DoublyLinkedList();
    int getCount() const;

    void insertLast(const T&, const U&); //Append a node to the end of the list
    bool nodeWithKeyExists(const T&) const; //Returns true if a node with key is in the list, false otherwise
    U& searchForKey(const T&); //Returns the data by reference of the associated key. Throws an Error if no key exists
    void deleteNodeWithKey(const T&); //Deletes the node with the specified key

Private data members:
    int count;
    Node<T, U> *first;
    Node<T, U> *last;
    void destroyList();


## Helpful Hints:

Only implement the methods with //TODO comments. You do not need to modify any others.

You can assume that only one unique key is allowed in the table. Duplicate keys should overwrite the existing value.

Understand the existing code before you start implementing your own methods.

