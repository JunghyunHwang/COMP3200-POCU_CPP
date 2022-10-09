#pragma once

#include <string>
#include "Animal.h"

namespace virtualtable
{
	class Cat : public Animal
	{
	public:
		Cat(unsigned int age, const char* name);
		virtual ~Cat();

		void SayName() const;
		void ChangeName(std::string name);

	private:
		std::string mName;
	};
}
