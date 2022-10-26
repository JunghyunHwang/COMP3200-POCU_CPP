#include "Dog.h"

namespace test
{
	Dog::Dog(int age, const char* name)
		: Animal(age)
	{
		const char* pName;

		while (*pName++ != '\0')
		{
		}

		--pName;

		mName = new char[pName - name + 1];
		memcpy(mName, name, pName - name + 1);
	}

	Dog::Dog(const Dog& other)
		: Animal(other)
	{
		mName = new char[strlen(other.mName) + 1];
		memcpy(mName, other.mName, strlen(other.mName) + 1);
	}

	Dog::~Dog()
	{
		delete[] mName;
	}

	Dog& Dog::operator=(const Dog& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		Animal::operator=(rhs);
		delete[] mName;

		const char* pName = rhs.mName;

		while (*pName++ != '\0')
		{
		}

		--pName;

		mName = new char[pName - rhs.mName + 1];
		memcpy(mName, rhs.mName, pName - rhs.mName + 1);

		return *this;
	}

	void Dog::Speak() const
	{
		std::cout << "I'm dog my name " << mName << std::endl;
	}
}

