#ifndef KARATSUBA_H
#define KARATSUBA_H
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>

namespace kara
{

    using namespace std;

    vector<long> decomposeNumber(long a)
    {
        vector<long> table;
        

        long quotient = a;
        long powerOfTen = 0;

        while (quotient >= 10)
        {
            powerOfTen = powerOfTen + 1;
            quotient = quotient / 10;
        }

        long coef = a / (long)pow(10, powerOfTen);
        long rest = a % (long)pow(10, powerOfTen);

        table.push_back(powerOfTen);
        table.push_back(coef);
        table.push_back(rest);

        return table;
    }

    long karatsuba(long a, long b)
    {
        vector<int> table{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -2, -3, -4, -5, -6, -7, -8, -9};
        bool existA = find(begin(table), end(table), a) != end(table);
        bool existB = find(begin(table), end(table), b) != end(table);

        if (existA && existB)
        {
            return a * b;
        }

        vector<long> dcpA = decomposeNumber(a);
        vector<long> dcpB = decomposeNumber(b);

        long a0 = karatsuba(dcpA[1], dcpB[1]);
        long a1 = karatsuba(dcpA[1] - dcpA[2], dcpB[1] - dcpB[2]);
        long a2 = karatsuba(dcpA[2], dcpB[2]);
        long k = dcpA[0];


        return (a0*pow(10,2*k)) + ((a0+a2)-a1)*pow(10,k) + (a2);
    }
}

#endif