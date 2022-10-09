
#include "Cat.h"
#include "Dog.h"
#include "Tree.h"

using namespace virtualtable;

int main()
{
	Cat* c1 = new Cat(3, "Meow");
	
	c1->SayName();

	Tree* t = new Tree(200);

	return 0;
}