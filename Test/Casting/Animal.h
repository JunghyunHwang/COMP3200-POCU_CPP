#pragma once

namespace test
{
    class Animal
    {
    public:
        Animal(unsigned int age);
        virtual ~Animal();

        virtual void Speak() const = 0;
        inline unsigned int GetAge() const;
    private:
        unsigned int mAge;
    };

    unsigned int Animal::GetAge() const
    {
        return mAge;
    }
}

// Cat Animal