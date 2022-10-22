#pragma once
#include <iostream>

class Person
{
    friend void SwapAge(Person& p1, Person& p2); // 정답
public:
    Person(unsigned int age);
    virtual ~Person();
    unsigned int GetAge() const;
    
private:
    unsigned int mAge;
};

