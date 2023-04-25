#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mSize(0)
		, mCapacity(DEFAULT_CAPACITY)
	{
		const char* pS = s;

		while (*pS++ != '\0')
		{
			++mSize;
		}

		if (mSize > mCapacity)
		{
			mCapacity = mSize * 2;
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
		: mSize(other.mSize)
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
		return mSize;
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

		if (mCapacity < mSize + sLength + 1)
		{
			mCapacity = (mSize + sLength) * 2;

			char* tmp = new char[mCapacity];
			assert(tmp != NULL);

			MyString::strCopy(tmp, mStr);

			delete[] mStr;
			mStr = tmp;
		}

		pS = s;

		for (size_t i = 0; i < sLength; ++i)
		{
			mStr[mSize++] = *pS++;
		}

		mStr[mSize] = '\0';
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
			return mSize;
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

		const char* pS = s;

		while (*pS++ != '\0')
		{
		}

		--pS;
		const unsigned int INPUT_LENGTH = pS - s;

		char* interleaveResult = new char[mSize + INPUT_LENGTH + 1];
		char* pInterleave = interleaveResult;
		const char* pStr = mStr;
		pS = s;

		while (*pStr != '\0' && *pS != '\0')
		{
			*pInterleave++ = *pStr++;
			*pInterleave++ = *pS++;
		}

		while (*pStr != '\0')
		{
			*pInterleave++ = *pStr++;
		}

		while (*pS != '\0')
		{
			*pInterleave++ = *pS++;
		}

		*pInterleave = '\0';

		delete[] mStr;
		mStr = interleaveResult;
		mSize += INPUT_LENGTH;
		interleaveResult = NULL;
	}
	
	bool MyString::RemoveAt(unsigned int i)
	{
		if (i >= mSize)
		{
			return false;
		}

		char* pStr = mStr + i;
		const char* pStrNext = pStr + 1;

		while (*pStrNext != '\0')
		{
			*pStr++ = *pStrNext++;
		}
		*pStr = '\0';

		--mSize;

		return true;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		MyString::PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= mSize)
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

		char* pStr = mStr + mSize;

		for (unsigned int i = 0; i < totalLength - mSize; ++i)
		{
			*pStr++ = c;
		}

		mSize = totalLength;
		mStr[mSize] = '\0';

		assert(totalLength == mSize);
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		MyString::PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= mSize)
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

		char* tmpOrigin = new char[mSize + 1];
		MyString::strCopy(tmpOrigin, mStr);

		char* pStr = mStr;
		unsigned int i = 0;

		while (i < totalLength - mSize)
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

		mSize = totalLength;
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
		if (rhs.mSize + 1 > mCapacity)
		{
			char* tmp = new char[rhs.mCapacity];
			assert(tmp != NULL);

			delete[] mStr;
			mStr = tmp;
		}

		MyString::strCopy(mStr, rhs.mStr);

		mSize = rhs.mSize;

		return *this;
	}

	void MyString::strCopy(char* dest, const char* origin)
	{
		assert(dest != NULL);
		assert(origin != NULL);

		char* pDest = dest;
		const char* pOrigin = origin;

		while (*pOrigin != '\0')
		{
			*pDest++ = *pOrigin++;
		}

		*pDest = '\0';
	}
}
