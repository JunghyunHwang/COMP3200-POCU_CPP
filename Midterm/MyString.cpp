#include "MyString.h"

namespace practice
{
    MyString::MyString(const char* s)
        : mCapacity(64)
        , mCount(0)
    {
        const char* pS = s;

        while (*pS++ != '\0')
        {
            ++mCount;
        }

        if (mCount >= mCapacity)
        {
            mCapacity = mCount * 2;
        }

        mStr = new char[mCapacity];
        
        for (size_t i = 0; i < mCount; ++i)
        {
            mStr[i] = s[i];
        }

        mStr[mCount] = '\0';
    }

    MyString::~MyString()
    {
        delete[] mStr;
    }

    MyString::MyString(const MyString& other)
        : mCapacity(other.mCapacity)
        , mCount(other.mCount)
    {
        mStr = new char[mCapacity];

        for (size_t i = 0; i < mCount; ++i)
        {
            mStr[i] = other.mStr[i];
        }

        mStr[mCount] = '\0';
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        delete[] mStr;
        mCapacity = rhs.mCapacity;
        mCount = rhs.mCount;

        mStr = new char[mCapacity];

        for (size_t i = 0; i < mCount; ++i)
        {
            mStr[i] = rhs.mStr[i];
        }
        
        mStr[mCount] = '\0';
    }

    bool MyString::operator==(const MyString& rhs)
    {
        const char* pRhs = rhs;
        const char* pStr = mStr;

        while (*pStr != '\0' && *pStr == pRhs)
        {
            ++pStr;
            ++pRhs;
        }

        if (*pStr == '\0' && pRhs == '\0')
        {
            return true;
        }

        return false;
    }

    MyString& operator+=(const MyString& rhs)
    {
        const unsigned int TOTAL_LENGTH = mCount + rhs.mCount;

        if (TOTAL_LENGTH >= mCapacity)
        {
            mCapacity = TOTAL_LENGTH * 2;
            char* tmp = new char[mCapacity];

            for (size_t i = 0; i < mCount; ++i)
            {
                tmp[i] = mStr[i];
            }

            delete[] mStr;
            mStr = tmp;
        }

        for (size_t i = 0; i < rhs.mCount; ++i)
        {
            mStr[mCount++] = rhs.mStr[i];
        }

        mStr[mCount] = '\0';
    }

    std::ostream& operator<<(std::ostream& os, const MyString& rhs)
    {
        os << rhs.mStr;
        return os;
    }
}