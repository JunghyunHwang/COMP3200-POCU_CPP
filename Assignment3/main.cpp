#include <iostream>
#include <limits>
#include <cassert>
#include <stack>

#include "Test.h"

using namespace assignment3;

int main()
{
	/*TestOfficial();
	TestWiki1();
	TestWiki2();
	TestSmartStack();
	TestSmartQueue();
	TestQueueStack();*/

	std::stack<int>* s1 = new std::stack<int>();
	s1->push(1);
	s1->push(2);
	s1->push(3);

	std::stack<int>* s2 = new std::stack<int>(*s1);
	
	std::cout << s2->top() << std::endl;
	s2->pop();

	std::cout << s2->top() << std::endl;
	s2->pop();

	std::cout << s2->top() << std::endl;
	s2->pop();

	std::cout << s1->top() << std::endl;

	delete s1;
	delete s2;

	std::cout << "No prob" << std::endl;
	return 0;
}