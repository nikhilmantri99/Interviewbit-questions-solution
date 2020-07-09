#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    //A->friends caps;
    //B->dishes filling capacity
    //C->costs
    //find max_capacity_of_friend // this size DP array will contain answers for all prev arrays
    int maxcap=INT_MIN;
    int i,j,k;
    for(i=0;i<A.size();i++){
        maxcap=max(maxcap,A[i]);
    }
    vector <int> ans(maxcap+1,INT_MAX);
    ans[0]=0;
    for(i=1;i<ans.size();i++){
        for(j=0;j<B.size();j++){
            int prev_index=i-B[j];//previous hunger removing this dish capacity
            int cost=C[j];
            if(prev_index>=0){
                ans[i]=min(ans[i],ans[prev_index]+cost);
            }
        }
    }
    int ultimate=0;
    for(i=0;i<A.size();i++){
        ultimate+=ans[A[i]];
    }
    return ultimate;
}