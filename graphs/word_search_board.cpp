#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool DFS(vector <string> &A, string &B, int i,int j, int pos){
    //same letter cell maybe used more than once
    //as the problem states so we r not marking visited nodes.
    if(pos>=B.size()){
        return true;
    }
    if(i<0||i>=A.size()||j<0||j>=A[0].size()){
        return false;
    }
    if(A[i][j]!=B[pos]){
        return false;
    }
    bool truth;
    
    truth=DFS(A,B,i-1,j,pos+1);
    if(truth==true) return true;
    
    truth=DFS(A,B,i+1,j,pos+1);
    if(truth==true) return true;
    
    truth=DFS(A,B,i,j-1,pos+1);
    if(truth==true) return true;
    
    truth=DFS(A,B,i,j+1,pos+1);
    if(truth==true) return true;
    
    return false;
    
}

int exist(vector<string> &A, string B) {
    int i,j;
    bool truth;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            truth=DFS(A,B,i,j,0);
            if(truth==true){
                return 1;
            }
        }
    }
    return 0;
}
