#include <cstdio>
#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mCount(0)
		, mCapacity(DEFAULT_CAPACITY)
	{
		const char* pS = s;

		while (*pS++ != '\0')
		{
			++mCount;
		}

		if (mCount > mCapacity)
		{
			mCapacity = mCount * 2;
		}

		mStr = new char[mCapacity];

		pS = s;
		char* pStr = mStr;

		while (*pS != '\0')
		{
			*pStr++ = *pS++;
		}

		*pStr = '\0';
	}

	MyString::MyString(const MyString& other)
		: mCount(other.mCount)
		, mCapacity(other.mCapacity)
	{
		mStr = new char[mCapacity];

		const char* pOtherString = other.mStr;
		char* pStr = mStr;

		while (*pOtherString != '\0')
		{
			*pStr++ = *pOtherString++;
		}

		*pStr = '\0';
	}

	MyString::~MyString()
	{
		delete[] mStr;
	}

	unsigned int MyString::GetLength() const
	{
		return mCount;
	}

	const char* MyString::GetCString() const
	{
		return mStr;
	}

	void MyString::Append(const char* s)
	{
		const char* pS = s;
		int sLength = 0;

		while (*pS++ != '\0')
		{
			++sLength;
		}

		if (mCapacity < mCount + sLength + 1)
		{
			mCapacity = (mCount + sLength) * 2;

			char* tmp = new char[mCapacity];
			char* pTmp = tmp;
			const char* pStr = mStr;

			while (*pStr != '\0')
			{
				*pTmp++ = *pStr++;
			}

			delete[] mStr;
			mStr = tmp;
		}

		pS = s;

		for (size_t i = 0; i < sLength; ++i)
		{
			mStr[mCount++] = *pS++;
		}

		mStr[mCount] = '\0';
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		const char* pStr = mStr;
		const char* pRhs = rhs.mStr;

		while (*pStr != '\0' && *pStr == *pRhs)
		{
			++pStr;
			++pRhs;
		}

		if (*pStr != '\0')
		{
			return false;
		}

		return true;
	}
}