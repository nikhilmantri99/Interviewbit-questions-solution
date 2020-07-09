#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int max_time=INT_MIN;
    for(int i=0;i<A.size();i++){
        max_time=max(abs(A[i]-B[i]),max_time);
    }
    return max_time;
}