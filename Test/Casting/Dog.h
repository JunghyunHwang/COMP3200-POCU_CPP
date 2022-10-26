#pragma once

#include <iostream>
#include <string>
#include "Animal.h"

namespace test
{
	class Dog : public Animal
	{
	public:
		Dog(int age, const char* name);
		Dog(const Dog& other);
		virtual ~Dog();
		Dog& operator=(const Dog& rhs);

		void Speak() const;
	private:
		char* mName;
	};
}

