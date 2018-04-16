#include "MultTable.h"

#include <iostream>

using std::cout;
using std::endl;

MultTable::MultTable() {
	createTable(DEFAULT_SIZE);
}

MultTable::MultTable(int size) {
	createTable(size);
}


MultTable::MultTable(const MultTable& other) {
	copyTable(other);
}

MultTable& MultTable::operator=(const MultTable& other) {
	if (this != &other) { //Prevent self-assignment
		int** oldTable = table;
		int oldSize = size;
		copyTable(other);
		deleteTable(oldTable, oldSize);
	}
	return *this;
}

MultTable::~MultTable() {
	deleteTable(table, size);
}

void MultTable::deleteTable(int** table, int size) {
	if (table) {  // tmp != nullptr
		for (int i = 0; i < size; i++) {
			delete[] table[i];
		}
		delete[] table;
	}
	table = nullptr;
}

void MultTable::printTable() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

void MultTable::copyTable(const MultTable& other) {
	size = other.size;
	table = new int*[size];
	for (int i = 0; i < size; i++) {
		table[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			table[i][j] = other.table[i][j];
		}
	}
}

void MultTable::createTable(int size) {
	this->size = size;
	table = new int*[size];
	for (int i = 0; i < size; i++) {
		table[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			table[i][j] = (i+1)*(j+1); 
		}
	}
}