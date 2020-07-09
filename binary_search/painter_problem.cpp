#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define M 10000003

bool isPossible(int A,int B, vector <int> &C,int mid){
	int time_taken=0;
	int painters_used=1;
	for(int i=0;i<C.size();i++){
		time_taken=((time_taken%M)+((C[i]%M)))%M;
		cout<<" "<<time_taken<<" ";
		if(time_taken>=mid){
			i=i-1;
			painters_used++;
			if(painters_used>A){
				return false;
			}
			time_taken=0;
			cout<<time_taken<<" ";
		}
	}
	cout<<" painters_used:"<<painters_used;
	if (painters_used>A) return false;
	else return true;
}

int paint(int A,int B, vector <int> &C){
	int end=M;
	int start=0;
	int mid;
	while(start<=end){
		mid=start+(end-start)/2;
		cout<<mid<<" ";
		if (isPossible(A,B,C,mid)==true){
			cout<<"true"<<endl;
			end=mid-1;
		}
		else{
			cout<<"false"<<endl;
			start=mid+1;
		}
	}
	return (((start-1)%M)*(B%M));
}

int main(){
	int A,B;
	vector <int> C;
	int n;
	cin>>A>>B>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		C.push_back(temp);
	}
	cout<<paint(A,B,C)<<endl;
	return 0;
}