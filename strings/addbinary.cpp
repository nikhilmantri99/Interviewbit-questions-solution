#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string to_char(int temp){
	char c='0'+temp;
	string ret;
	ret=ret+c;
	return ret;
}

int num(char &t){
	return (int)(t-'0');
}

string add(string &x,string &y){//sizeof x is greater than or equal to y
	string ans;
	int nx=x.size(),ny=y.size();
	int i,j,k,carry=0;
	for(i=0;i<ny;i++){
		//cout<<"i: "<<i<<" ans: "<<ans;
		int temp=carry+num(x[nx-1-i])+num(y[ny-1-i]);
		//cout<<" temp: "<<temp<<endl;
		if(temp<=1){
			ans=to_char(temp)+ans;
			carry=0;
		}
		else if(temp==2){
			ans=to_char(0)+ans;
			carry=1;
		}
		else if(temp==3){
			ans=to_char(1)+ans;
			carry=1;
		}
	}
	for(i=nx-ny-1;i>=0;i--){
		int temp=carry+num(x[i]);
		if(temp<=1){
			ans=to_char(temp)+ans;
			carry=0;
		}
		else if(temp==2){
			ans=to_char(0)+ans;
			carry=1;
		}
		else if(temp==3){
			ans=to_char(1)+ans;
			carry=1;
		}
	}
	if(carry!=0){
		int temp=carry;
		if(temp<=1){
			ans=to_char(temp)+ans;
			carry=0;
		}
		else if(temp==2){
			ans=to_char(0)+ans;
			carry=1;
		}
		else if(temp==3){
			ans=to_char(1)+ans;
			carry=1;
		}
	}
	//cout<<"ans: "<<ans<<endl;
	return ans;
}

string addBinary(string A, string B) {
    if (A.size()>=B.size()) return add(A,B);
    else return add(B,A);
}

int main(){
	string A="1100110";
	string B="10101010";
	cout<<addBinary(A,B)<<endl;
	return 0;
}