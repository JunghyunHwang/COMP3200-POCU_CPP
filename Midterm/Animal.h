#pragma once

class Animal
{
public:
	Animal(const char* name);
	~Animal();
	virtual void PrintName() const = 0;

protected:
	const char* mName;
};

