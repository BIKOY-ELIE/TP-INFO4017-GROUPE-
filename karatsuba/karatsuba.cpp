#include "karatsuba.hpp"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

bool findANumberInArray(int A[], int a){
    return find(begin(A), end(A), a) != end(A);
}

long * decomposeNumber(long a) {
    long table[3];


    long quotient = a / 10;
    long powerOfTen = 0;

    while(quotient > 10) {
        powerOfTen += 1;
        long quotient = a / 10;  
    }

    long coef = a / (long)pow(10, powerOfTen);
    long rest = a % (long)(pow(10, powerOfTen));

    table[0] = powerOfTen;
    table[1] = coef;
    table[2] = rest;
    

    return table;
}

long karatsuba(long a, long b)
{
    int table[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool existA = findANumberInArray(table, a);
    bool existB = findANumberInArray(table, a);

    if (existA && existB) {
        return a*b;
    }
    
    long *dcpA = decomposeNumber(a);
    long *dcpB = decomposeNumber(b);

    long a0 = karatsuba(dcpA[1], dcpA[1]);
    long a1 = karatsuba(dcpA[1] - dcpA[2], dcpB[1] - dcpB[2]);
    long a2 = karatsuba(dcpA[2], dcpA[2]);

    return (a0 * pow(10, 2*dcpA[0])) + ((a0 + a2 - a1) * pow(10, dcpA[0])) + (a2 * pow(10, 2*dcpA[0]));
}