#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int strStr(const string A, const string B) {
    if(A.size()<B.size()){
    	return -1;
    }
    int i,j,k;
    for(i=0;i<=A.size()-B.size();i++){
        int count=0;
        for(j=0;j<B.size();j++){
    		if(A[i+j]!=B[j]){
    			break;
    		}
    		else{
    			count++;
    		}        
        }
        if(count==B.size()){
        	return i;
        }
    }
    return -1;
}

int main(){
	string A;
	string B;
	cin>>A>>B;
	cout<<strStr(A,B)<<endl;
	return 0;
}
