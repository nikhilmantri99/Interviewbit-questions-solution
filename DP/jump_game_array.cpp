#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int canJump(vector<int> &A) {
    vector <bool> canjump(A.size(),false);
    canjump[0]=true;
    for(int i=0;i<canjump.size();i++){
        if(canjump[i]==true){
            for(int j=1;j<=A[i] && i+j<A.size();j++){
                canjump[i+j]=true;
            }
        }
    }
    if(canjump[A.size()-1]==true){
        return 1;
    }
    else{
        return 0;
    }
}