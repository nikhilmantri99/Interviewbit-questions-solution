#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

string convertToTitle(int A) {
	string alphabets="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string temp;
	while(A!=0){
		if(A%26==0){
			temp="Z"+temp;
			A=(A-1)/26;
			continue;
		}
		else{
			temp=alphabets[A%26-1]+temp;
		}
		A=A/26;
	}
	return temp;
}

int main(){
	int x;
	cin>>x;
	cout<<convertToTitle(x)<<endl;
	return 0;
}