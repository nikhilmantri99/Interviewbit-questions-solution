#include <bits/stdc++.h>
#include <iostream>

 using namespace std;

// You are given 3 arrays A, B and C. All 3 of the arrays are sorted.
// Find i, j, k such that :
// max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
// Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))


int maximum(int x, int y, int z){
	if(x>=y && x>=z){
		return x;
	}
	if(y>=x && y>=z){
		return y;
	}
	if(z>=y && z>=x){
		return z;
	}
}

int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int i,j,k;
	i=A.size()-1,j=B.size()-1,k=C.size()-1;
	int max_required=INT_MAX;
	int alternate_i=i,alternate_j=j,alternate_k=k;
	int moves=0;
	while(i>=0 && j>=0 && k>=0){
		int temp=maximum(abs(A[i]-B[j]),abs(B[j]-C[k]),abs(C[k]-A[i]));
		if(temp<=max_required){
			max_required=temp;
		}
		if(temp==abs(A[i]-B[j])){
			if(A[i]>=B[j]){
				i--;
			}
			else{
				j--;
			}
		}
		else if(temp==abs(B[j]-C[k])){
			if(B[j]>=C[k]){
				j--;
			}
			else{
				k--;
			}
		}
		else if(temp==abs(C[k]-A[i])){
			if(C[k]>=A[i]){
				k--;
			}
			else{
				i--;
			}
		}
		moves++;
		if(moves==2){
			if(alternate_i==i && alternate_j==j && alternate_k==k){
				break;
			}
			else{
				moves=0;
				alternate_i=i;
				alternate_j=j;
				alternate_k=k;
			}
		}
	}
	return max_required;
}

int main(){
	vector <int> A={1, 4, 10};
	vector <int> B={2, 15, 20};
	vector <int> C={10, 12};
	cout<<minimize(A,B,C)<<endl;
	return 0;
}