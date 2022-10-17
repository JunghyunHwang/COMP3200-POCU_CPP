#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int integer1 = 10;
    int integer2 = 15189;

    int* p1 = &integer1;
    char* pCh = reinterpret_cast<char*>(p1);

    float decf = 3.1415f;
    double decd = 3.141592;

    char ch = 'c';
    string s = "Test";

    cout << (int)*pCh++ << endl;
    cout << (int)*pCh++ << endl;
    cout << (int)*pCh++ << endl;
    cout << (int)*pCh++ << endl;

    return 0;
}