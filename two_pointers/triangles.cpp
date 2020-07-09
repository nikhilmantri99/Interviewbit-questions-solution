#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int binary_search_just_greatest_index(vector <int> &A, int left, int right, int val){
	if(val<A[left]){
		return left;
	}
	if(left>=A.size()||right>=A.size()){
		return -1;
	}
	if(left>right){
		return -1;
	}
	int mid=(left+right)/2;
	//cout<<"left:"<<left<<" right:"<<right<<" mid:"<<mid<<"-----";
	if(A[mid]==val){
		return mid;
	}
	else if(mid>0 && A[mid]>=val && A[mid-1]<val){
		//cout<<"here1"<<endl;
		return mid;
	}
	else if(mid==A.size()-1 && A[mid]<val){
		//cout<<"here2"<<endl;
		return A.size();
	}
	else if(val<A[mid]){
		//cout<<"here3"<<endl;
		return binary_search_just_greatest_index(A,left,mid-1,val);
	}
	else{
		//cout<<"here4"<<endl;
		return binary_search_just_greatest_index(A,mid+1,right,val);
	}
}


int nTriang(vector<int> &A) {
	sort(A.begin(),A.end());
	print_vector(A);
	int i,j,k;
	int sum=0;
	for(i=0;i<A.size()-2;i++){
		for(j=i+1;j<A.size()-1;j++){
			int apb=A[i]+A[j];
			int index=binary_search_just_greatest_index(A,j+1,A.size()-1,apb);
			if(index==-1){
				continue;
			}
			if(index-j-1>0){
				sum+=index-j-1;
			}
		}
	}
	return sum;
}

int main(){
	vector <int> A={2,2,1,1,1};
	//int temp;
	//cin>>temp;
	cout<<nTriang(A)<<endl;
	return 0;
}
