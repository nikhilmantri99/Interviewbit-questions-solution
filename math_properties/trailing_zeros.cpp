#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int A) {
	int zeros=0;
	while(A!=0){
		zeros+=A/5;
		A=A/5;
	}
	return zeros;
}

int main(){
	int n;
	cin>>n;
	cout<<"factorial "<<n<<" has "<<trailingZeroes(n)<<" zeros";
	return 0;
}
