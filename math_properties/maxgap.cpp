#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void print_vector(vector <int> &x){
    cout<<"vector:";
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
    return;
}

int maximumGap(vector<int> &A) {
    if(A.size()<2){
        return 0;
    }
    int minval=INT_MAX,maxval=INT_MIN;
    int i,j,k,n=A.size();
    for(i=0;i<n;i++){
        minval=min(A[i],minval);
        maxval=max(A[i],maxval);
    }
    cout<<"minval:"<<minval<<endl;
    cout<<"maxval:"<<maxval<<endl;
    vector <int> vec(maxval-minval+1,0);
    for(i=0;i<n;i++){
        vec[A[i]-minval]++;
    }
    print_vector(vec);
    int diff=0;
    i=0;
    while(i<vec.size()){
        j=i+1;
        while(j<vec.size() && vec[j]==0){
            j++;
        }
        diff=max(j-i,diff);
        i=j;
    }
    cout<<diff<<endl;
    return diff;
}

int main(){
    vector<int>A;
    A.push_back(7);
    A.push_back(4);
    A.push_back(8);
    A.push_back(2);
    A.push_back(20);
    maximumGap(A);
    return 0;

}