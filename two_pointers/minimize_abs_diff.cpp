#include <bits/stdc++.h>
#include <iostream>

 using namespace std;

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

int minimum(int x, int y, int z){
	if(x<=y && x<=z){
		return x;
	}
	if(y<=x && y<=z){
		return y;
	}
	if(z<=y && z<=x){
		return z;
	}
}

// follow one approach either decrease the maximum by starting at the ends if the arrays or increment the minimum 
// by starting at the minimum of all the arrays.
// Dont go on doing both together. Also put an alternate infinte loop condition.
int solve(vector<int> &A, vector<int> &B, vector<int> &C) {
	int i,j,k; 
	i=0;
	j=0;
	k=0;
	int diff=INT_MAX;
	int alternate_i=0,alternate_j=0,alternate_k=0,moves=0;
	while(i<A.size() && j<B.size() && k<C.size()){
		cout<<" i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
		int maxi=maximum(A[i],B[j],C[k]);
		int mini=minimum(A[i],B[j],C[k]);
		if(abs(maxi-mini)<diff) diff=abs(maxi-mini);
		
		if(A[i]==mini){
			if(i<A.size()){
				i++;
			}	
		}
		if(B[j]==mini){
			if(j<B.size()){
				j++;
			}
		}
		if(C[k]==mini){
			if(k<C.size()){
				k++;
			}
		}
		moves++;
		if(moves==2){
			if(i==alternate_i && j==alternate_j && k==alternate_k){
				break;
			}
			moves=0;
			alternate_i=i;
			alternate_j=j;
			alternate_k=k;
		}
	}
	return diff;
}

int main(){
	vector <int> A={ 1, 4, 5, 8, 10  };
	vector <int> B={ 6, 9, 10};
	vector <int> C={2, 3, 6, 10};
	cout<<solve(A,B,C)<<endl;
	return 0;
}
