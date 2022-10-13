#include <iostream>
#include "karatsuba/karatsuba.h"
#include "strassen/strassen.h"
#include "lcs/lcs.h"
#include <vector>

using namespace std;
using namespace kara;
using namespace stra;
using namespace lcs;

int main()
{

    int choice;

    cout << "_________________________________choose : 1. Karatsuba algorithm\t 2. Strassen algorithm\t 3. Lcs algorithm\t 4. sac à dos algorithm_____________________________ \nMake your choice : ";
    cin >> choice;

    if (choice == 1)
    {
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
    }
    else if (choice == 2)
    {
        int n;

        cout << "enter the size of the matrix: ";
        cin >> n;

        vector<int> cols(n);
        vector<vector<int>> A(n, cols), B(n, cols), C(n, cols);

        createMatrix(A, n);
        createMatrix(B, n);

        strassen(A, B, C, n);

        printMatrix(A, n, 'A');
        printMatrix(B, n, 'B');
        printMatrix(C, n, 'C');
    }
    else if (choice == 3)
    {
        int n, m;
        cout << "Enter the size of the first string: ";
        cin >> m;
        cout << "Enter the size of the second string: ";
        cin >> n;
        vector<char> X(m), Y(n);
        vector<string> LCS;

        createString(X, m);
        createString(Y, n);

        algoLcs(X, Y, LCS, 10, 7);

        printString(X, m, 'X');
        printString(Y, n, 'Y');
        printLCS(LCS, X, m);
    }
    else if(choice == 4){
        cout << "Algorithme du sac à dos pas encore intégré !" << endl;
    }
    else
    {
        cout << "Function not found !" << endl;
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