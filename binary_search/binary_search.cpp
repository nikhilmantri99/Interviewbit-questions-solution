#include <bits/stdc++.h>
using namespace std;

int binary_seach_index(vector <int> &A,int val){
	int start=0,end=A.size()-1,mid;
	while(start<=end){
		mid=(start+end)/2;
		if(A[mid]==val){
			return mid;
		}
		else if(A[mid]>val){
			end=mid-1;
		}
		else if(A[mid]<val){
			start=mid+1;
		}
	}
	return -1;//if not found;
}

int main(){
	vector <int> A={2,4,6,8,10};
	cout<<binary_seach_index(A,10)<<endl;
	return 0;
}