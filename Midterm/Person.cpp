#include "Person.h"

Person::Person(unsigned int age)
    : mAge(age)
{
}

Person::~Person()
{
}

unsigned int Person::GetAge() const
{
    return mAge;
}