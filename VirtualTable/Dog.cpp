#include <iostream>
#include "Dog.h"

namespace virtualtable
{
	Dog::Dog(unsigned int age, const char* name)
		: Animal(age)
		, mName(name)
	{
	}

	Dog::~Dog()
	{
	}

	void Dog::SayName() const
	{
		std::cout << mName << std::endl;
	}

	void Dog::ChangeName(std::string name)
	{
		mName = name;
	}
}
