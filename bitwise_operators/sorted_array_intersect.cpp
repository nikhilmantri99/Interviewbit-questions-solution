#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Find the intersection of two sorted arrays.
// OR in other words,
// Given 2 sorted arrays, find all the elements which occur in both the arrays.

//The code is a modification of the merge of two sorted arrays
void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

vector <int> intersect(const vector <int> &A,const vector<int> &B){
    int m=A.size();
    int n=B.size();
    vector <int> result;
    int i,j,k;
    i=0;
    j=0;
    while(i<m && j<n){
    	if(A[i]<B[j]){
    		i++;
    	}
    	else if(A[i]==B[j]){
    		result.push_back(A[i]);
    		i++;
    		j++;
    	}
    	else{
    		j++;
    	}
    }
    print_vector(result);
    return result;
}

int main(){
	vector <int> A={1,2,3,3,4,5,6};
	vector <int> B={3,5};
	vector <int> ans=intersect(A,B);
	return 0;
}