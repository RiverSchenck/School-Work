LINKEDLIST_EXE = bin/LinkedListTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(LINKEDLIST_EXE)
.PHONY: all run test_linkedlist memcheck_linkedlist directories clean

run:$(LINKEDLIST_EXE)
	@echo "Press enter to run staticTest"
	@read DUMMY
	$(LINKEDLIST_EXE)
	@echo "Press enter to memcheck staticTest"
	@read DUMMY
	$(MEMCHECK) $(LINKEDLIST_EXE)

test_linkedlist: $(LINKEDLIST_EXE)
	$(LINKEDLIST_EXE)

memcheck_linkedlist: $(LINKEDLIST_EXE)
	$(MEMCHECK) $(LINKEDLIST_EXE)

directories:
	mkdir -p obj
	mkdir -p bin

clean: directories
	rm bin/*
	rm obj/*

$(LINKEDLIST_EXE):obj/LinkedListTest.o obj/MemberDO.o
	$(CC) $(OPTIONS) $(DEBUG) -o $(LINKEDLIST_EXE) obj/LinkedListTest.o obj/MemberDO.o
	cp Member.dat bin/Member.dat

obj/LinkedListTest.o:directories src/LinkedListTest.cpp inc/LinkedList.h
	$(CC) $(OPTIONS) $(DEBUG) -o obj/LinkedListTest.o -c  -I inc/ src/LinkedListTest.cpp

obj/MemberDO.o:directories src/MemberDO.cpp inc/MemberDO.h
	$(CC) $(OPTIONS) $(DEBUG) -o obj/MemberDO.o -c  -I inc/ src/MemberDO.cpp
