#include <iomanip>
#include <fstream>
#include <string>

#include "Lab2.h"

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;

	string happyPathfileName = "HappyPath.txt";
	string fileName1 = "inputInt1.txt";
	string fileName2 = "inputInt2.txt";
	string fileName3 = "inputInt3.txt";
	string fileName4 = "inputInt4.txt";

	fin.open(fileName4);
	fout.open("Result_" + fileName4);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();

    string fileName5 = "inputFloat1.txt";
	string fileName6 = "inputFloat2.txt";
	string fileName7 = "inputFloat3.txt";
	string fileName8 = "inputFloat4.txt";

    fin.open(fileName5);
    fout.open("Result_" + fileName5);
    {
        lab2::PrintMaxFloat(fin, fout);
    }
    fin.close();
	fout.close();

    cout << "No prob";

	return 0;
}