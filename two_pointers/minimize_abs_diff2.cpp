#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int max3(int a,int b, int c){
    return max(max(a,b),c);
}

int min3(int a,int b, int c){
    return min(min(a,b),c);
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i,j,k,ans;
    i=0;j=0;k=0,ans=INT_MAX;
    while(i<A.size() && j<B.size() && k<C.size()){
        int Max=max3(A[i],B[j],C[k]);
        int Min=min3(A[i],B[j],C[k]);
        ans=min(ans,abs(Max-Min));
        if(Min==A[i]){
            i++;
        }
        else if(Min==B[j]){
            j++;
        }
        else if(Min==C[k]){
            k++;
        }
    }
    return ans;
}