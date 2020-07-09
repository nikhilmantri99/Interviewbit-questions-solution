#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int canJump(vector<int> &A) {
    int n=A.size();
    if(A.size()==0 || A.size()==1){
        return 1;
    }
    if(A[0]==0){
        return 0;
    }
    vector <bool> reachable(A.size(),false);
    reachable[0]=true;
    int i,j,k;
    for(i=0;i<A.size();i++){
        if(reachable[i]==false){
            continue;
        }
        for(j=1;j<A[i];j++){
            reachable[i+j]=true;
        }
    }
    //cout<<"here"<<endl;
    if(reachable[n-1]==true){
        //cout<<"here1"<<endl;
        return 1;
    }
    //cout<<"here2"<<endl;
    return 0;
}

int main(){
    vector <int> A={4, 0, 25, 0, 0, 0, 0, 0, 18, 27, 0, 0, 15, 0, 29, 0, 0, 0, 0, 0, 0, 5, 0, 0, 18, 0, 0, 26, 0, 24, 0, 6, 0, 0, 8, 4, 0, 1, 0, 0, 18, 0, 0, 0, 4, 0, 0, 0, 30, 18, 0, 0, 0, 0, 14, 0, 0, 16, 0, 0, 0, 0, 6, 0, 0, 0, 8, 0, 0, 0, 7, 14, 22, 19, 0, 0, 0, 13, 10, 25, 0, 0, 0, 0, 19, 0, 0, 0, 0, 0, 30, 0, 0, 0, 15, 25, 0, 0, 8, 0, 0, 0, 0, 12, 0, 16, 16, 24, 0, 0, 0, 3, 0, 0, 0, 10, 0, 0, 0, 0, 23};
    cout<<canJump(A)<<endl;
    return 0;
}