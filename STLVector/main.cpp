#include <iostream>
#include <vector>

int main()
{
	std::vector<int> nums;
	nums.reserve(10);

	nums.assign(7, 100);

	nums.resize(2);

	return 0;
}