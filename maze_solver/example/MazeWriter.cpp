#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream MyMaze("test_cases/maze.txt");

	MyMaze << "hello maze";

	MyMaze.close();
}