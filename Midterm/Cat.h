#pragma once

#include <iostream>
#include <string>
#include "Animal.h"

class Cat : public Animal
{
public:
	Cat(int age, std::string name);
	virtual ~Cat();
	
	void SetName(std::string name);
	std::string GetName() const;
	void Speak() const;
};
