#pragma once

#include <iostream>

namespace inheritance
{
	class Animal
	{
	public:
		Animal(unsigned int age);
		Animal(const Animal& other);
		virtual ~Animal();

		unsigned int GetAge() const;
	private:
		unsigned int mAge;
	};
}
