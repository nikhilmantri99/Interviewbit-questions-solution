#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int M=1000000007;

void update_ans(int &ans,int required_len, int current_len, int target){
    int i;
    if(target<0){
        return;
    }
    else if(current_len==required_len){
        if(target==0){
            ans++;
            ans=ans%M;
        }
        return;
    }
    else if(current_len==0){
        for(i=1;i<=9;i++){
            update_ans(ans,required_len,current_len+1,target-i);
        }
    }
    else{
        for(i=0;i<=9;i++){
            update_ans(ans,required_len,current_len+1,target-i);
        }
    }
}

int Solution::solve(int A, int B) {
    //A->num of digits
    //B->required sum
    if(A==0){
        if(B==0){
            return 1;
        }
        return 0;
    }
    if(B==0){
        if(A==1){
            return 1;
        }
        return 0;
    }
    int ans=0;
    update_ans(ans,A,0,B);
    ans=ans%M;
    return ans;
}
