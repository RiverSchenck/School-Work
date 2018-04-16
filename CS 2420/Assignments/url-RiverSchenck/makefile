URL_EXE = bin/urlTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(URL_EXE)
.PHONY: all run test_url memcheck_url clean

run:$(URL_EXE)
	@echo "Press enter to run urlTest"
	@read DUMMY
	$(URL_EXE)
	@echo "Press enter to memcheck urlTest"
	@read DUMMY
	$(MEMCHECK) $(URL_EXE)

test_url: $(URL_EXE)
	$(URL_EXE)

memcheck_url: $(URL_EXE)
	$(MEMCHECK) $(URL_EXE)

clean:
	rm obj/*
	rm bin/*

$(URL_EXE):obj/Url.o obj/URLTest.o obj/DynamicString.o
	mkdir -p bin
	$(CC) $(OPTIONS) $(DEBUG) -o $(URL_EXE) obj/Url.o obj/URLTest.o obj/DynamicString.o

obj/URLTest.o:src/URLTest.cpp
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/URLTest.o -c  -I inc/ src/URLTest.cpp

obj/Url.o:src/Url.cpp inc/Url.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/Url.o -c  -I inc/ src/Url.cpp

obj/DynamicString.o:src/DynamicString.cpp inc/DynamicString.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/DynamicString.o -c  -I inc/ src/DynamicString.cpp
