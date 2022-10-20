#pragma once

#include <string>

class Animal
{
public:
	Animal(int age, std::string name);
	virtual ~Animal();
	
	virtual void Speak() const = 0;

protected:
	int mAge;
	static std::string mName;
};