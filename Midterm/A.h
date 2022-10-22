#pragma once

#include <string>
class B;

class A
{
public:
	A();
	virtual ~A();
	void Increase() const;

private:
	int mInt;
	unsigned int mUi;
	float mFloat;
	double mDouble;
	std::string mStr;
	int* mP;
	B* mB;
	static unsigned int mCount;
};

