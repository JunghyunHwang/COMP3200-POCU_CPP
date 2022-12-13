#pragma once

#include "Foo.h"

namespace test
{
	class Bar : public Foo
	{
	public:
		Bar() : Foo() {};
		~Bar() = delete;
		virtual void DoSomething(char x) override;
	};
}
