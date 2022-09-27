#include <iostream>
#include "karatsuba/karatsuba.hpp"

using namespace std;

int main(){

    long a = 50;
    long b = 37;
    long c = karatsuba(a, b);
    cout << c;

    return 0;
}