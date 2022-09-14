#include <iomanip>
#include <fstream>
#include <string>

#include "Lab2.h"

using namespace std;

void testPrintIntegers();
void testPrintMaxFloat();

int main()
{
    // testPrintIntegers();
    // testPrintMaxFloat();
    float testNumber;
    cin >> testNumber;

    cout << "No prob";

	return 0;
}

void testPrintIntegers()
{
    ifstream fin;
	ofstream fout;

    string empty = "Empty.txt";
	string IntTest1 = "inputInt1.txt";
	string IntTest2 = "inputInt2.txt";
	string IntTest3 = "inputInt3.txt";
	string IntTest4 = "inputInt4.txt";
	string IntTest5 = "inputInt5.txt";

	fin.open(IntTest5);
	fout.open("Result_" + IntTest5);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();

    fin.open(empty);
	fout.open("Result_" + empty);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();
}

void testPrintMaxFloat()
{
    ifstream fin;
	ofstream fout;

    string floatTest1 = "inputFloat1.txt";
    fin.open(floatTest1);
    fout.open("Result_" + floatTest1);
    {
        lab2::PrintMaxFloat(fin, fout);
    }
    fin.close();
	fout.close();

    string floatTest2 = "inputFloat2.txt";
    fin.open(floatTest2);
    fout.open("Result_" + floatTest2);
    {
        lab2::PrintMaxFloat(fin, fout);
    }
    fin.close();
	fout.close();

    string empty = "Empty.txt";
    fin.open(empty);
	fout.open("Result_" + empty);
	{
		lab2::PrintMaxFloat(fin, fout);
	}
	fin.close();
	fout.close();
}