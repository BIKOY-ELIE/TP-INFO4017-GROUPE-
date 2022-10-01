#include <iostream>
#include "karatsuba/karatsuba.h"
#include "strassen/strassen.h"

using namespace std;
using namespace kara;

int main()
{

    long a;
    long b;

    cout << "Entrer un premier nombre : ";
    cin >> a;
    cout << "Entrer un second nombre : ";
    cin >> b;
    long c = karatsuba(a, b);
    cout << endl;
    if (c == -1)
    {
        cout << "impossible d'effectuer cette opération !" << endl;
    }
    else
    {
        cout << a << " multiplier par " << b << " avec l'algorithme de karatsuba donne : " << c << endl;
    }
    cout << endl;

    // vector< vector<int> > M = {
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12},
    //     {14,15,16,17}
    // };

    // cout << M[1].size() << endl;

    return 0;
}