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

int maxSpecialProduct(vector<int> &A) {
   stack<int>left;//stores element in decreasing order
   stack<int>right;
   int i,n=A.size();
   int *lsv=(int *)malloc(n*sizeof(int));
   int *rsv=(int *)malloc(n*sizeof(int));
   for(i=0;i<n;i++){
        cout<<"cehck "<<A[i]<<" pop: ";
        while(left.empty()==false){
            if(left.top()<=A[i]){
              cout<<left.top()<<" ";
              left.pop();
            }
            else break;
        }
        cout<<"found lsv :"<<" ";
        if(left.empty()==true){
            
            lsv[i]=0;
            cout<<lsv[i]<<endl;
            left.push(A[i]);
        }
        else{
            lsv[i]=left.top();
            cout<<lsv[i]<<endl;
            left.push(A[i]);
        }
   }
   for(i=n-1;i>=0;i--){
        while(right.empty()==false){
            if(right.top()<=A[i])right.pop();
            else break;
        }
        if(right.empty()==true){
            rsv[i]=0;
            right.push(A[i]);
        }
        else{
            rsv[i]=right.top();
            right.push(A[i]);
        }
   }
   int maxval=INT_MIN;
   for(i=0;i<n;i++){
       maxval=max(maxval,(lsv[i]*rsv[i])%1000000007);
   }
   return maxval;
}

int main(){
  vector <int> A;
  A.push_back(5);
  A.push_back(9);
  A.push_back(6);
  A.push_back(8);
  A.push_back(6);
  A.push_back(4);
  A.push_back(6);
  A.push_back(9);
  A.push_back(5);
  A.push_back(4);
  A.push_back(9);
  cout<<maxSpecialProduct(A)<<endl;
  return 0;
}