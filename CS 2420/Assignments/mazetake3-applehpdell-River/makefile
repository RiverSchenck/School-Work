MAZE_EXE = bin/MazeTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes


.PHONY: all run test_maze memcheck_maze clean

all:$(MAZE_EXE)


run:$(MAZE_EXE)
	@echo "Press enter to run MazeTest"
	@read DUMMY
	$(MAZE_EXE)
	@echo "Press enter to memcheck MazeTest"
	@read DUMMY
	$(MEMCHECK) $(MAZE_EXE)

test_maze: $(MAZE_EXE)
	$(MAZE_EXE)

memcheck_maze: $(MAZE_EXE)
	$(MEMCHECK) $(MAZE_EXE)

clean: directories
	rm obj/*
	rm bin/*

$(MAZE_EXE):obj/MazeTest.o obj/Maze.o obj/OS_Utils.o
	mkdir -p bin
	$(CC) $(OPTIONS) $(DEBUG) -o $(MAZE_EXE) obj/MazeTest.o obj/Maze.o obj/OS_Utils.o

obj/MazeTest.o:src/MazeTest.cpp inc/Maze.h inc/OS_Utils.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/MazeTest.o -c  -I inc/ src/MazeTest.cpp

obj/Maze.o:src/Maze.cpp inc/Maze.h inc/OS_Utils.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/Maze.o -c  -I inc/ src/Maze.cpp

obj/OS_Utils.o:src/OS_Utils.cpp inc/OS_Utils.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/OS_Utils.o -c  -I inc/ src/OS_Utils.cpp
