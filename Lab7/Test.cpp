#include "Test.h"

namespace lab7
{
	enum eCapacityForMain
	{
		DEFAULT_CAPACITY = 16
	};
	
	void TestOfficial()
	{
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		std::vector<char> v2;
		v2.push_back('a');
		v2.push_back('b');
		v2.push_back('c');

		std::vector<int> v3;
		v3.push_back(4);
		v3.push_back(5);
		v3.push_back(6);

		std::map<char, int> m1;
		m1['a'] = 1;
		m1['b'] = 2;
		m1['c'] = 3;

		std::map<char, int> m2;
		m2['d'] = 4;
		m2['e'] = 5;
		m2['f'] = 6;

		std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);
		{
			std::map<int, char>::const_iterator it = m.begin();

			assert(it->first == 1);
			assert(it->second == 'a');
			it++;
			assert(it->first == 2);
			assert(it->second == 'b');
			it++;
			assert(it->first == 3);
			assert(it->second == 'c');
		}
		
		std::vector<char> keys = lab7::GetKeys(m1);
		{
			std::vector<char>::const_iterator it = keys.begin();

			assert(*it == 'a');
			it++;
			assert(*it == 'b');
			it++;
			assert(*it == 'c');
		}

		std::vector<int> values = lab7::GetValues(m1);
		{
			std::vector<int>::const_iterator it = values.begin();

			assert(*it == 1);
			it++;
			assert(*it == 2);
			it++;
			assert(*it == 3);
		}

		std::vector<int> reversedV1 = lab7::Reverse(v1);
		{
			assert(reversedV1[0] == v1[2]);
			assert(reversedV1[1] == v1[1]);
			assert(reversedV1[2] == v1[0]);
		}

		std::vector<int> combinedVector = v1 + v3;
		{
			assert(combinedVector.size() == 6);
			assert(combinedVector[0] == 1);
			assert(combinedVector[1] == 2);
			assert(combinedVector[2] == 3);
			assert(combinedVector[3] == 4);
			assert(combinedVector[4] == 5);
			assert(combinedVector[5] == 6);
		}

		std::map<char, int> combinedMap = m1 + m2;
		{
			std::map<char, int>::const_iterator it = combinedMap.begin();

			assert(combinedMap.size() == 6);

			assert(it->first == 'a');
			assert(it->second == 1);
			it++;
			assert(it->first == 'b');
			assert(it->second == 2);
			it++;
			assert(it->first == 'c');
			assert(it->second == 3);
			it++;
			assert(it->first == 'd');
			assert(it->second == 4);
			it++;
			assert(it->first == 'e');
			assert(it->second == 5);
			it++;
			assert(it->first == 'f');
			assert(it->second == 6);
		}

