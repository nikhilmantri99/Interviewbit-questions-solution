#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isNum(const string &A,int i){
	if(A[i]-'0'>9 || A[i]-'0'<0){
		return false;
	}
	return true;
}

bool isNumber(const string A){
	int i=0;
	int sign=0;
	if(A[i]=='+'||A[i]=='-'){
		i++;
		sign++;
	}
	int decimal=0;
	int exp=0;
	while(i<A.size()){
		if(isNum(A,i)==false){
			if(A[i]=='.'){
				if(i== A.size()-1) return false;
				if(decimal==0) {
					if(exp>0) return 0;
					i++;
					decimal++;
					continue;
				}
				else if(decimal>0){
					return false;
				}
				if(exp>0){
					return false;
				}
			}
			else if(A[i]=='e'){
				if(i==0 || i== A.size()-1) return false;
				if(exp==0) {
					exp++;
					sign=0;
					int j=i+1;
					if(A[j]=='+'||A[j]=='-'){
						i=j+1;
						continue;
					}
					i++;
					continue;
				}
				else if(exp>0){
					return false;
				}
			}
			else{
				return false;
			}
		}
		i++;
	}
	return true;
}

int main(){
	string A;
	cin>>A;
	cout<<isNumber(A)<<endl;
	return 0;
}