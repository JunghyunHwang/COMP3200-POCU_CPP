#pragma once

namespace virtualtable
{
	class Animal
	{
	public:
		Animal(unsigned int age);
		Animal(const Animal& other);
		virtual ~Animal();

		unsigned int GetAge();
		virtual void SayName() const = 0;
	private:
		unsigned int mAge;
	};
}

