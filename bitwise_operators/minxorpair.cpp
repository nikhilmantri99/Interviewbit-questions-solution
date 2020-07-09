#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//for Xor the lesser the difference between corresponding bits in 2 numbers, lesser their XOR value;

int findMinXor(vector <int> &A) {
	int n=A.size();
	sort(A.begin(),A.end());
	int mini=INT_MAX;
	int temp;
	for(int i=0;i<A.size()-1;i++){
		temp=A[i]^A[i+1];
		//cout<<A[i]<<" "<<A[i+1]<<" XOR: "<<temp<<endl;
		if(temp<mini){
			mini=temp;
		}
	}
	return mini;
}

int main(){
	vector <int> A={7,9,0,4};
	cout<<findMinXor(A)<<endl;
	return 0;
}