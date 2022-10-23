// main.cpp
#include <iostream>
#include <iomanip>

#include "Cat.h"

using namespace std;

int main()
{
	Animal* a1 = new Cat(3, "Phang");
	Animal a2(*a1);

	return 0;
}