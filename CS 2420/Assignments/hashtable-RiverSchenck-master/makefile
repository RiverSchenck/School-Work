HASHTABLE_EXE = bin/HashTableTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes

all:$(HASHTABLE_EXE)
.PHONY: all run test_hashtable memcheck_hashtable directories clean

run:$(HASHTABLE_EXE)
	@echo "Press enter to run HashTableTest"
	@read DUMMY
	$(HASHTABLE_EXE)
	@echo "Press enter to memcheck HashTableTest"
	@read DUMMY
	$(MEMCHECK) $(HASHTABLE_EXE)

test_hashtable: $(HASHTABLE_EXE)
	$(HASHTABLE_EXE)

memcheck_hashtable: $(HASHTABLE_EXE)
	$(MEMCHECK) $(HASHTABLE_EXE)

directories:
	mkdir -p obj
	mkdir -p bin

clean: directories
	rm bin/*
	rm obj/*

$(HASHTABLE_EXE):obj/HashTableTest.o 
	$(CC) $(OPTIONS) $(DEBUG) -o $(HASHTABLE_EXE) obj/HashTableTest.o
	
obj/HashTableTest.o:directories src/HashTableTest.cpp inc/HashTable.h inc/DoublyLinkedList.h
	$(CC) $(OPTIONS) $(DEBUG) -o obj/HashTableTest.o -c  -I inc/ src/HashTableTest.cpp
