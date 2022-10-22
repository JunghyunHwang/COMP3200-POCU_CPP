#include "A.h"

unsigned int A::mCount = 0;
A::A()
{
}

A::~A()
{
}

void A::Increase() const
{
	++mCount;
}
