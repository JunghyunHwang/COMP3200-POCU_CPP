#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> num1 = std::make_unique<int>(3);
	std::unique_ptr<int> num2 = std::move(num1);

	std::cout << *num2 << std::endl;

	return 0;
}