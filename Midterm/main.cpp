// main.cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char ch = 'A';
	unsigned int mask = 0x20;

	cout << showbase << hex << internal << setfill('-') << setw(10) << static_cast<int>(ch) << endl;
	cout << static_cast<char>(ch ^ mask) << endl;
	return 0;
}