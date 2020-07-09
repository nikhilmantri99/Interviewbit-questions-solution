#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//traverse the array from behind. while the array increases, keep moving forward, as soon as 
//a value drops, exchange this value with a number in the already traverse array which is just
//greater than this value, Then sort this part of the array from the current index+1.

vector<int> nextPermutation(vector<int> &A) {
    int i,j,k;
    i=A.size()-2;
    while(i>=0){
        if(A[i]>=A[i+1]){
            i--;
        }
        else{
            break;
        }
    }
    //cout<<"i:"<<i<<endl;
    if(i==-1){
        sort(A.begin(),A.end());
        return A;
    }
    else{
        j=A.size()-1;
        while(A[i]>=A[j]){
            j--;
        }
        //cout<<"j:"<<j<<endl;
        int temp=A[j];
        A[j]=A[i];
        A[i]=temp;
        sort(A.begin()+i+1,A.end());
    }
    return A;
}
