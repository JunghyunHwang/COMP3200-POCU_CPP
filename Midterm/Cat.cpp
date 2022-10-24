#include "Cat.h"

Cat::Cat(const char* name)
	: Animal(name)
{
}

Cat::~Cat()
{
}

void Cat::PrintName() const
{
	std::cout << "I'm cat named " << mName;
}