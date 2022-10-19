#include "Animal.h"

Animal::Animal(const char* name)
	: mName(name)
{
}

Animal::~Animal()
{
	delete mName;
}