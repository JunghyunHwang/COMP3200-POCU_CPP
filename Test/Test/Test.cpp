#include "Test.h"

namespace test
{
	void TestPractice()
	{
		auto v1 = std::make_shared<Vector>(2, 7);
		auto v2 = std::make_shared<Vector>(4, 3);

		v1->DoMagic(v2);
		v2->DoMagic(v1);

		std::cout << v1->GetX() << " " << v1->GetY() << std::endl;
		std::cout << v2->GetX() << " " << v2->GetY() << std::endl;
	}

	void TestVector()
	{
		std::vector<int> vi;
		std::vector<float> vf;
		std::vector<std::string> vs;
		std::vector<Vector*> vv;

		vi.reserve(10);
		vf.reserve(10);
		vs.reserve(10);
		vv.reserve(10);

		vi.push_back(1);
		vi.push_back(2);
		vi.push_back(3);
		vi.push_back(4);
		vi.push_back(5);

		vf.push_back(1.0f);
		vf.push_back(2.0f);
		vf.push_back(3.0f);
		vf.push_back(4.0f);
		vf.push_back(5.0f);

		vs.push_back("Hi");
		vs.push_back("my");
		vs.push_back("name");
		vs.push_back("is");

		Vector* vec1 = new Vector(1, 1);
		Vector* vec2 = new Vector(2, 2);
		Vector* vec3 = new Vector(3, 3);

		vv.push_back(vec1);
		vv.push_back(vec2);
		vv.push_back(vec3);

		vi.resize(1);
		vf.resize(1);
		vs.resize(1);
		vv.resize(1);

		delete vec1;
		delete vec2;
		delete vec3;
	}

	void TestMap()
	{
		std::map<std::string, unsigned int> scores;

		scores.insert(std::pair<std::string, unsigned int>("JaHwang", 100));
		scores.insert(std::pair<std::string, unsigned int>("Baro", 100));
		scores.insert(std::pair<std::string, unsigned int>("Juneseok", 100));
		scores.insert(std::pair<std::string, unsigned int>("Coco", 80));

		if (scores.find("Ho") == scores.end())
		{
			scores["Ho"] = 100;
		}

		for (auto it = scores.rbegin(); it != scores.rend(); ++it)
		{
			std::cout << it->first << ": " << it->second << std::endl;
		}
	}

	void TestSmartPointer()
	{
		auto sp = std::make_unique<std::unique_ptr<int>>(std::make_unique<int>(3));

		assert(**sp == 3);
	}
}
