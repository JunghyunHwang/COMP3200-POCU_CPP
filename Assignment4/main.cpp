#include <iostream>
#include <memory>

#include "TreeNode.h"

using namespace assignment4;

int main()
{
	TreeNode<int> n(std::make_unique<int>(2));
	std::cout << "No prob" << std::endl;
	return 0;
}