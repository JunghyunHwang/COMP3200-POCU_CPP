#include <iostream>
#include "Cat.h"

namespace virtualtable
{
	Cat::Cat(unsigned int age, const char* name)
		: Animal(age)
		, mName(name)
	{
	}

	Cat::~Cat()
	{
	}

	void Cat::SayName() const
	{
		std::cout << mName << std::endl;
	}

	void Cat::ChangeName(std::string name)
	{
		mName = name;
	}
}

