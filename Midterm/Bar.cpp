#include "Bar.h"

Bar::Bar()
	: mY(0)
{
}

Bar::~Bar()
{
}

void Bar::Print() const
{
	std::cout << "Bar" << std::endl;
}