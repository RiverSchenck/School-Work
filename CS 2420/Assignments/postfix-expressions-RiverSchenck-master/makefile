INFIX_EXE = bin/InfixTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(INFIX_EXE)
.PHONY: all run test_infix memcheck_infix directories clean

run:$(INFIX_EXE)
	@echo "Press enter to run InfixTest"
	@read DUMMY
	$(INFIX_EXE)
	@echo "Press enter to memcheck InfixTest"
	@read DUMMY
	$(MEMCHECK) $(INFIX_EXE)

test_infix: $(INFIX_EXE)
	$(INFIX_EXE)

memcheck_infix: $(INFIX_EXE)
	$(MEMCHECK) $(INFIX_EXE)

directories:
	mkdir -p obj
	mkdir -p bin

clean: directories
	rm bin/*
	rm obj/*

$(INFIX_EXE):obj/InfixTest.o obj/Infix.o
	$(CC) $(OPTIONS) $(DEBUG) -o $(INFIX_EXE) obj/InfixTest.o obj/infix.o
	
obj/InfixTest.o:directories src/InfixTest.cpp inc/Infix.h
	$(CC) $(OPTIONS) $(DEBUG) -o obj/InfixTest.o -c  -I inc/ src/InfixTest.cpp

obj/Infix.o:directories src/Infix.cpp inc/Infix.h
	$(CC) $(OPTIONS) $(DEBUG) -o obj/Infix.o -c  -I inc/ src/Infix.cpp
