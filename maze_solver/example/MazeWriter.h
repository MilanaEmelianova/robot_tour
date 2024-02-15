#ifndef __MAZEWRITER__
#define __MAZEWRITER__

#include <iostream>
#include <fstream>
using namespace std;

// rewrite the function so it would take the maze as an argument
int main() {
	ofstream MyMaze("test_cases/mymaze.txt");

	MyMaze << 
"+---+---+---+---+" "\n"
"|               |" "\n"
"+   +---+   +---+" "\n"
"|   |           |" "\n"
"+   +   +---+   +" "\n"
"|           |   |" "\n"
"+   +---+   +---+" "\n"
"|               |" "\n"
"+---+---+---+---+"
;

	MyMaze.close();
}

#endif // !__MAZESWRITER__