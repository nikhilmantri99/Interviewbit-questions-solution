#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int absolute(int x){
	if(x<0){
		return -1*x;
	}
	else{
		return x;
	}
}

int quotient_overall(int A, int B){ //to return A/B floor without using division, multiplication or mod
	int denom=B;
	int quotient=1;
	if(B==A){
		return 1;
	}
	else if(B>A){
		return 0;
	}
	if(B==1){
		return A;
	}
	if(A==0){
		return 0;
	}
	if(B==0){
		return INT_MAX;
	}
	while(denom+denom<=A){
		denom=denom+denom;
		quotient=quotient+quotient;
	}
	return quotient+quotient_overall(A-denom,B);
}

int divide(int A,int B){
	int sign1=1,sign2=1;
	if(A<0){
		sign1=-1;
	}
	if(B<0){
		sign2=-1;
	}
	return sign1*sign2*quotient_overall(absolute(A),absolute(B));
}

int main(){
	int A,B;
	cin>>A>>B;
	cout<<divide(A,B)<<endl;
	return 0;
}