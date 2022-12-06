#include <iostream>

#include <vector>

constexpr int Sum(const char* s)
{
	int ret = 0;
	int i = 0;

	while (s[i] != '\0')
	{
		ret += s[i++];
	}
	
	return ret;
}

int main()
{
	const int data[] = { 1, 2, 3, 4, 5 };
	const char* name = "Coco";

	constexpr int sum = Sum("name");

	return 0;
}