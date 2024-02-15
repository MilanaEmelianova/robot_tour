#include <iostream>
#include <fstream>
#include "../src/MazeSolver.h"
#include "MazeStringReader.h"
#include "MazePrint.h"
using namespace std;


void setOuter(MazeStringReader &msb)
{
	msb.setUsingDefault(false);
	// Set Start
	msb.addGoal(1, 2);
	// Set Goal
	msb.addGoal(2, 1);
}

template <typename path>
void findPath(Maze &maze, Vertex *start, Vertex *end, MazePrint &mp)
{
	maze.reset();
	path p;
	p.findPath(start, end);
	if (p.getPath().empty())
	{
		cout << "Path does not exist!\n";
	}
	else
	{
		mp.printPath(p.getPath());
	}

	char option;
	cout << "Number of iterations: " << p.getCount() << '\n';

	cout << "Cordinates of path: ";
	list<Coordinates> cord = p.getCordinatePath();
	for (auto &x : cord)
	{
		cout << '(' << x.row << ' ' << x.col << ") ";
	}
}

int main()
{
	ofstream MyMaze("test_cases/mymaze.txt");

	MyMaze << "+---+---+---+---+""\n"
			  "|       |       |""\n"
			  "+   +   +   +---+" "\n"
			  "|   |           |""\n"
			  "+   +       +   +""\n"
			  "|           |   |""\n"
			  "+   +---+   +---+""\n"
			  "|       |       |""\n"
			  "+---+---+---+---+";

	MyMaze.close();

	

	Maze maze;
	MazeStringReader msb;
	MazePrint mp;
	string in = "test_cases/mymaze.txt";

	// reads the file
	msb.getFile(in);
	// sets start and goal coordinates
	setOuter(msb);
	maze.setMaze(msb);
	// prints maze
	cout << "Built Maze.\nMaze Size: " << maze.getRow() * maze.getColumn() << "\nBuilt using " << maze.listSize() << '\n';
	mp.setMaze(maze, msb.getText());
	mp.printNodes();
	mp.printAt(maze.maze_begin(), 'S');
	mp.printAt(maze.maze_end(), 'E');
	mp.printMaze();
	maze.reset();
	mp.setMaze(maze, msb.getText());
	findPath<BreadthFirstSearch>(maze, maze.maze_begin(), maze.maze_end(), mp);
}