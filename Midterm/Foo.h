#pragma once

class Foo
{
public:
	Foo(int x);
	~Foo();
	Foo operator+(const Foo& f) const;
	static unsigned int GetCount();

private:
	int mX;
	static unsigned int mCount;
};

