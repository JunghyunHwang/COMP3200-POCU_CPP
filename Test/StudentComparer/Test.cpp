#include "Test.h"

namespace test
{
	void TestMemberFunctionComparer()
	{
		std::map<Student, uint32_t> scores;
		Student s1("Ja hwang");
		Student s2("Baro kim");
		Student s3("June seok");
		Student s4("Coco");

		scores.insert(std::pair<Student, uint32_t>(s1, 100));
		scores.insert(std::pair<Student, uint32_t>(s2, 100));
		scores.insert(std::pair<Student, uint32_t>(s3, 100));
		scores.insert(std::pair<Student, uint32_t>(s4, 100));

		for (auto it = scores.begin(); it != scores.end(); ++it)
		{
			std::cout << it->first.GetId() << ". " << it->first.GetName() << ": " << it->second << std::endl;
		}
	}

	void TestStructComparer()
	{
	}
}
