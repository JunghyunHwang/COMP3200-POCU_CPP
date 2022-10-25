#include <iostream>
#include <iomanip>

void output1()
{
    std::cout << std::showpos << std::uppercase << std::showbase << std::setw(10) << std::setprecision(4) << std::hex << std::setfill('?');
    std::cout << 3.141592 << std::endl << std::setw(15) << 16;
    std::cout << std::setw(5) << std::setfill('-') << ' ';
}


int main()
{
    output1();
}