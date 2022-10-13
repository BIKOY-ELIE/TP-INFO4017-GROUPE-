#ifndef LCS_H
#define LCS_H
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>


namespace lcs {
    using namespace std;

    void printLCS(vector< string > LCS, vector< char > X, int m){
        if (m == 0){
            return;
        }
        cout << "___________________________________________Affichage d'une sous-chaine_______________________________________ " << endl;
        for (int i = 0; i < m; i++)
        {
            if(LCS.at(i) == "equal") {
                cout << X[i] << " " ;
            }
        }
        cout << endl;
    }

    void printString(vector< char > X, int m, char name){
        cout << "Affichage de la chaine " << name << ": ";
        for (int i = m; i > 0; i--)
        {
            cout << X[i] << " ";
        }
        cout << endl;
    }

    void createString(vector<char> &S, int n){
        char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

        for (int i = 0; i < n; i++)
        {
            int index = (rand() % (25));
            S[i] = alphabet[index];
        }
    }

    int algoLcs(vector< char > X, vector< char > Y, vector<string> &LCS, int m, int n) {
        vector<int> col (n+1);
        vector< vector<int> > C (m+1, col);

        for (int i = 0; i <= m; i++)
        {
            C[i][0] = 0;
        }
        for (int j = 0; j <= n; j++)
        {
            C[0][j] = 0;
        }
        

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (X.at(i) == Y.at(j))
                {
                    C[i+1][j+1] = C[i][j] + 1;
                    LCS.insert(LCS.begin() + i, "equal");
                } else {
                    C[i+1][j+1] = max(C[i+1][j], C[i][j+1]);
                    LCS.insert(LCS.begin() + i, "diff");
                }
                
            }
            
        }
        return C[m][n];
    }

}


#endif