#pragma once
#include <iostream>
#include "Foo.h"

class Bar : public Foo
{
public:
	Bar();
	virtual ~Bar();
	virtual void PrintBar() const;
};

