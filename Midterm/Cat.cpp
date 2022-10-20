#include "Cat.h"

Cat::Cat(int age, std::string name)
	: Animal(age, name)
{
}

Cat::~Cat()
{
}

void Cat::SetName(std::string name)
{
	mName = name;
}

std::string Cat::GetName() const
{
	return mName;
}

void Cat::Speak() const
{
	std::cout << "My name is " << mName << std::endl;
}
