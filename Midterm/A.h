#pragma once

#include <iostream>
#include "Base.h"

class A : public Base
{
	void method()
	{
		std::cout << "from A" << std::endl;
	}
public:
	~A()
	{
		method();
	}
};

