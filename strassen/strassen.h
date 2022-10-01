#ifndef STRASSEN_H
#define STRASSEN_H
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

namespace stra {

    using namespace std;
    
    void  divideMatrix(
        vector< vector<int> > &A,
        vector< vector<int> > &a,
        vector< vector<int> > &b,
        vector< vector<int> > &c,
        vector< vector<int> > &d,
        int n
    ){
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                a[i][j] = A[i][j];
                b[i][j] = A[i][j + n];
                c[i][j] = A[i + n][j];
                d[i][j] = A[i + n][j + n];
            }
        }
    }

    void subtractOrSum(
        vector< vector<int> > &a,
        vector< vector<int> > &b,
        vector< vector<int> > &c,
        char sign,
        int n
    ){
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                if (strcomp(sign, "-") == 0){
                    c[i][j] = a[i][j] - b[i][j];
                }
                else if (strcomp(sign, "+") == 0){
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
        }
    }

    void strassen(
        vector< vector<int> > &A,
        vector< vector<int> > &B,
        vector< vector<int> > &C,
        int n
    ){
        int nHalf = n/2;
        vector<int> cols(nHalf);
        vector< vector<int> > a(nHalf, cols), b(nHalf, cols), c(nHalf, cols), d(nHalf, cols),
                              e(nHalf, cols), f(nHalf, cols), g(nHalf, cols), h(nHalf, cols),
                              r(nHalf, cols), s(nHalf, cols), t(nHalf, cols), u(nHalf, cols),
                              p1(nHalf, cols), p2(nHalf, cols), p3(nHalf, cols), p4(nHalf, cols), p5(nHalf, cols), p6(nHalf, cols), p7(nHalf, cols),
                              FminusH(nHalf, cols), AplusB(nHalf, cols), GminusE(nHalf, cols), CplusD(nHalf, cols), AplusD(nHalf, cols), EminusH(nHalf, cols), BminusD(nHalf, cols), GplusH(nHalf, cols), EplusF(nHalf, cols), AminusC(nHalf, cols),
                              P5plusP4(nHalf, cols), P6minusP2(nHalf, cols), P5minusP3(nHalf, cols), P1minusP7(nHalf, cols);


        if (A.size() == 1 && A[0].size() == 1 && B.size() == 1 && A[0].size() == 1){
            C[0][0] = A[0][0] * B[0][0];
        }

        divideMatrix(a, b, c, d, A, n-1);
        divideMatrix(e, f, g, h, B, n-1);

        //determine p1
        subtractOrSum(f, h, FminusH, "-", nHalf);
        strassen(a, FminusH, p1, nHalf);

        //determine p2
        subtractOrSum(a, b, AplusB, "+", nHalf);
        strassen(AplusB, h, p2, nHalf);

        //determine p3
        subtractOrSum(c, d, CplusD, "+", nHalf);
        strassen(CplusD, e, p3, nHalf);

        //determine p4
        subtractOrSum(g, e, GminusE, "-", nHalf);
        strassen(d, GminusE, p4, nHalf);

        //determine p5
        subtractOrSum(a, d, AplusD, "+", nHalf);
        subtractOrSum(e, h, EplusH, "+", nHalf);
        strassen(AplusD, EplusH, p4, nHalf);

        //determine p6
        subtractOrSum(b, d, BminusD, "-", nHalf);
        subtractOrSum(g, h, GplusH, "+", nHalf);
        strassen(BminusD, GplusH, p6, nHalf);

        //determine p7
        subtractOrSum(a, c, AminusC, "-", nHalf);
        subtractOrSum(e, f, EplusF, "+", nHalf);
        strassen(AminusC, EplusF, p1, nHalf);


        // calculate r
        subtractOrSum(p6, p2, P6minusP2, "-", nHalf);
        subtractOrSum(p5, p4, P5plusP4, "+", nHalf);
        subtractOrSum(P6minusP2, P5plusP4, r, "+", nHalf);

        // calculate u
        subtractOrSum(p5, p3, P5minusP3, "-", nHalf);
        subtractOrSum(p1, p7, P1minusP7, "-", nHalf);
        subtractOrSum(P5minusP3, P1minusP7, u, "+", nHalf);

        // caculate s
        subtractOrSum(p1, p2, s, "+", nHalf);

        // calculate t
        subtractOrSum(p3, p4, t, "+", nHalf);
        

        for(int i=0; i < nHalf; i++){
            for(int j=0; j < nHalf; j++){
                C[i][j] = r[i][j];
                C[i][j + nHalf - 1] = s[i][j];
                C[i + nHalf - 1][j] = t[i][j];
                C[i + nHalf - 1][j + nHalf - 1] = u[i][j];
            }
        }


        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                cout << "element d'indice [" << i << "]" << "[" << j << "] : " << C[i][j] << endl;
            }
        }

    }

    void createMatrix(vector< vector<int> > &M){
        int n;
        cout << "enter the order of your matrix : ";
        cin >> n;

        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                M[i][j] = (rand() % 10) + 1;
            }
        }
    }

}




#endif