#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;


vector<int> plusOne(vector<int> &A) {
    cout<<"here"<<endl;
    int i;
    vector <int> x;
    int prev=0,lowerlimit=0;
    i=0;
    if(A.size()==1){
        if (A[i]==0) x.push_back(1);
        return x;
    }
    i=0;
    while(A[i]==0 && i<A.size()){
        lowerlimit++;
        i++;
    }
    cout<<lowerlimit<<endl;
    for(i=A.size()-1;i>=lowerlimit;i--){
        if(i==A.size()-1){
            int temp=A[i]+1;
            if (temp>9){
                x.push_back(0);
                prev=1;
            }
            else{
                x.push_back(temp);
                prev=0;
            }
            continue;
        }
        if(prev==1){
            int temp=A[i]+1;
            if (temp>9){
                x.push_back(0);
                prev=1;
            }
            else{
                x.push_back(temp);
                prev=0;
            }
            continue;
        }
        else{
            prev=0;
            x.push_back(A[i]);
        }
    }
    for(i=0;i<x.size()/2;i++){
        int temp=x[i];
        x[i]=x[x.size()-1-i];
        x[x.size()-1-i]=temp;
    }
    for(i=0;i<x.size();i++){
        cout<<x[i]<<endl;
    }
    return x;
    
}

int main(){
    int n;
    cin>>n;
    vector <int> A;
    int i,temp;;
    for(i=0;i<n;i++){
        cin>>temp;
        A.push_back(temp);
    }
    vector <int> next=plusOne(A);
}