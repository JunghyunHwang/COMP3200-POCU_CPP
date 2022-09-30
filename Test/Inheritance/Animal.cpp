#include "Animal.h"

namespace inheritance
{
	Animal::Animal(unsigned int age)
		: mAge(age)
	{
	}

	Animal::Animal(const Animal& other)
		: mAge(other.mAge)
	{
	}

	Animal::~Animal()
	{
		std::cout << "Call destructor Animal" << std::endl;
	}

	unsigned int Animal::GetAge() const
	{
		return mAge;
	}
}
