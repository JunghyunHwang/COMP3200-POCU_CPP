#pragma once
#include <iostream>

class Base
{
	virtual void method()
	{
		std::cout << "from Base" << std::endl;
	}

public:
	virtual ~Base()
	{
		method();
	}
	void baseMethod()
	{
		method();
	}
};

