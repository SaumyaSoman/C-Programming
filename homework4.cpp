/*******************************************************************************
* homework4.cpp
*
Homework 4 is just a small assignment to give you practice using polymorphic
classes and the type_info structure. The goal is simple; write a mammal.h and
mammal.cpp file so that the program in homework.cpp runs successfully.
You have been given a mammal.h file to start with that defines the Mammal
class and gives a function prototype for a function named MammalFactory. You
need to add definitions for the following classes: Carnivore, Canid, Dog, Fox,
Feline, Cat, Rodent, and Mouse. The inheritance relationships between the
classes are logical: Dog inherits from Canid, which inherits from Carnivore,
which inherits from Mammal. Fox inherits from Canid.  Cat inherits from Feline
which inherits from Carnivore. Mouse inherits from Rodent which inherits from
Mammal.


All classes should be pure virtual classes except for Dog, Fox, Cat, and
Mouse. Each of these give an implementation of the name() and say() functions.
The name function simply returns the name of the animal; for example, an
object of type Dog should return "dog" for the name function.  You can have
the animals return any string for the say() function. Take a look at the
week8_inclass.cpp file if the intent is not clear.



You will also need to implement the MammalFactory function.cpp file. The
MammalFactory function takes in a std::type_info object, checks if the
type_info corresponds to Cat, Dog, Mouse, or Fox and returns an object of the
corresponding type. If a type is given that matches none of those then a NULL
pointer should be returned.

*
* Programming Finance, Fall 2014
* Bernhard Firner
******************************************************************************/
#include <string>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "mammal.h"

int main(int argc, char** argv) {
	std::vector<Mammal*> mammals;
	mammals.push_back(MammalFactory(typeid(Dog)));
	mammals.push_back(MammalFactory(typeid(Cat)));
	mammals.push_back(MammalFactory(typeid(Mouse)));
	Mammal* fox = MammalFactory(typeid(Fox));

	for (Mammal* mammal : mammals) {
		std::cout << mammal->name() << " goes " << mammal->say() << '\n';
	}

	//Check animal names
	if (mammals.at(0)->name() != "dog") {
		std::cout << "Dog's name is incorrect!\n";
	}
	if (mammals.at(1)->name() != "cat") {
		std::cout << "Cat's name is incorrect!\n";
	}
	if (mammals.at(2)->name() != "mouse") {
		std::cout << "Mouse's name is incorrect!\n";
	}
	if (fox->name() != "fox") {
		std::cout << "Fox's name is incorrect!\n";
	}

	//Check to make sure everything belongs to the right kingdon, class, and order
	if (NULL == dynamic_cast<Canid*>(fox)) {
		std::cout << "Fox should be a Canid!\n";
	}
	if (NULL == dynamic_cast<Carnivore*>(fox)) {
		std::cout << "Fox should be a Carnivore!\n";
	}
	if (NULL == dynamic_cast<Canid*>(mammals.at(0))) {
		std::cout << "Dog should be a Canid!\n";
	}
	if (NULL == dynamic_cast<Carnivore*>(mammals.at(0))) {
		std::cout << "Dog should be a Carnivore!\n";
	}
	if (NULL == dynamic_cast<Feline*>(mammals.at(1))) {
		std::cout << "Cat should be a Feline!\n";
	}
	if (NULL == dynamic_cast<Carnivore*>(mammals.at(1))) {
		std::cout << "Cat should be a Carnivore!\n";
	}
	if (NULL == dynamic_cast<Rodent*>(mammals.at(2))) {
		std::cout << "Mouse should be a Rodent!\n";
	}
	if (NULL != dynamic_cast<Carnivore*>(mammals.at(2))) {
		std::cout << "Mouse should not be a Carnivore!\n";
	}


	//Need to delete everything!
	for (Mammal* mammal : mammals) {
		delete mammal;
	}

	return 0;
}
