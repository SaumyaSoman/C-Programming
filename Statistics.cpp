/*
* Class that implements Statistics.h
* @author Saumya Soman
*/

#include "Statistics.h"
#include <cmath>

//Implementation of default constructor
Statistics::Statistics(){
	num = 0;
	oldAvg = 0;
}

//Implementation of push method. When input is entered; mean, variance and standard deviation is found. 
//Also number of samples is incremented.
void Statistics::push(double value){
	input = value;
	num++;
	findMean();
	findVariance();
	findstddev();
}

//Implementation of get number of samples method
int Statistics::total(){
	return num;
}

// Function to find mean
void Statistics::findMean(){

	if (num==1){
		avg = input;
	}
	else{
		oldAvg = avg;		
		avg = avg + ((input - avg) / num);
	}
}

// Function to find variance
void Statistics::findVariance(){

	if (num == 1){
		var = 0;
	}
	else{
		var = (var*(num-2)) + ((input - avg) * (input - oldAvg));
		var = var / (num - 1);
	}
}


// Function to find standard deviation
void Statistics::findstddev(){
	sd = sqrt(var);
}

// Implementation of mean getter method
double Statistics:: mean(){
	return avg;
}

// Implementation of variance getter method
double Statistics::variance(){
	return var;
}

// Implementation of standard deviation getter method
double Statistics::stddev(){
	return sd;
}