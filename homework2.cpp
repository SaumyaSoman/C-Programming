/*
* In class assignment for week 3.
* Saumya Soman
*
* This program will accept two command line arguments that represent a width
* and a height. The program will then print a grid of 'X' characters of that
* width and height.  Your program will then prompt the user to enter two
* numbers that represent a coordinate pair by row and column, and will print
* the grid again with the character at that position changed to an 'O'.
* That pattern will be repeated until the user "breaks" the input loop by
* typing control+c. Any positions changed to an O should remain that way
* with each repetition of the loop.
*/

#include <vector>
#include <iostream>
#include <string>

using std::vector;

//This function only parameter is a two-dimensional vector of char.
//The vector should be passed by reference.
//The return type is "void" because this function does not return anything.
void printGrid(vector<vector<char>>& grid) {
	//Loop over each row
	for (int i = 0; i < grid.size(); i++){
		//Loop over each column
		for (int j = 0; j < grid[i].size(); j++){
			//Print out the character at that location
			std::cout << grid[i][j] <<" ";
		}
		//Print out a new line after printing out each column in the row
		std::cout << "\n";
	}
	
}

int main(int argc, char** argv) {
	//First check user arguments. We require ints for width and a height

	if (argc != 3){
		std::cout << "Please insert height and width";
	}

	//Get the width and height
	int width = std::stoi(std::string (argv[1]));
	int height = std::stoi(std::string(argv[2]));

		//Make the grid. This is a vector of vectors. Make the
		//outer vector hold the rows (so it has "height" elements).
		//Make each inner vector have "width" elements.
		//Initialize all elements to 'X'

	vector<vector<char>> grid(height, vector<char>(width, 'X'));

		//Print out the grid
		printGrid(grid);

	std::cout << "Input coordinates by row and column\n";

	//Keep reading in new locations to set to 'O'
	int row, column;
	while (std::cin >> row >> column) {
		//Set the value at column,row to an 'O' character
		//Print out the grid
		grid[row][column] = 'O';
		printGrid(grid);
	}

	return 0;
}



