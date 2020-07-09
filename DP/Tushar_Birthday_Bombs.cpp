#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> Solution::solve(int A, vector<int> &B) {
    Algorithm:

    // Find the max no. of kicks (length of our answer).
    // Make a new S vector which only takes the friends that can be in the answer.
    // Iterate through the S vector formed above and see if the friend at consideration can be used instead of the friend with minimum strength.
    // If he can be successfully used then use him instead of the friend with minimum strength to get a lexicographically smaller answer.
    int i,j,k;
    vector <int> ans;
    int minval=INT_MAX,minIndex;
    for(i=0;i<B.size();i++){
        if(B[i]<minval){
            minval=B[i];
            minIndex=i;
        }
    }
    int maxL=A/minval;
    if(maxL==0){
        return ans;
    }
    vector <int> newS;
    int residual=A-(maxL-1)*minval;
    for(i=0;i<minIndex;i++){
        if(newS.size()==0 && B[i]<=residual){
            newS.push_back(i);
            residual=B[i];
        }
        else if(B[i]<residual){
            newS.push_back(i);
            residual=B[i];
        }
    }
    for(i=0;i<maxL;i++){
        ans.push_back(minIndex);
    }
    int currentsum=minval*maxL;
    i=0;//i ans index
    j=0;//newS index
    for(;i<ans.size() && j<newS.size();){
        if(currentsum-B[ans[i]]+B[newS[j]]>A){
            j++;
        }
        else if(currentsum-B[ans[i]]+B[newS[j]]<=A){
            currentsum=currentsum-B[ans[i]]+B[newS[j]];
            ans[i]=newS[j];
            i++;
        }
    }
    return ans;
}