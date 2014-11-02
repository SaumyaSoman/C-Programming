/*
* Header file for mammal
* @author Saumya Soman
*/
#include <string>
#include <typeinfo>

//Abstract class for animal
class Mammal {
public:
	virtual std::string say() = 0;
	virtual std::string name() = 0;
};

//Create and return a new animal with the given name
Mammal* MammalFactory(const std::type_info& ti);

//Abstract class for Carnivore
class Carnivore :public 
	Mammal {
public:
	virtual std::string say() = 0;
	virtual std::string name() = 0;
};

//Abstract class for Canid
class Canid : public Carnivore {
public:
	virtual std::string say() = 0;
	virtual std::string name() = 0;
};

//Abstract class for Rodent
class Rodent :public Mammal {
public:
	virtual std::string say() = 0;
	virtual std::string name() = 0;
};

//Abstract class for Feline
class Feline :public Carnivore {
public:
	virtual std::string say() = 0;
	virtual std::string name() = 0;
};

//Dog Class
class Dog: public Canid{
public:
	 std::string say();
	 std::string name();
};

//Fox Class
class Fox :public Canid{
public:
	 std::string say();
	 std::string name();
};

//Mouse Class
class Mouse :public Rodent {
public:
	 std::string say();
	 std::string name();
};

//Cat Class
class Cat :public Feline {
public:
	 std::string say();
	 std::string name();
};