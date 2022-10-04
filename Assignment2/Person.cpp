#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mName(name)
		, mWeight(weight)
	{
	}

	Person::~Person()
	{
	}

	bool Person::operator==(const Person& rhs) const
	{
		return (mWeight == rhs.mWeight && mName == rhs.mName);
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}