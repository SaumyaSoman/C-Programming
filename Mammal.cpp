/*******************************************************************************
* Mammal.cpp
*
* This class implements mammal.h
*
* Programming Finance, Fall 2014
* Saumya Soman
******************************************************************************/
#include "mammal.h"
#include <typeinfo>

//Implementation of Dog name function.
std::string Dog::name(){
	return "dog";
}

//Implementation of Dog say function.
std::string Dog::say(){
	return "bow wow!!";
}

//Implementation of Cat name function.
std::string Cat::name(){
	return "cat";
}

//Implementation of Cat say function.
std::string Cat::say(){
	return "meow meow!!";
}

//Implementation of Mouse name function.
std::string Mouse::name(){
	return "mouse";
}

//Implementation of Mouse say function.
std::string Mouse::say(){
	return "squeak squeak!!";
}

//Implementation of Fox name function.
std::string Fox::name(){
	return "fox";
}

//Implementation of Fox say function.
std::string Fox::say(){
	return "what does the fox say?";
}

//Implementation of the factory function to return animal depending on the type
Mammal* MammalFactory(const std::type_info& ti){
	Mammal* animal;

	if (ti == typeid(Cat)){
		animal = new Cat();
		return animal;
	}
	else if (ti == typeid(Mouse)){
		animal = new Mouse();
		return animal;
	}
	else if (ti == typeid(Dog)){
		animal = new Dog();
		return animal;
	}
	else if (ti == typeid(Fox)){
		animal = new Fox();
		return animal;
	}
	else
		return nullptr;
}
