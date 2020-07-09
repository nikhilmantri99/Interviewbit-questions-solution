#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int cpfact(int A,int B){
	int X=A;
	while(X>1){
		//cout<<X<<endl;
		if(A%X==0 && gcd(X,B)==1){
			return X;
		}
		else{
			X=X/gcd(X,B);
		}
	}
	return 1;
}

int main(){
	int A, B;
	cin>>A>>B;
	cout<<cpfact(A,B)<<endl;
}