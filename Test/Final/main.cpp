#include <cassert>
#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "MyClass.h"

using namespace test;

int main()
{
	::std::map<std::string, uint32_t> map;
	map["Coco"] = 10;
	map["Sana"] = 20;
	map["Momo"] = 30;
	map["Mina"] = 40;

	for (auto it = map.begin(); it != map.end(); ++it)
	{
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
	}
}