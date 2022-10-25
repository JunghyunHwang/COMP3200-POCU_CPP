#pragma once

#include <iostream>

namespace practice
{
    class MyString
    {
        friend std::ostream& operator<<(std::ostream& os, const MyString& rhs);
    public:
        MyString(const char* s);
        MyString(const MyString& other);
        virtual ~MyString();

        MyString& operator=(const MyString& rhs);
        bool operator==(const MyString& rhs) const;
        MyString& operator+=(const MyString& rhs);

    private:
        unsigned int mCapacity;
        unsigned int mCount;
        char* mStr;
    };
}