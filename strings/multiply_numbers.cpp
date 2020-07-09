#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string to_char(int temp){
	char c='0'+temp;
	string ret;
	ret=ret+c;
	return ret;
}

int num(char x){
	return (int)(x-'0');
}



string add_strings(string &A,string &B){
	//A is bigger size string, B is smaller size string
	string sum;
	sum.clear();
	int i,j,k;
	int nB=B.size();
	int nA=A.size();//nB is smaller than nA
	int carry=0;
	int digit;
	for(i=0;i<nB;i++){
		digit=num(B[nB-1-i])+num(A[nA-1-i])+carry;
		carry=digit/10;
		digit=digit%10;
		sum=to_char(digit)+sum;
	}
	//cout<<"sum: "<<sum<<" carry: "<<carry<<endl;
	for(i=nA-nB-1;i>=0;i--){
		digit=num(A[i])+carry;
		carry=digit/10;
		digit=digit%10;
		sum=to_char(digit)+sum;
	}
	if(carry!=0){
		sum=to_char(carry)+sum;
	}
	return sum;
}

string multiply_single(string &A,int x){
	if(x==0){
		string ans;
		ans='0';
		return ans;
	}
	string ans;
	int i;
	int digit,carry=0;
	for(i=A.size()-1;i>=0;i--){
		digit=num(A[i])*x+carry;
		carry=digit/10;
		digit=digit%10;
		cout<<"digit: "<<digit<<" carry: "<<carry<<endl;
		ans=to_char(digit)+ans;
	}
	if(carry!=0){
		ans=to_char(carry)+ans;
	}
	return ans;
}

string multiply(string A, string B) {
	string current,ultimate;
	int i,j,k;
	for(i=0;i<B.size();i++){
		current.clear();
		for(j=0;j<i;j++){
			current+='0';
		}
		current=multiply_single(A,num(B[B.size()-1-i]))+current;
		if(ultimate.size()>current.size()){
			ultimate=add_strings(ultimate,current);
		}
		else{
			ultimate=add_strings(current,ultimate);
		}
	}
	for(i=0;i<ultimate.size() && ultimate[i]=='0';){
		i++;
	}
	ultimate=ultimate.substr(i);
	if(ultimate.size()==0){
		string temp="0";
		return temp;
	}
	return ultimate;
}

int main(){
	string A,B;
	cin>>A>>B;
	cout<<multiply(A,B)<<endl;
	return 0;
}
