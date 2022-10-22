#pragma once

#include "A.h"

class B : public A
{
public:
	int GetNum()
	{
		return 10;
	}

	virtual int GetNegativeNum()
	{
		return -10;
	}
};

