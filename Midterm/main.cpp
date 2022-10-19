#include <iostream>
#include <iomanip>
#include <string>

#include "A.h"

int main()
{
	A a(10, 20);
	int* arr = (int*)&a;
	std::cout << arr[2] << std::endl;
}