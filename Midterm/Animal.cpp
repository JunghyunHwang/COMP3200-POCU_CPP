#include "Animal.h"

Animal::Animal(const char* name)
{
	const char* pName = name;

	while (*pName++ != '\0')
	{
	}

	--pName;

	const unsigned int LENGTH = pName - name;

	mName = new char[LENGTH + 1];
	std::memcpy(mName, name, LENGTH + 1);
}

Animal::~Animal()
{
	delete mName;
}

std::ostream& operator<<(std::ostream& os, const Animal& rhs)
{
	rhs.PrintName();
	return os;
}