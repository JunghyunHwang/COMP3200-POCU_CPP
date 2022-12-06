#include <iostream>

#include "MyString.h"

using namespace test;

int main()
{
	MyString ms1("All I want for christmas with you");
	MyString ms2("Santa tell me if you're really there");

	MyString copied1(ms1);
	MyString copied2 = ms2;

	std::cout << "First string: " << ms1 << std::endl;
	std::cout << "Second string: " << ms2 << std::endl;

	std::cout << "First copied string: " << copied1 << std::endl;
	std::cout << "Second copied string: " << copied2 << std::endl;

	return 0;
}