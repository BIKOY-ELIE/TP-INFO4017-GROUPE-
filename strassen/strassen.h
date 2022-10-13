#ifndef STRASSEN_H
#define STRASSEN_H
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

namespace stra
{

    using namespace std;

        void printMatrix(vector<vector<int>> M, int n, char name) {
        cout << endl;
        cout << endl;

        cout << "________________________________________________Print out of Matrix : " << name << "___________________________________________________________" << endl;
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1)
                {
                    cout << M[i][j] << endl;
                }
                else if (j == 0)
                {
                    cout << "\t\t\t\t\t\t\t" << M[i][j] << " ";
                }
                else
                {
                    cout << M[i][j] << " ";
                }
            }
        }

        cout << endl;
        cout << endl;
    }

    void divideMatrix(
        vector<vector<int>> &A,
        vector<vector<int>> &a,
        vector<vector<int>> &b,
        vector<vector<int>> &c,
        vector<vector<int>> &d,
        int n)
    {
        if (2*n >= 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = A[i][j];
                    b[i][j] = A[i][j + n];
                    c[i][j] = A[i + n][j];
                    d[i][j] = A[i + n][j + n];
                }
            }
        }
    }

    void subtractOrSum(
        vector<vector<int>> a,
        vector<vector<int>> b,
        vector<vector<int>> &c,
        char sign,
        int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sign == '-')
                {
                    c[i][j] = a[i][j] - b[i][j];
                }
                else if (sign == '+')
                {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
        }
    }

    void strassen(
        vector<vector<int>> A,
        vector<vector<int>> B,
        vector<vector<int>> &C,
        int n)
    {
        int nHalf = n / 2;
        vector<int> cols(nHalf);
        vector<vector<int>> a(nHalf, cols), b(nHalf, cols), c(nHalf, cols), d(nHalf, cols),
            e(nHalf, cols), f(nHalf, cols), g(nHalf, cols), h(nHalf, cols),
            r(nHalf, cols), s(nHalf, cols), t(nHalf, cols), u(nHalf, cols),
            p1(nHalf, cols), p2(nHalf, cols), p3(nHalf, cols), p4(nHalf, cols), p5(nHalf, cols), p6(nHalf, cols), p7(nHalf, cols),
            FminusH(nHalf, cols), AplusB(nHalf, cols), GminusE(nHalf, cols), CplusD(nHalf, cols), AplusD(nHalf, cols), EplusH(nHalf, cols), BminusD(nHalf, cols), GplusH(nHalf, cols), EplusF(nHalf, cols), AminusC(nHalf, cols),
            P5plusP4(nHalf, cols), P6minusP2(nHalf, cols), P5minusP3(nHalf, cols), P1minusP7(nHalf, cols);

        if (A.size() == 1 && A[0].size() == 1 && B.size() == 1 && A[0].size() == 1)
        {
            C[0][0] = A[0][0] * B[0][0];
        }
        else
        {
            // division of A
            divideMatrix(A, a, b, c, d, nHalf);
            // printMatrix(A, n, 'A');
            // printMatrix(a, nHalf, 'a');
            // printMatrix(b, nHalf, 'b');
            // printMatrix(c, nHalf, 'c');
            // printMatrix(d, nHalf, 'd');

            // // division of B
            divideMatrix(B, e, f, g, h, nHalf);
            // printMatrix(B, n, 'B');
            // printMatrix(e, nHalf, 'e');
            // printMatrix(f, nHalf, 'f');
            // printMatrix(g, nHalf, 'g');
            // printMatrix(h, nHalf, 'h');

            // determine p1
            subtractOrSum(f, h, FminusH, '-', nHalf - 1);
            printMatrix(FminusH, nHalf, 'F');
            strassen(a, FminusH, p1, nHalf);

            // //determine p2
            subtractOrSum(a, b, AplusB, '+', nHalf - 1);
            strassen(AplusB, h, p2, nHalf);

            // //determine p3
            subtractOrSum(c, d, CplusD, '+', nHalf - 1);
            strassen(CplusD, e, p3, nHalf);

            // //determine p4
            subtractOrSum(g, e, GminusE, '-', nHalf - 1);
            strassen(d, GminusE, p4, nHalf);

            // //determine p5
            subtractOrSum(a, d, AplusD, '+', nHalf - 1);
            subtractOrSum(e, h, EplusH, '+', nHalf - 1);
            strassen(AplusD, EplusH, p4, nHalf);

            // //determine p6
            subtractOrSum(b, d, BminusD, '-', nHalf - 1);
            subtractOrSum(g, h, GplusH, '+', nHalf - 1);
            strassen(BminusD, GplusH, p6, nHalf);

            // //determine p7
            subtractOrSum(a, c, AminusC, '-', nHalf - 1);
            subtractOrSum(e, f, EplusF, '+', nHalf - 1);
            strassen(AminusC, EplusF, p1, nHalf);

            // // calculate r
            subtractOrSum(p6, p2, P6minusP2, '-', nHalf - 1);
            subtractOrSum(p5, p4, P5plusP4, '+', nHalf - 1);
            subtractOrSum(P6minusP2, P5plusP4, r, '+', nHalf);

            // // calculate u
            subtractOrSum(p5, p3, P5minusP3, '-', nHalf - 1);
            subtractOrSum(p1, p7, P1minusP7, '-', nHalf - 1);
            subtractOrSum(P5minusP3, P1minusP7, u, '+', nHalf - 1);

            // // caculate s
            subtractOrSum(p1, p2, s, '+', nHalf - 1);

            // // calculate t
            subtractOrSum(p3, p4, t, '+', nHalf - 1);

            for(int i=0; i < nHalf; i++){
                for(int j=0; j < nHalf; j++){
                    C[i][j] = r[i][j];
                    C[i][j + nHalf] = s[i][j];
                    C[i + nHalf][j] = t[i][j];
                    C[i + nHalf][j + nHalf] = u[i][j];
                }
            }
        }
    }

    void createMatrix(vector<vector<int>> &M, int n)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                M[i][j] = (rand() % 10) + 1;
            }
        }
    }

}

#endif