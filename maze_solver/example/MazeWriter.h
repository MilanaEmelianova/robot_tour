#ifndef __MAZEWRITER__
#define __MAZEWRITER__

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// turn into .h file and include in driver.cpp

int write(string filename) {
	// specify the path in driver.cpp
	// ofstream MyMaze("test_cases/maze2.txt");
	ofstream MyMaze(filename);

	MyMaze << 
	//write in driver.cpp
"+---+---+---+---+" "\n"
"|               |" "\n"
"+   +       +---+" "\n"
"|   |       |   |" "\n"
"+   +---+   +   +" "\n"
"|               |" "\n"
"+   +---+   +---+" "\n"
"|       |       |" "\n"
"+---+---+---+---+"
;

	MyMaze.close();
}

#endif