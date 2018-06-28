# Club Membership Linked List

A registry of club members can be created in the form of an **ordered** linked list of Member data objects.  Each Member object is an element or node in the linked list. The information for each Member includes an Identification Number, Last Name, First Initial, and Yearly Dues.

The data for five existing club members are contained in a file named **Member.dat**. You will write a program that implements a generic ordered linked list, creates an instance of this list that contains Member objects, reads existing member data from **Member.dat** , inserts members into the list, and removes members from the list.

The program must satisfy all test statements contained in the associated starter file.

## Goals:
The purpose of this project is to continue working with C++ classes, practice working with templates, and understand and implement the concepts of a linked list data structure.

## Requirements:
Code construction can be divided into two primary tasks:

### 1. **MemberDO class**

Create a data object class named **MemberDO** that represents the data for a club member. The names of the data members and the associated data types are as follows:

	int key;

	string lastName;

	char firstInitial;

	double dues;

The key represents the unique ID number of the club member and will be used exclusively to locate nodes in the implementation of the linked list methods.

The following methods should be implemented for the MemberDO class:

1. Default constructor.
2. Four-argument constructor that initializes each data member to a specific value passed as a parameter to this method.
3. Appropriate getter and setter methods.  The getter methods should have names that correspond with the calls used in the test code contained in the starter file.
4. A static method named **readFromFile** that takes a C-string as the first parameter, and an orderedLinkedList&lt;MemberDO&gt; object as the second parameter. The first argument is the filename that contains data for existing members.  This method should read the data for each individual member from the input file (one line of data per member), create a new MemberDO object, and insert this object into the linked list specified in the second argument.  Implelmenting this method is extra-credit.  You can use the implementation provided which just inserts the data without reading it from a file if you do not want the extra credit.

### 2. **orderedLinkedList class**

Create a generic **ordered** linked list class named **orderedLinkedList** using template syntax. The generic nodes for this linked list should be defined exactly as shown at the bottom of p.279 of the text. The linked list should have **at most** three **private** data members:

1. a pointer to the first node in the list
2. a pointer to the last node in the list
3. a count of the number of nodes in the list

The **orderedLinkedList** should implement the following methods and satisfy each of the associated specifications as given here:

	orderedLinkedList();

	// default constructor

	// initializes the list to an empty state

	// Postcondition: first = NULL, last = NULL, count = 0;

	int insert(const Type&amp; newItem);

	// Function to insert newItem in the ordered list

	//  Key values should be used exclusively to find appropriate

	//     location for inserted object

	// Postcondition: first points to the new list, newItem

	//    is inserted at the proper place in the list, and

	//    count is incremented by 1

	// Return: Key value of item inserted on the list

	Type \* get(int location) const;

	// Function to find the object at a specific location on the list

	// For example, if location = 0, find the first item on the list

	// If location = 4, find the fifth item on the list

	// Postcondition: Status of list not changed

	// Return: Object if found, NULL if object not found or if

	//    location value is &lt;= 0.

	Type \* find(int key) const;

	// Function to find the object by key in the list

	// For example, find the item with key=1123 in the list

	// Postcondition: Status of list not changed

	// Return: Object if found, NULL if object not found

	int remove(int keyValue);

	// Function to remove an item with key == keyValue from the list

	//  Key values should be used exclusively to identify

	//     object to be removed

	// Postcondition: if found the node with key == keyValue is

	//   removed from the list;

	//   first points to the first node of the new list; count is

	//   decremented by 1.

	// Return: If item is in list, return key, else return -1.

**As noted in the above specifications, the ordered linked list methods should be implemented such that node identification is accomplished using only key comparisons.**
