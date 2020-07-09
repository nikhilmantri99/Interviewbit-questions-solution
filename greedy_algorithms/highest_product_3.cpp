#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vec(vector <int> &A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int Solution::maxp3(vector<int> &A) {
    sort(A.begin(),A.end());
    //print_vec(A);
    int maxval=INT_MIN;
    int i,j;
    maxval=max(maxval,A[0]*A[1]*A[A.size()-1]);
    maxval=max(maxval,A[A.size()-1]*A[A.size()-2]*A[A.size()-3]);
    return maxval;
}
