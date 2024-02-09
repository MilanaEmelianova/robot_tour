#include <iostream>
#include <fstream>
using namespace std;

// turn into .h file and include in driver.cpp

int main() {
	// specify the path in driver.cpp
	ofstream MyMaze("test_cases/maze2.txt");

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