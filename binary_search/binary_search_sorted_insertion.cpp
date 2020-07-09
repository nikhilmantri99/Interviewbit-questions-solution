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
	int x=start;
	if(A[x]<val){
		while(x<A.size()){
			if(A[x]>val){
				return x-1;
			}
			else{
				x++;
			}
		}
		return x;
	}
	if(A[x]>val){
		while(x>0){
			if(A[x]<val){
				return x; 
			}
			else{
				x--;
			}
		}
		return x+1;
	}
}

int main(){
	vector <int> A={2,4,6,8,10};
	cout<<binary_seach_index(A,3)<<endl;
	return 0;
}