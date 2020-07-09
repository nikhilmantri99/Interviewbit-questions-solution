#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int binary_search(vector <int> &A, int left, int right, int val){
	int mid=left+(right-left)/2;
	if(left>=A.size()||right>=A.size()) return -1;
	else if(left>right) return -1;
	else if(val==A[mid]) return mid;
	else if(val<A[mid]) return binary_search(A,left,mid-1,val);
	else return binary_search(A,mid+1,right,val);
}

int diffPossible(vector <int> &A, int B) {
	int temp;
	int i,j;
	for(i=0;i<A.size()-1;i++){
		temp=B+A[i];
		if(binary_search(A,i+1,A.size()-1,temp)>=0){
			return 1;
		}
	}
	return 0;
}

int main(){
	vector <int> A={1,4,5,7,9,12};
	int val;
	cin>>val;
	cout<<binary_search(A,0,A.size()-1,val)<<endl;
	return 0;
}