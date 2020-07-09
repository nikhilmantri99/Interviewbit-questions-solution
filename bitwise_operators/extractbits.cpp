#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//x & ~(x-1)

int numSetBits(unsigned int A) {
	int count=0;
	while(A!=0){
		int temp = (A & ~(A-1));// this will return the last bit (or the bit at 2^0 position)
		cout<<temp<<endl;
		if (temp==1){
			count++;
		}
		A=A>>1;
	}
	return count;
}

int main(){
	unsigned int A;
	cin>>A;
	cout<<numSetBits(A)<<endl;
	return 0;
}