		std::cout << v1 << std::endl;
		std::cout << m1 << std::endl;
	}

	void TestWiki()
	{
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		std::vector<char> v2;
		v2.push_back('a');
		v2.push_back('b');
		v2.push_back('c');

		std::vector<int> v3;
		v3.push_back(4);
		v3.push_back(5);
		v3.push_back(6);

		std::vector<int> v4;
		v4.push_back(1);
		v4.push_back(1);
		v4.push_back(2);
		v4.push_back(3);

		std::vector<int> v5;
		v5.push_back(1);
		v5.push_back(2);
		v5.push_back(4);
		v5.push_back(3);

		std::map<char, int> m1;
		m1['a'] = 1;
		m1['b'] = 2;
		m1['c'] = 3;

		std::map<char, int> m2;
		m2['d'] = 4;
		m2['e'] = 5;
		m2['f'] = 6;

		std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);
		{
			std::map<int, char>::const_iterator it = m.begin();

			assert(it->first == 1);
			assert(it->second == 'a');
			it++;
			assert(it->first == 2);
			assert(it->second == 'b');
			it++;
			assert(it->first == 3);
			assert(it->second == 'c');
		}

		std::vector<char> keys = lab7::GetKeys(m1);
		{
			std::vector<char>::const_iterator it = keys.begin();

			assert(*it == 'a');
			it++;
			assert(*it == 'b');
			it++;
			assert(*it == 'c');
		}

		std::vector<int> values = lab7::GetValues(m1);
		{
			std::vector<int>::const_iterator it = values.begin();

			assert(*it == 1);
			it++;
			assert(*it == 2);
			it++;
			assert(*it == 3);
		}

		std::vector<int> reversedV1 = lab7::Reverse(v1);
		{
			assert(reversedV1[0] == v1[2]);
			assert(reversedV1[1] == v1[1]);
			assert(reversedV1[2] == v1[0]);
		}

		std::vector<int> combinedVector = v1 + v3;
		{
			assert(combinedVector.size() == 6);
			assert(combinedVector[0] == 1);
			assert(combinedVector[1] == 2);
			assert(combinedVector[2] == 3);
			assert(combinedVector[3] == 4);
			assert(combinedVector[4] == 5);
			assert(combinedVector[5] == 6);
		}

		std::vector<int> v4plusv5 = v4 + v5;
		{
			std::vector<int>::const_iterator it = v4plusv5.begin();

			assert(v4plusv5.size() == 4);

			assert(*it == 1);
			it++;
			assert(*it == 2);
			it++;
			assert(*it == 3);
			it++;
			assert(*it == 4);
		}

		std::map<char, int> combinedMap = m1 + m2;
		{
			std::map<char, int>::const_iterator it = combinedMap.begin();

			assert(combinedMap.size() == 6);

			assert(it->first == 'a');
			assert(it->second == 1);
			it++;
			assert(it->first == 'b');
			assert(it->second == 2);
			it++;
			assert(it->first == 'c');
			assert(it->second == 3);
			it++;
			assert(it->first == 'd');
			assert(it->second == 4);
			it++;
			assert(it->first == 'e');
			assert(it->second == 5);
			it++;
			assert(it->first == 'f');
			assert(it->second == 6);
		}

		std::cout << v1 << std::endl;
		std::cout << m1 << std::endl;

		{
			std::vector<int> vector1;
			vector1.reserve(eCapacityForMain::DEFAULT_CAPACITY);

			vector1.push_back(1);
			vector1.push_back(2);
			vector1.push_back(3);
			vector1.push_back(4);
			vector1.push_back(5);
			vector1.push_back(6);

			std::vector<int> vector2;
			vector2.reserve(eCapacityForMain::DEFAULT_CAPACITY);

			vector2.push_back(7);
			vector2.push_back(8);
			vector2.push_back(9);
			vector2.push_back(1);
			vector2.push_back(2);
			vector2.push_back(3);

			std::vector<int> combinedVector9 = vector1 + vector2;
			{
				for (size_t i = 0; i < combinedVector9.size(); ++i)
				{
					assert(combinedVector9[i] == i + 1);
				}
			}
		}
	}

	void TestConvertVectorToMap()
	{
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		std::vector<char> v2;
		v2.push_back('a');
		v2.push_back('b');
		v2.push_back('c');
		v2.push_back('D');

		std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);	
		{
			assert(m.size() == 3);
			std::map<int, char>::const_iterator it = m.begin();

			assert(it->first == 1);
			assert(it->second == 'a');
			it++;
			assert(it->first == 2);
			assert(it->second == 'b');
			it++;
			assert(it->first == 3);
			assert(it->second == 'c');
		}
	}

	void TestGetKeysAndGetValues()
	{
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		std::vector<char> v2;
		v2.push_back('a');
		v2.push_back('b');
		v2.push_back('c');
		v2.push_back('D');

		std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);	
		{
			assert(m.size() == 3);
			std::map<int, char>::const_iterator it = m.begin();

			assert(it->first == 1);
			assert(it->second == 'a');
			it++;
			assert(it->first == 2);
			assert(it->second == 'b');
			it++;
			assert(it->first == 3);
			assert(it->second == 'c');
		}

		std::vector<int> keys1 = GetKeys(m);
		{
			assert(keys1.size() == 3);
			for (size_t i = 0; i < keys1.size(); ++i)
			{
				assert(keys1[i] == i + 1);
			}

		}

		std::vector<char> values1 = GetValues(m);
		{
			assert(values1.size() == 3);
			assert(values1[0] == 'a');
			assert(values1[1] == 'b');
			assert(values1[2] == 'c');
		}

		std::vector<int> v3;
		v3.reserve(5);
		v3.push_back(1);
		v3.push_back(2);
		v3.push_back(3);
		v3.push_back(4);

		std::string strs[5];
		strs[0] = "Season change and our love went cold";
		strs[1] = "Feed the flame cause we can't let it go";
		strs[2] = "Run away but we running a circles";
		strs[3] = "Run away";
		strs[4] = "Run away";

		std::vector<std::string> v4;
		v4.reserve(4);
		v4.push_back(strs[0]);
		v4.push_back(strs[1]);
		v4.push_back(strs[2]);
		v4.push_back(strs[3]);

		std::map<int, std::string> m2 = lab7::ConvertVectorsToMap(v3, v4);
		{
			assert(m2.size() == 4);
			size_t i = 0;

			for (std::map<int, std::string>::iterator it = m2.begin(); it != m2.end(); ++it)
			{
				assert(it->first == i + 1);
				assert(it->second == strs[i]);
				++i;
			}
		}

		std::vector<int> keys2 = GetKeys(m2);
		{
			assert(keys2.size() == 4);

			for (size_t i = 0; i < keys2.size(); ++i)
			{
				assert(keys2[i] == i + 1);
			}
		}

		std::vector<std::string> values2 = GetValues(m2);
		{
			assert(values2.size() == 4);

			for (size_t i = 0; i < values2.size(); ++i)
			{
				assert(values2[i] == strs[i]);
			}
		}
	}

	void TestReverse()
	{
		std::vector<std::string> v1;
		std::string strs[4];
		strs[0] = "Season change and our love went cold";
		strs[1] = "Feed the flame cause we can't let it go";
		strs[2] = "Run away but we running a circles";
		strs[3] = "Run away";

		v1.push_back(strs[0]);
		v1.push_back(strs[1]);
		v1.push_back(strs[2]);
		v1.push_back(strs[3]);

		std::vector<std::string> rv = Reverse(v1);
		{
			assert(rv.size() == v1.size());
			
			for (size_t i = 0; i < rv.size(); ++i)
			{
				assert(rv[i] == strs[rv.size() - 1 - i]);
			}
		}
	}

	void TestOperator()
	{
		std::vector<int> v1;
		v1.reserve(5);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		std::vector<int> v2;
		v2.reserve(5);
		v2.push_back(4);
		v2.push_back(5);
		v2.push_back(6);

		std::vector<int> combinedVector = v1 + v2;
		{
			assert(combinedVector.size() == 6);
			assert(combinedVector[0] == 1);
			assert(combinedVector[1] == 2);
			assert(combinedVector[2] == 3);
			assert(combinedVector[3] == 4);
			assert(combinedVector[4] == 5);
			assert(combinedVector[5] == 6);
		}

		std::vector<char> v3;
		v3.reserve(5);
		v3.push_back('a');
		v3.push_back('a');
		v3.push_back('b');
		v3.push_back('b');

		std::vector<char> v4;
		v4.reserve(5);
		v4.push_back('c');
		v4.push_back('a');
		v4.push_back('b');
		v4.push_back('d');
		v4.push_back('e');

		std::vector<char> combinedVector2 = v3 + v4;
		{
			assert(combinedVector2.size() == 5);
			assert(combinedVector2[0] == 'a');
			assert(combinedVector2[1] == 'b');
			assert(combinedVector2[2] == 'c');
			assert(combinedVector2[3] == 'd');
			assert(combinedVector2[4] == 'e');
		}

		std::map<char, int> m1;
		m1.insert(std::pair<char, int>('a', 1));
		m1.insert(std::pair<char, int>('b', 2));
		m1.insert(std::pair<char, int>('c', 3));

		std::map<char, int> m2;
		m2.insert(std::pair<char, int>('d', 4));
		m2.insert(std::pair<char, int>('e', 5));
		m2.insert(std::pair<char, int>('f', 6));

		std::map<char, int> combinedMap1 = m1 + m2;
		{
			std::map<char, int>::const_iterator it = combinedMap1.begin();
			assert(it->first == 'a');
			assert(it->second == 1);
			++it;
			assert(it->first == 'b');
			assert(it->second == 2);
			++it;
			assert(it->first == 'c');
			assert(it->second == 3);
			++it;
			assert(it->first == 'd');
			assert(it->second == 4);
			++it;
			assert(it->first == 'e');
			assert(it->second == 5);
			++it;
			assert(it->first == 'f');
			assert(it->second == 6);
		}

		std::map<char, int> m3;
		m3.insert(std::pair<char, int>('a', 1));
		m3.insert(std::pair<char, int>('b', 2));
		m3.insert(std::pair<char, int>('c', 3));
		m3.insert(std::pair<char, int>('c', 3));

		std::map<char, int> m4;
		m4.insert(std::pair<char, int>('a', 4));
		m4.insert(std::pair<char, int>('a', 5));
		m4.insert(std::pair<char, int>('f', 6));

		std::map<char, int> combinedMap2 = m3 + m4;
		{
			assert(combinedMap2.size() == 4);
			std::map<char, int>::const_iterator it = combinedMap2.begin();
			assert(it->first == 'a');
			assert(it->second == 1);
			++it;
			assert(it->first == 'b');
			assert(it->second == 2);
			++it;
			assert(it->first == 'c');
			assert(it->second == 3);
			++it;
			assert(it->first == 'f');
			assert(it->second == 6);
		}
	}

	void TestOutputFormat()
	{
		std::vector<int> v1;
		v1.reserve(32);
		v1.push_back(32);
		v1.push_back(-535);
		v1.push_back(232);
		v1.push_back(81);

		std::cout << v1 << std::endl;

		std::map<char, int> m1;
		m1.insert(std::pair<char, int>('z', 2));
		m1.insert(std::pair<char, int>('a', 1));
		m1.insert(std::pair<char, int>('G', 2));
		m1.insert(std::pair<char, int>('T', 2));
		m1.insert(std::pair<char, int>('V', 2));

		std::cout << m1 << std::endl;
	}
}