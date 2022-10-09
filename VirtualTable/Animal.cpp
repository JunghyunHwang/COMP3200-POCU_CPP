#include "Animal.h"

namespace virtualtable
{
	Animal::Animal(unsigned int age)
		: mAge(age)
	{
	}

	Animal::Animal(const Animal& other)
	{
	}

	Animal::~Animal()
	{
	}

	unsigned int Animal::GetAge()
	{
		return mAge;
	}
}

