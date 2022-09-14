#include <iomanip>
#include <string>
#include <limits.h>

#include "Lab2.h"

#define OCT_WIDTH 12
#define DEC_WIDTH 11
#define HEX_WIDTH 9

using namespace std;

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        std::string trash;
        int inputNumber;

        // Print header
        out << setw(OCT_WIDTH) << "oct"
            << setw(DEC_WIDTH) << "dec"
            << setw(HEX_WIDTH) << "hex" << endl;

        out << setfill('-') << setw(OCT_WIDTH) << ""
            << " " << setfill('-') << setw(DEC_WIDTH - 1) << ""
            << " " << setfill('-') << setw(HEX_WIDTH - 1) << "" << endl;

        out << setfill(' ');

        while (!in.eof())
        {
            in >> inputNumber;

            if (in.fail())
            {
                in.clear();
                in >> trash;
            }
            else
            {
                out << setw(OCT_WIDTH) << oct << inputNumber
                    << setw(DEC_WIDTH) << dec << inputNumber
                    << setw(HEX_WIDTH) << uppercase << hex << inputNumber << endl;
            }
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        string trash;
        float inputNumber;
        const int MAX_NUMBER = INT_MIN;
        float maxNumber = MAX_NUMBER;

        while (!in.eof())
        {
            in >> inputNumber;

            if (in.fail())
            {
                in.clear();
                in >> trash;
            }
            else
            {
                out << setw(5) << " " << setw(15) << showpos << internal;

                out << fixed;
                out.precision(3);
                out << inputNumber << endl;

                maxNumber = maxNumber < inputNumber ? inputNumber : maxNumber;
            }
        }

        out << setw(5) << left << "max: " << setw(15) << showpos << internal << maxNumber << endl;
    }
}
