#pragma once

#include <iostream>
#include "Animal.h"

class Cat : public Animal
{
public:
	Cat(const char* name);
	virtual ~Cat();
	void PrintName() const;
};
