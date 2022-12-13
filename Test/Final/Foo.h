#pragma once

#include <iostream>

namespace test
{
	class Foo
	{
	public:
		Foo() = default;
		~Foo() = default;
		virtual void DoSomething(char c);
	};
}