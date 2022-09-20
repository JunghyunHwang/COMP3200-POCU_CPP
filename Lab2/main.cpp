#include <iomanip>
#include <fstream>
#include <string>

#include "Lab2.h"

void testPrintIntegers();
void testPrintMaxFloat();

int main()
{
	testPrintIntegers();
	testPrintMaxFloat();

	char name[] = "JaHwang";

	std::cout << name << std::endl;
	std::cout << sizeof(name) << std::endl;

	std::cout << "No prob" << std::endl;

	return 0;
}

void testPrintIntegers()
{
	std::ifstream fin;
	std::ofstream fout;

	std::string empty = "Empty.txt";
	std::string IntTest1 = "inputInt1.txt";
	std::string IntTest2 = "inputInt2.txt";
	std::string IntTest3 = "inputInt3.txt";
	std::string IntTest4 = "inputInt4.txt";
	std::string IntTest5 = "inputInt5.txt";

	fin.open(IntTest1);
	fout.open("Result_" + IntTest1);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(IntTest2);
	fout.open("Result_" + IntTest2);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(IntTest3);
	fout.open("Result_" + IntTest3);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(IntTest4);
	fout.open("Result_" + IntTest4);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(IntTest5);
	fout.open("Result_" + IntTest5);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(empty);
	fout.open("Result_Int" + empty);
	{
		lab2::PrintIntegers(fin, fout);
	}
	fin.close();
	fout.close();
}

void testPrintMaxFloat()
{
	std::ifstream fin;
	std::ofstream fout;

	std::string floatTest1 = "inputFloat1.txt";
	std::string floatTest2 = "inputFloat2.txt";
	std::string floatTest3 = "inputFloat3.txt";
	std::string floatTest4 = "inputFloat4.txt";
	std::string empty = "Empty.txt";

	fin.open(floatTest1);
	fout.open("Result_" + floatTest1);
	{
		lab2::PrintMaxFloat(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(floatTest2);
	fout.open("Result_" + floatTest2);
	{
		lab2::PrintMaxFloat(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(floatTest2);
	fout.open("Result_" + floatTest2);
	{
		lab2::PrintMaxFloat(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(floatTest3);
	fout.open("Result_" + floatTest3);
	{
		lab2::PrintMaxFloat(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(floatTest4);
	fout.open("Result_" + floatTest4);
	{
		lab2::PrintMaxFloat(fin, fout);
	}
	fin.close();
	fout.close();

	fin.open(empty);
	fout.open("Result_Float" + empty);
	{
		lab2::PrintMaxFloat(fin, fout);
	}
	fin.close();
	fout.close();
}