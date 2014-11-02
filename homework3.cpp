#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
* Homework 2-  Program to store a sorted list of floating point numbers and allows users 
* to add or remove numbers from the list by interactively giving commands
* @author Saumya Soman
*/

using namespace std;

//Method to print numbers in the list
void print(vector<double>& vec){

	//If list is empty
	if (vec.size() == 0){
		cout << "There are no elements in the list";
	}
	else{
		//Iterate through the vector to print each number.
		for each (double x in vec)
		{
			std::cout << x << "\n";
		}
	}
}

//Method to insert numbers to the list
void insert(vector<double>& vec){

	typedef vector<double>::iterator iterator;

	//Accept the number to be added from user
	string number;
	cout << "Insert what number?";
	cin >> number;
	double num = std::stod(number);

	// Add the number as the last element in the vector
	vec.push_back(num);

	// Arrange the position of the number added, in the vector using insertion sort.

	//If only one element in the vector, return.
	if (vec.begin() == vec.end()){
		return;
	}

	for (iterator I = vec.begin()+1; I != vec.end(); ++I){
		iterator J = I;
		while (J != vec.begin() && *J < *(J-1)){
			std::swap(*J, *(J-1));
			--J;
		}
	}
}

//Method to remove numbers from the list
void remove(vector<double>& vec){

	//Accept the number to be removed from user
	string number;
	cout << "Remove what number?";
	cin >> number;
	double num = std::stod(number);

	std::vector<double>::iterator position = std::find(vec.begin(), vec.end(), num);
	//Check to see if number was found in the list
	if (position != vec.end())  {
		//The number is removed from the vector using erase()
		vec.erase(position);
	}
}

int main(int __argc, char**__argv){

	cout << "Enter a command : 'insert' , 'remove' or 'print' \n";
	string input;
	
	//Declare an empty vector
	vector<double> vec(0);

	//Receive commands from input
	while (cin >> input){

		if (input.compare("insert") == 0){
			//call insert function if command is insert
			insert(vec);
		}
		else if (input.compare("remove") == 0){
			//call remove function if command is remove
			remove(vec);
		}
		else if (input.compare("print") == 0){
			//call print function if command is print
			print(vec);
		}
		else{
			//If command is not 'insert' , 'remove' or 'print'
			cout << "Please enter a valid command";
		}
	}	
	return 0;
}