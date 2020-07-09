#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int Solution::majorityElement(const vector<int> &A) {
    int n=A.size();
    int target=n/2+1;
    int i;
    unordered_map<int,int> umap;
    for(i=0;i<A.size();i++){
        if(umap.find(A[i])==umap.end()){
            umap[A[i]]=1;
            if(umap[A[i]]>=target){
                return A[i];
            }
        }
        else{
            umap[A[i]]++;
            if(umap[A[i]]>=target){
                return A[i];
            }
        }
    }
    return -1;
}