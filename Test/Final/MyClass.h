#pragma once

#include <iostream>

namespace test
{
	template<typename T, typename U>
	class MyClass
	{
	public:
		MyClass(T t, U u);
		void DoSomething();

	private:
		T mT;
		U mU;
	};

	template<typename T, typename U>
	MyClass<T, U>::MyClass(T t, U u)
		: mT(t)
		, mU(u)
	{
	}

	template<typename T, typename U>
	void MyClass<T, U>::DoSomething()
	{
		std::cout << "Foo" << std::endl;
	}

	template<typename U>
	class MyClass<int, U>
	{
	public:
		MyClass(int t, U u);
		void DoSomething();

	private:
		int mT;
		U mU;
	};

	template<typename U>
	MyClass<int, U>::MyClass(int t, U u)
		: mT(t)
		, mU(u)
	{
	}

	template<typename U>
	void MyClass<int, U>::DoSomething()
	{
		std::cout << "Bar" << std::endl;
	}
}
