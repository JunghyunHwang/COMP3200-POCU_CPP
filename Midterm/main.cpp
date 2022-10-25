#include <iostream>
#include <string>

#include "MyString.h"
using namespace practice;

int main()
{
	MyString s("Hello, World");

	s += " Hello, World";

	std::cout << s << std::endl;

	return 0;
}