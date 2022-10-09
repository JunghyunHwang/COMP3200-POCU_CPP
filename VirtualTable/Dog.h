#pragma once

#include <string>
#include "Animal.h"

namespace virtualtable
{
	class Dog : public Animal
	{
	public:
		Dog(unsigned int age, const char* name);
		virtual ~Dog();

		void SayName() const;
		void ChangeName(std::string name);

	private:
		std::string mName;
	};
}


