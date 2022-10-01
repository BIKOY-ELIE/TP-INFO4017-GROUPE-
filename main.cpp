#include <iostream>
#include "karatsuba/karatsuba.h"
#include "strassen/strassen.h"
#include <vector>

using namespace std;
using namespace kara;
using namespace stra;

int main()
{

    int choice;

    cout << "_________________________________choose : 1. Karatsuba algorithm\t 2. Strassen algorithm_____________________________ \nMake your choice : ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            long a, b, c;

            cout << "Entrer un premier nombre : ";
            cin >> a;
            cout << "Entrer un second nombre : ";
            cin >> b;
            c = karatsuba(a, b);
            cout << endl;
            if (c == -1)
            {
                cout << "impossible d'effectuer cette opération !" << endl;
            }
            else
            {
                cout << a << " multiplier par " << b << " avec l'algorithme de karatsuba donne : " << c << endl;
            }
            break;
        case 2:
            int n;

            cout << "enter the size of the matrix: ";
            cin >> n;

            vector<int> cols(n);
            vector< vector<int> > A(n, cols), B(n, cols), C(n, cols);

            createMatrix(A, n);
            createMatrix(B, n);

            strassen(A, B, C, n);

            printMatrix(A, n, 'A');
            printMatrix(B, n, 'B');
            printMatrix(C, n, 'C');

            break;
    }

    // vector< vector<int> > M = {
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12},
    //     {14,15,16,17}
    // };

    // cout << M[1].size() << endl;

    return 0;
}