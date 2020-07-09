#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int climbStairs(int A) {
    if(A==0){
        return 0;
    }
    if(A==1){
        return 1;
    }
    if(A==2){
        return 2;
    }
    vector <int> x(A+1,0);
    x[0]=0;
    x[1]=1;
    x[2]=2;
    for(int i=3;i<=A;i++){
        x[i]=x[i-1]+x[i-2];
    }
    return x[A];
}