#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int coinchange2(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    if(A.size()==0){
        return 0;
    }
    if(A[0]>B){
        return 0;
    }
    int M=1000007;
    vector <int> ans(B+1,0);
    int i,j,k;
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin
    ans[0]=1;
    for(i=0;i<A.size();i++){
        for(j=A[i];j<=B;j++){
            ans[j]=((ans[j])%M+(ans[j-A[i]])%M)%M;
        }
    }
    return ans[B]%M;
}