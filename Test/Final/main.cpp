#include <cassert>
#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "MyClass.h"
#include "Song.h"

using namespace test;

int main()
{
	::std::map<std::string, uint32_t> map;
	map["Coco"] = 10;
	map["Sana"] = 20;
	map["Momo"] = 30;
	map["Mina"] = 40;

	Song s1("Santa tell me", "Ariana Grande");
	Song s2("Circle", "Post Malone");
	Song s3("Stand by me", "Ben E. king");

	auto magic = [=]()
	{
		for (auto it = map.begin(); it != map.end(); ++it)
		{
			std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
		}

		std::cout << "Hi " << s1.GetArtist() << std::endl;
		std::cout << "Hi " << s2.GetArtist() << std::endl;
		std::cout << "Hi " << s3.GetArtist() << std::endl;
	};

	magic();
}