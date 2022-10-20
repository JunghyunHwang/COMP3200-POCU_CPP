#include "Animal.h"

std::string Animal::mName = "";

Animal::Animal(int age, std::string name)
	: mAge(age)
{
	mName = name;
}

Animal::~Animal()
{
}