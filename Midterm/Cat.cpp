#include "Cat.h"

int Cat::mCount = 10;
Cat::Cat()
{
	mCount++;
}

int Cat::GetCount() const
{
	return mCount / 3;
}