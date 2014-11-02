#include <iostream>
#include <string>

/*
Program to find the sum, product, or mean of a user-provided set of numbers
@author Saumya Soman
*/
/* Function to calculate sum of the numbers*/
float sum(int argc, char* argv[]){
	float sum = 0.0;

	// Loop through the arguments, convert them to float and add it with the sum
	for (int i = 2; i < argc; i++){
		sum += std::stof(std::string(argv[i]));
	}
	return sum;
}

/* Function to calculate product of the numbers*/
float product(int argc, char* argv[]){
	float product = 1.0;

	// Loop through the arguments, convert them to float and find product
	for (int i = 2; i < argc; i++){
		product *= std::stof(std::string(argv[i]));
	}
	return product;
}

/* Function to calculate mean of the numbers*/
float mean(int argc, char* argv[]){

	// Find sum and divide it by the count of numbers
	float total = sum(argc, argv);
	return total / (argc - 2);

}

/* Main method */
int main(int argc, char* argv[]){

	//Prompt user to select an operation
	if (argc == 1){
		std::cout << "Please select an operation : 'sum','product' or 'mean'";
		return 1;
	}

	//Prompt user to enter numbers
	if (argc == 2){
		std::cout << "Please insert atleast one number";
		return 1;
	}

	//save operation in a string variable
	std::string operation(argv[1]);

	// According to the selected operation, call the appropriate function.
	if (operation.compare("sum")==0){
		float result = sum(argc, argv);
		std::cout << "Sum of the numbers :" << result;
	}
	else if (operation.compare("product") == 0){
		float result = product(argc, argv);
		std::cout << "Product of the numbers :" << result;
	}
	else if (operation.compare("mean") == 0){
		float result = mean(argc, argv);
		std::cout << "Mean of the numbers :" << result;
	}
	else{
		std::cout << "Please select from operations 'sum','mean' or 'product'";
		return 1;
	}
	return 0;
}

