#ifndef MULT_TABLE_H
#define MULT_TABLE_H

#define DEFAULT_SIZE 10

class MultTable {

public:
	MultTable();
	MultTable(int size);
	MultTable(const MultTable& other);
	MultTable& operator=(const MultTable& other);
	~MultTable();
	void printTable();
	//void foo(MultTable other);

private:
	void deleteTable(int** table, int size);
	void copyTable(const MultTable& other);
	void createTable(int size);
	int** table;
	int size;

};


#endif
