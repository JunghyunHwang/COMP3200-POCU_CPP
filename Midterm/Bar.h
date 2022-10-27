#pragma once
#include <iostream>
#include "Foo.h"

class Bar : public Foo
{
public:
	Bar();
	virtual ~Bar();
	void Print() const;
private:
	int mY;
};

