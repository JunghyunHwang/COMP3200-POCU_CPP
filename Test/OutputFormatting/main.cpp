#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int integer1 = 10;
    int integer2 = 15189;

    float price = 1.24f;

    cout << fixed << right;

    cout << setw(9) << integer1 << endl;
    cout << setw(9) << integer2 << endl;
    cout << setw(9) << price << endl;

    return 0;
}