#include <bits/stdc++.h>
#include <iostream>
using namespace std;


bool soln(string &A,int a,string &B,int b,string &C,int c){
    if(c>=C.size()){
        return true;
    }
    else if(a>=A.size() && b<B.size()){
        if(B[b]==C[c]){
            return soln(A,a,B,b+1,C,c+1);
        }
        else{
            return false;
        }
    }
    else if(b>=B.size() && a<A.size()){
        if(A[a]==C[c]){
            return soln(A,a+1,B,b,C,c+1);
        }
        else{
            return false;
        }
    }
    else{
        bool truth1=false,truth2=false;
        if(A[a]==C[c]){
            truth1=soln(A,a+1,B,b,C,c+1);
        }
        if(B[b]==C[c]){
            truth2=soln(A,a,B,b+1,C,c+1);
        }
        return (truth1 || truth2);
    }
}

int isInterleave(string A, string B, string C) {
    bool truth=soln(A,0,B,0,C,0);
    if(truth==true){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    
}