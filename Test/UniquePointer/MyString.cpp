#include "MyString.h"

namespace test
{
	MyString::MyString(const char* str)
		: mSize(0)
		, mCapacity(CAPACITY)
	{
		const char* pStr = str;

		while (*pStr++ != '\0')
		{
		}

		--pStr;

		const size_t STRING_LENGTH = pStr - str;

		if (mCapacity <= STRING_LENGTH)
		{
			mCapacity = STRING_LENGTH * 2;
		}

		mStr = std::make_unique<char[]>(mCapacity);

		memcpy(mStr.get(), str, STRING_LENGTH);
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
		, mCapacity(other.mCapacity)
		, mStr(std::make_unique<char[]>(mCapacity))
	{
		memcpy(mStr.get(), other.mStr.get(), mSize);
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mSize = rhs.mSize;
		mCapacity = rhs.mCapacity;

		mStr = nullptr;
		mStr = std::make_unique<char[]>(mSize);
		memcpy(mStr.get(), rhs.mStr.get(), mSize);

		return *this;
	}

	size_t MyString::GetLength() const
	{
		return mSize;
	}

	const char* MyString::GetCString() const
	{
		return mStr.get();
	}

	std::ostream& operator<<(std::ostream& os, const MyString& rhs)
	{
		os << rhs.mStr.get();

		return os;
	}
}