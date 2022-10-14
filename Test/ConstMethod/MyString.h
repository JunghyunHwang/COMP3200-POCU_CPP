#pragma once
#include <cassert>

namespace test
{
    class MyString
    {
    public:
        MyString(const char* str);
        MyString(const MyString& other);
        virtual ~MyString();
        MyString& operator=(const MyString& rhs);

        inline unsigned int GetCapacity() const;
        inline unsigned int GetSize() const;
        char* GetCString() const;
        void SetCapacity(int capacity);

    private:
        char* mStr;
        unsigned int mCapacity;
        unsigned int mSize;
    };

    unsigned int MyString::GetCapacity() const
    {
        return mCapacity;
    }

    unsigned int MyString::GetSize() const
    {
        return mSize;
    }
}