#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//The number after the last I will be the largest and second last I second largest number and so on.
//The number after lastmost D will be smallest, and second last D second smallest and so on.

vector<int> Solution::findPerm(const string A, int B) {
    vector <int> ans(B,-1);
    vector <bool> done(B+1,false);
    done[0]=true;
    int i,j,k;
    k=B;
    for(i=A.size()-1;i>=0;i--){
        if(A[i]=='I'){
            ans[i+1]=k;
            done[k]=true;
            k--;
        }
    }
    k=1;
    for(i=A.size()-1;i>=0;i--){
        if(A[i]=='D'){
            ans[i+1]=k;
            done[k]=true;
            k++;
        }
    }
    int num;
    for(i=0;i<done.size();i++){
        if(done[i]==false){
            num=i;
            break;
        }
    }
    for(i=0;i<ans.size();i++){
        if(ans[i]==-1){
            ans[i]=num;
        }
    }
    return ans;
}