#include "Dog.h"

namespace inheritance
{
	Dog::Dog(unsigned int age, const char* name)
		: Animal(age)
		, mName(name)
	{
	}
	
	Dog::Dog(const Dog& other)
		: Animal(other)
		, mName(other.mName)
	{
	}

	Dog::~Dog()
	{
		std::cout << "Call destructor Dog" << std::endl;
	}

	void Dog::SayName() const
	{
		std::cout << mName << std::endl;
	}
}