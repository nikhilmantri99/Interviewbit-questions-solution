#include <vector>
#include <string>
#include <cassert>
#include <algorithm> 
#include <stack>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int ** generateMatrix(int A, int *len1, int *len2) {
    int n=A,left_top=0,right_top=A-1;
    *len1=n;
    *len2=n;
    int **spiral=(int **)malloc(n*sizeof(int *));
    int i,j,k;
    for(i=0;i<n;i++){
        spiral[i]=(int *)malloc(n*sizeof(int));
    }
    j=1;
    while(j<=n*n){
        for(i=left_top;i<=right_top && j<=n*n;i++){
            spiral[left_top][i]=j;
            cout<<"LOOP 1 :filling index :"<<left_top<<" "<<i<<":"<< j<<endl;
            j++;
        }
        for(i=left_top+1;i<=right_top && j<=n*n;i++){
            spiral[i][right_top]=j;
            cout<<"LOOP 2 :filling index :"<<i<<" "<<right_top<<":"<< j<<endl;
            j++;
        }
        for(i=right_top-1;i>=left_top && j<=n*n;i--){
            spiral[right_top][i]=j;
            cout<<"LOOP 3 :filling index :"<<right_top<<" "<<i<<":"<< j<<endl;
            j++;
        }
        left_top++;
        for(i=right_top-1;i>=left_top && j<=n*n;i--){
            spiral[i][left_top-1]=j;
            cout<<"LOOP 4 :filling index :"<<i<<" "<<left_top-1<<":"<< j<<endl;
            j++;
        }
        right_top--;
    }
    return spiral;
}

int main(){
    int A,l1,l2;
    A=4;
    int **spiral;
    cout<<A<<endl;
    spiral =generateMatrix(A,&l1,&l2);
    int i,j,k;
    for(i=0;i<l1;i++){
        for(j=0;j<l2;j++){
            cout<<spiral[i][j]<<" ";
        }
        cout<<endl;

    }
    return 0;
}