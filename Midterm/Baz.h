#pragma once
#include "Foo.h"

class Baz : public Foo
{
public:
	Baz();
	virtual ~Baz();
	int GetX() const;
};

