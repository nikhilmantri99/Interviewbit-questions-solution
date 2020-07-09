// F(i, j)  represents the maximum value the user can collect from 
//          i'th coin to j'th coin.

//     F(i, j)  = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
//                   Vj + min(F(i+1, j-1), F(i, j-2) )) 
// Base Cases
//     F(i, j)  = Vi           If j == i
//     F(i, j)  = max(Vi, Vj)  If j == i+1

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int maxcoin(vector<int> &A) {
   // Create a table to store solutions of subproblems 
    int n=A.size();
    int table[n][n]; 
  
    // Fill table using above recursive formula. Note  
    // that the table is filled in diagonal fashion (similar 
    // to http://goo.gl/PQqoS), from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
  
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive formula 
            int x=0,y=0,z=0;
            if((i + 2) <= j){
                x=table[i + 2][j];
            }
            if(i+1<=j-1){
                y=table[i+1][j-1];
            }
            if(i<=j-2){
                z=table[i][j - 2];
            }
            
            // int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            // int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            // int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(A[i] + min(x, y), A[j] + min(y, z)); 
        } 
    } 
  
    return table[0][n - 1]; 
    
}
