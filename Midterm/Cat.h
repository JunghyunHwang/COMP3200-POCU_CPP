#pragma once

#include <iostream>
#include "Animal.h"

class Cat
{
public:
	Cat();
	int GetCount() const;
private:
	static int mCount;
};

