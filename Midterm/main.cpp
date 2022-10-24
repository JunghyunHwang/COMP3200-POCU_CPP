#include <iostream>
#include <string.h>

int main()
{
	std::string strTempA = "A";
	std::string strTempB = "B";

	std::string result = "";
	for (int i = 0; i < 5; ++i)
	{
		result += strTempA.c_str();
	}

	return 0;
}