#include <iostream>
#include "karatsuba/karatsuba.h"

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

    return 0;
}