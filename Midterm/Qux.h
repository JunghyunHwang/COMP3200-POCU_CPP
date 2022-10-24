#pragma once
#include "Baz.h"
class Qux : public Baz
{
public:
	Qux();
	virtual ~Qux();
	void PrintBar() const;
};

