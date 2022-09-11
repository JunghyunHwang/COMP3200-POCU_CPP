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
		if (*s == '\0')
		{
			return;
		}

		const char* pS = s;
		size_t sLength = 0;

		while (*pS++ != '\0')
		{
			++sLength;
		}

		if (mCapacity < mCount + sLength + 1)
		{
			mCapacity = (mCount + sLength) * 2;

			char* tmp = new char[mCapacity];
			assert(tmp != nullptr);

			MyString::strCopy(tmp, mStr);

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

	MyString MyString::operator+(const MyString& rhs) const
	{
		MyString result(*this);

		result.Append(rhs.mStr);

		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		if (*s == '\0')
		{
			return 0;
		}

		int result = -1;
		const char* pStr = mStr;

		while (*pStr != '\0')
		{
			const char* pS = s;

			if (*pStr == *pS)
			{
				++pS;
				size_t i = 1;

				while (*pS != '\0' && *pS == *(pStr + i))
				{
					++pS;
					++i;
				}

				if (*pS == '\0')
				{
					result = pStr - mStr;
					break;
				}
			}

			++pStr;
		}
	
		return result;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (*s == '\0')
		{
			return mCount;
		}

		int result = -1;
		const char* pStr = mStr;

		while (*pStr != '\0')
		{
			const char* pS = s;

			if (*pStr == *pS)
			{
				++pS;
				size_t i = 1;

				while (*pS != '\0' && *pS == *(pStr + i))
				{
					++pS;
					++i;
				}

				if (*pS == '\0')
				{
					result = pStr - mStr;
				}
			}

			++pStr;
		}
	
		return result;
	}

	void MyString::Interleave(const char* s)
	{
		if (*s == '\0')
		{
			return;
		}

		char* interleaveResult;
		const char* pS = s;
		size_t sLength = 0;

		while (*pS++ != '\0')
		{
			++sLength;
		}

		const size_t TOTAL_LENGTH = mCount + sLength;

		if (mCapacity < TOTAL_LENGTH + 1)
		{
			mCapacity = TOTAL_LENGTH * 2;
		}

		interleaveResult = new char[mCapacity];

		const char* pStr = mStr;
		pS = s;
		
		for (size_t i = 0; i <= TOTAL_LENGTH; ++i)
		{
			if (i % 2 == 0)
			{
				if (*pStr == '\0')
				{
					interleaveResult[i] = *pS++;
					continue;
				}

				interleaveResult[i] = *pStr++;
				continue;
			}

			if (*pS == '\0')
			{
				interleaveResult[i] = *pStr++;
				continue;
			}

			interleaveResult[i] = *pS++;
		}

		mCount = TOTAL_LENGTH;
		interleaveResult[mCount] = '\0';

		delete[] mStr;
		mStr = interleaveResult;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		if (i >= mCount)
		{
			return false;
		}

		char* pStr = mStr + i;

		while (*pStr != '\0')
		{
			*pStr = *(pStr + 1);
			++pStr;
		}

		--mCount;

		return true;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		MyString::PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= mCount)
		{
			return;
		}

		if (totalLength > mCapacity)
		{
			mCapacity *= 2;

			char* tmp = new char[mCapacity];

			MyString::strCopy(tmp, mStr);

			delete[] mStr;
			mStr = tmp;
		}

		char* pStr = mStr + mCount;

		for (unsigned int i = 0; i < totalLength - mCount; ++i)
		{
			*pStr++ = c;
		}

		mCount = totalLength;
		mStr[mCount] = '\0';

		assert(totalLength == mCount);
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		MyString::PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= mCount)
		{
			return;
		}

		if (totalLength > mCapacity)
		{
			mCapacity *= 2;

			char* tmp = new char[mCapacity];

			MyString::strCopy(tmp, mStr);

			delete[] mStr;
			mStr = tmp;
		}

		char* tmpOrigin = new char[mCount + 1];
		MyString::strCopy(tmpOrigin, mStr);

		char* pStr = mStr;
		unsigned int i = 0;

		while (i < totalLength - mCount)
		{
			*pStr++ = c;
			++i;
		}

		const char* pTmp = tmpOrigin;

		while (*pTmp != '\0')
		{
			*pStr++ = *pTmp++;
		}

		delete[] tmpOrigin;

		*pStr = '\0';

		mCount = totalLength;
	}

	void MyString::ToLower()
	{
		char* pStr = mStr;

		while (*pStr != '\0')
		{
			char c = *pStr;

			if ('A' <= c && c <= 'Z')
			{
				*pStr ^= ALPHA_MASK;
			}

			++pStr;
		}
	}

	void MyString::ToUpper()
	{
		char* pStr = mStr;

		while (*pStr != '\0')
		{
			char c = *pStr;

			if ('a' <= c && c <= 'z')
			{
				c ^= ALPHA_MASK;
				*pStr = c;
			}

			++pStr;
		}
	}

	void MyString::Reverse()
	{
		char* pStrStart = mStr;
		char* pStrEnd = mStr;

		while (*pStrEnd != '\0')
		{
			++pStrEnd;
		}

		--pStrEnd;

		while (pStrStart < pStrEnd)
		{
			char tmp = *pStrStart;
			*pStrStart = *pStrEnd;
			*pStrEnd = tmp;

			++pStrStart;
			--pStrEnd;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		const char* pStr = mStr;
		const char* pRhsStr = rhs.mStr;

		while (*pStr != '\0' && *pStr == *pRhsStr)
		{
			++pStr;
			++pRhsStr;
		}

		if (*pStr == *pRhsStr)
		{
			return true;
		}

		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (rhs.mCount + 1 > mCapacity)
		{
			char* tmp = new char[rhs.mCapacity];
			assert(tmp != nullptr);

			delete[] mStr;
			mStr = tmp;
		}

		MyString::strCopy(mStr, rhs.mStr);

		mCount = rhs.mCount;

		return *this;
	}
}
