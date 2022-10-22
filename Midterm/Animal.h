#pragma once

#include <string>

class Animal
{
public:
	Animal(unsigned int age, std::string name);
	virtual ~Animal();
	
	virtual void Speak() const = 0;

protected:
	unsigned int mAge;
	std::string mName;
};