#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // Create and open a text file
  ofstream MyFile("test_cases/testmaze.txt");

  // Write to the file
  MyFile << 
"+---+---+---+---+" "\n"
"|               |" "\n"
"+   +       |   +" "\n"
"|   |           |" "\n"
"+   +   +---+   +" "\n"
"|               |" "\n"
"+   +   +---+---+" "\n"
"|   |           |" "\n"
"+---+---+---+---+"
;

  // Close the file
  MyFile.close();
}