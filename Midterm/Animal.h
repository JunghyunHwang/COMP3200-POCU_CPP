#pragma once

#include <string>

class Animal
{
	friend std::ostream& operator<<(std::ostream& os, const Animal& rhs);
public:
	Animal(const char* name);
	virtual ~Animal();
	virtual void PrintName() const = 0;

protected:
	char* mName;
};