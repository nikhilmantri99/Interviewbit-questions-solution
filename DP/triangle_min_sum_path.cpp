#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// O(1) solution that you came up by yourself Nikhil. Good Job boy

int minimumTotal(vector<vector<int> > &A) {
    int i,j;
    for(i=1;i<A.size();i++){
        for(j=0;j<A[i].size();j++){
            if(j==0){
                A[i][j]=A[i-1][j]+A[i][j];
            }
            else if(j==A[i].size()-1){
                A[i][j]=A[i-1][j-1]+A[i][j];
            }
            else{
                A[i][j]=min(A[i-1][j-1],A[i-1][j])+A[i][j];
            }
        }
    }
    i=A.size()-1;
    int minval=INT_MAX;
    for(j=0;j<A[i].size();j++){
        minval=min(minval,A[i][j]);
    }
    return minval;
}

