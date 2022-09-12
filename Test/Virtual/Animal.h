#pragma once

namespace testvirtual
{
    class Animal
    {
    public:
        Animal(int age);
        virtual ~Animal();
        void Speak();
        int GetAge() const;
    private:
        int mAge;
    };
}