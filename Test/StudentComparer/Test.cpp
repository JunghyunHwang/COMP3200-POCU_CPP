#include "Test.h"

namespace test
{
	struct StudentComparer
	{
		bool operator()(const Student& a, const Student& b) const
		{
			if (a.GetName() == b.GetName())
			{
				return a.GetId() < b.GetId();
			}

			return a.GetName() < b.GetName();
		}
	};

	void TestMemberFunctionComparer()
	{
		std::map<Student, uint32_t, StudentComparer> scores;
		Student s1("Ja hwang");
		Student s2("Baro kim");
		Student s3("June seok");
		Student s4("Coco");

		scores.insert(std::pair<Student, uint32_t>(s1, 100));
		scores.insert(std::pair<Student, uint32_t>(s2, 100));
		scores.insert(std::pair<Student, uint32_t>(s3, 100));
		scores.insert(std::pair<Student, uint32_t>(s4, 100));

		std::vector<Student> expected;

		expected.push_back(s2);
		expected.push_back(s4);
		expected.push_back(s1);
		expected.push_back(s3);

		uint32_t i = 0;

		for (auto it = scores.begin(); it != scores.end(); ++it)
		{
			std::cout << it->first.GetId() << ". " << it->first.GetName() << ": " << it->second << std::endl;
			assert(expected[i++] == it->first);
		}
	}
}
