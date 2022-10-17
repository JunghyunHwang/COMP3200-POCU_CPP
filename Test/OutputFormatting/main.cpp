#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int integer1 = -127;
    int integer2 = 15189;

    int* p1 = &integer1;
    char* pCh = reinterpret_cast<char*>(p1);

    float decf = 3.14159265358979;
    double decd = 3.14159265358979;

    char ch = 'c';
    string s = "Test";

    cout << right << setw(5) << setprecision(3) << decf << endl
        << decd;

    cout << *pCh << endl;

    return 0;
}