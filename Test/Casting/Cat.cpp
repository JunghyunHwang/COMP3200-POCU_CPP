#include "Cat.h"

namespace test
{
    Cat::Cat(unsigned int age, const char* name)
        : Animal(age)
    {
        const char* pName = name;

        while (*pName++ != '\0')
        {
        }

        --pName;

        const unsigned int NAME_LENGTH = pName - name;

        mName = new char[NAME_LENGTH + 1];
        memcpy(mName, name, NAME_LENGTH);
        mName[NAME_LENGTH] = '\0';
    }

    Cat::Cat(const Cat& other)
        : Animal(other)
    {
        char* pEnd = other.mName;

        while (*pEnd++ != '\0')
        {
        }

        --pEnd;

        const unsigned int NAME_LENGTH = pEnd - other.mName;
        mName = new char[NAME_LENGTH + 1];
        memcpy(mName, other.mName, NAME_LENGTH + 1);
    }

    Cat::~Cat()
    {
        delete[] mName;
    }

    Cat& Cat::operator=(const Cat& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        Animal::operator=(rhs);

        delete[] mName;

        char* pEnd = rhs.mName;

        while (*pEnd++ != '\0')
        {
        }

        --pEnd;

        const unsigned int NAME_LENGTH = pEnd - rhs.mName;
        mName = new char[NAME_LENGTH + 1];
        memcpy(mName, rhs.mName, NAME_LENGTH + 1);
    }

    void Cat::Speak() const
    {
        std::cout << "I'm cat my name " << mName << std::endl;
    }
}