#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

//extract first and last digit everytime 

int isPalindrome(int A){
	if(A>=0 && A<=9){
		return 1;
	}
	int divisor=1;
	while(A/divisor>=10){
		divisor=divisor*10;
	}
	//cout<<"divisor: "<<divisor<<endl;
	if(divisor==10){
		if(A%10==A/divisor){
			return 1;
		}
	}
	while(A!=0){
		if(A/divisor==A%10){
			divisor=divisor/100;
			//cout<<"changing A to: ";
			A=(A%divisor)/10;
			//cout<<A<<endl;
			continue;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int main(){
	int n;
	cin>>n;
	cout<<isPalindrome(n)<<endl;
	return 0;
}