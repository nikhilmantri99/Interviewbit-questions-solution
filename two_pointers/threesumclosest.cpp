#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void binary_search(vector <int> &A, int left, int right, int val, int &temp,int &closest){
	if(left>=A.size() || right>=A.size()){
		return;
	}
	if(left>right){
		return ;
	}
	int mid=(left+right)/2;
	if(A[mid]==val){
		temp = 0;
		closest=A[mid];
		return;
	}
	if(val<A[mid]){
		if(A[mid]-val<temp){
			temp=A[mid]-val;
			closest=A[mid];
		}
		return binary_search(A,left,mid-1,val,temp,closest);
	}
	else{
		if(val-A[mid]<temp) {
			temp=val-A[mid];
			closest=A[mid];
		}
		return binary_search(A,mid+1,right,val,temp,closest);
	}
}

int threeSumClosest(vector<int> &A, int B) {
	int i,j,k;
	sort(A.begin(),A.end());
	print_vector(A);
	i=0;
	int localsum, sum=INT_MAX,absolutediff=INT_MAX;
	while(i<A.size()){
		if(i>0 && A[i]==A[i-1]){
			i++;
			continue;
		}
		else{
			j=i+1;
			while(j<A.size()){
				if(j>i+1 && A[j]==A[j-1]){
					j++;
					continue;
				}
				int apb=B-A[i];
				int a=apb-A[j];
				int closest=INT_MAX;
				int temp=INT_MAX;
				binary_search(A,j+1,A.size()-1,a,temp,closest);
				if(closest==INT_MAX){
					j++;
					continue;
				}
				cout<<"closest: "<<closest;
				localsum=A[i]+A[j]+closest;
				cout<<" localsum: "<<localsum<<endl;
				if(abs(B-localsum)<absolutediff){
					sum=localsum;
					absolutediff=abs(B-localsum);
				}
				j++;
			}
			i++;
		}
	}
	return sum;
}


int main(){
	vector <int> A={-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3 };
	int target=-1;
	int sum=threeSumClosest(A,target);
	cout<<sum<<endl;
	return 0;
}