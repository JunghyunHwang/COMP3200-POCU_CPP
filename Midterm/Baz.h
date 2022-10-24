#pragma once
#include "Bar.h"

class Baz : public Bar
{
public:
	Baz();
	virtual ~Baz();
	void PrintBaz() const;
};

