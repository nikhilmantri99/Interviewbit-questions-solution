#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int minDistance(string A, string B) {
    int m=A.size(),n=B.size();
    int arr[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0){
                arr[i][j]=j;
            }
            else if(j==0){
                arr[i][j]=i;    
            }
            else{
                int val;
                if(A[i-1]==B[j-1]){
                    val=arr[i-1][j-1];//match
                }
                else{
                    val=arr[i-1][j-1]+1;//replace
                }
                int temp=min(arr[i-1][j]+1,arr[i][j-1]+1);
                arr[i][j]=min(val,temp);
            }
        }
    }
    return arr[m][n];
}