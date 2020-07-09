#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int removeElement(vector<int> &A, int B){
	int i,j,k;
	i=0;
	while(A[i]!=B && i<A.size()){
		i++;
	}
	if(i==A.size()){
		return A.size();
	}
	j=i+1;
	while(j<A.size()){
		if(A[j]!=B){
			A[i]=A[j];
			i++;
		}
		j++;
	}
	A.erase(A.begin()+i,A.end());
	print_vector(A);	
	return i;	
}

int main(){
	vector <int> A={1,1,2,3,4,7,7,8,8,8};
	cout<<removeElement(A,3)<<endl;
	return 0;
}