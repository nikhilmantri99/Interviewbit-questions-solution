#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void combine(vector <int> &A,vector <int> &result){
	A.clear();
	for(int i=0;i<result.size();i++){
		A.push_back(result[i]);
	}
}

void merge(vector <int> &A, vector<int> &B) {
    int m=A.size();
    int n=B.size();
    vector <int> result;
    int i,j,k;
    i=0;
    j=0;
    while(i<m && j<n){
    	if(A[i]<=B[j]){
    		result.push_back(A[i]);
    		i++;
    	}
    	else{
    		result.push_back(B[j]);
    		j++;
    	}
    	print_vector(result);
    }
    if(i==m){
    	while(j<n){
    		result.push_back(B[j]);
    		j++;
    	}
    }
    if(j==n){
    	while(i<m){
    		result.push_back(A[i]);
    		i++;
    	}
    }
    combine(A,result);
    print_vector(result);
    print_vector(A);
    return;
}

int main(){
	vector <int> A={3};
	vector <int> B={-4,-3};
	merge(A,B);
	return 0;
}