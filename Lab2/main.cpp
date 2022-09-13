#include <iomanip>
#include <fstream>
#include <string>

#include "lab2.h"

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

	fin.open(fileName1);
	fout.open("Result_" + fileName1);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();

	return 0;
}