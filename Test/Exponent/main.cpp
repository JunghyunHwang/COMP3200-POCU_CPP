#include <iostream>
#include "Exponent.h"

using namespace middlemath;

int main()
{
    Exponent num1(2);
    Exponent num2(2, 3.f);

    Exponent result = num1 * num2; // 밑은 무조건 같아야 함

    cout << result.Calculate() << endl; // 밑과 지수의 계산값 출력

    cout << result << endl;
    // base: ??, exponent: ??, result: ??  출력


    num1 = Exponent(3, 2.f);
    num2 = Exponent(3, 4.f);

    result = num1 / num2; // 마찬가지로 밑은 같다고 가정
    cout << result << endl;


    result = 3 * num1;
    cout << result << endl;
    
    result = 3 / num1;
    cout << result << endl;

    num1 = Exponent(5, 2.f);
    num2 = Exponent(5, 4.f);

    cout << (num1 == num2) << endl;

    num1 = num1 ^ 2;

    cout << (num1 == num2) << endl;

    return 0;
}