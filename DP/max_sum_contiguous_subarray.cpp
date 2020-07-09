#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxi(int a,int b,int c){
	return max(max(a,b),c);
}


//Kadane's algo DP way.
int maxsum(vector <int> &A){
	vector <int> x=A;
	int maxval=x[0],i;
	for(i=1;i<x.size();i++){
		int temp=x[i];
		x[i]=max(temp,temp+x[i-1]);
		maxval=max(maxval,x[i]);
	}
	return maxval;
}

int main(){
	vector <int> A={-2,-3,4,-1,-2,1,5,-3};
	cout<<maxsum(A)<<endl;
	return 0;
}