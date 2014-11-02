/*
* This program will test your submission for homework 3.
* This program will attempt to create an instance of a class named "Statistics"
* that is defined in a file named "statistics.h".
*
* You should implement the functionality of your Statistics class in another
* file that is named "statistics.cpp".
*
* Your statistics class will keep track of the statistics of a stream of samples
* Your class should support the following member functions:
*   push     - Process another floating point sample (a double)
*   total    - return the total number of samples (an integer)
*   mean     - return the sample mean (a double)
*   variance - return the sample variance (a double)
*   stddev   - return the sample standard deviation (a double)
*
* Your code should *not* store any of the samples! Instead you should use the
* method described in the instructions. Specifically, you should take advantage
* of this recurrence relation:
*
* At the first sample the mean is equal to the sample:
* Mean_1 = x_1
*
* When adding a sample the mean increases by the difference between the new
* sample and the current mean, scaled by the total number of samples
* Mean_k = Mean_(k-1) + (x_k - Mean_(k-1)) / k
*
* At the first sample the variance is equal to 0:
* Variance_1 = 0
*
* With subsequent samples the variance increases by the difference between the
* new sample and the current mean multiplied by the difference between the
* new sample and the previous mean:
* Variance_k = (Variance_(k-1)*(k-2) + (x_k - Mean_(k-1)) * (x_k - Mean_k))/(k - 1)
*
* If the mean, variance, or stddev functions are called before the push()
* function is called for the first time, just return 0.0. You will need to
* include cmath in order to use the sqrt function to convert variance to a
* standard deviation.
*
* Written by Bernhard Firner, 2014
*/

#include "statistics.h"
#include <iostream>


int main(int argc, char** argv) {
	//Create a new instance of your class.
	//Statistics of all input numbers
	Statistics all_stat;
	//Statistics of just the positive numbers input
	Statistics positive_stat;

	double input;
	std::cout << "Provide numbers upon which to compute statistics.\n";
	std::cout << "Press ctrl+d or type a non-numeric string to stop.\n";
	while (std::cin >> input) {
		all_stat.push(input);
		std::cout << "Mean and variance are now: " << all_stat.mean() << " and " << all_stat.variance() << '\n';
		//Only push this value into the positive statistics if it is positive
		if (0.0 < input) {
			positive_stat.push(input);
			std::cout << "Mean and variance of positive numbers are now: " << positive_stat.mean() << " and " << positive_stat.variance() << '\n';
		}
	}
	//Print out the final statistics
	std::cout << "After " << all_stat.total() << " samples, the mean, variance, and standard deviation are " <<
		all_stat.mean() << " and " << all_stat.variance() << " and " << all_stat.stddev() << '\n';

	std::cout << "After " << positive_stat.total() << " positive samples, the mean, variance, and standard deviation are " <<
		positive_stat.mean() << " and " << positive_stat.variance() << " and " << positive_stat.stddev() << '\n';

	return 0;
}
