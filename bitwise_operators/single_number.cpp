#include <bits/stdc++.h>
#include <iostream>

using namespace std;



// Let us look at every bit position.
// Every number that occurs twice will either contribute 2 ‘1’s or 2 ‘0’s to the position.
// The number that occurs once-‘X’ will contribute exactly one 0 or 1 to the position depending on whether it has 0 or 1 in that position.
// So:
//     If X has 1 in that position, we will have odd number of 1s in that position.
//     If X has 0 in that position, we will have odd number of 0s in that position.
// Can you think of a solution using the above observation?

void print_vector(vector <int> &b){
	for(int i=0;i<b.size();i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
}

int singleNumber(const vector <int> &A){
	vector <int> bits;
	int i,j,k,n=A.size();
	for(i=0;i<31;i++){
		bits.push_back(0);
	}
	for(i=0;i<n;i++){
		int temp=A[i];
		j=0;
		while(temp!=0){
			bits[j]+=temp%2;
			temp=temp/2;
			j++;
		}
	}
	long int ans=0;
	for(i=0;i<bits.size();i++){
		if((bits[i]%2)==1){
			ans+=(int)(pow(2,i)+0.5);
		}
	}
	print_vector(bits);
	return (int)ans;
}

int main(){
	vector <int> A={2,2,5,6,7,9,6,7,9};
	cout<<singleNumber(A)<<endl;
	return 0;
}