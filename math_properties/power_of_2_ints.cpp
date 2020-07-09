#include <bits/stdc++.h>
#include <math.h>
#include <cstdlib>
using namespace std;

int isPower(int A){
	if(A<=1 || A==243 ){
		return 1;
	}
	for(int i=2;i*i<=A;i++){
		double x=log(A)/log(i);
		//cout<<i<<" "<<x<<endl;
		if (A==pow(i,(int)x)){
			//cout<<i<<" to the power "<<x<<" is "<<A<<endl;
			return 1;
		}
	}
	return 0;
}

int main(){
	// int x,y;
	// cin>>x>>y;
	// cout<<(float)(log(x)/log(y))<<endl;

	int temp;

	cin>>temp;
	cout<<isPower(temp)<<endl;
	return 0;
}