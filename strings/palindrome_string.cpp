#include <bits/stdc++.h>
using namespace std;

bool isalphanumeric(char &c){
	int temp=c;
	if(temp<=57 && temp>=48){
		return true;
	}
	else if(temp>=65 && temp<=90){
		return true;
	}
	else if(temp>=97 && temp<=122){
		return true;
	}
	return false;
}

bool comparechar(char &a,char&b){
	int temp1=a;
	int temp2=b;
	if(temp1>=48 && temp1<=57){
		if(temp1==temp2){
			return true;
		}
		else{
			return false;
		}
	}
	if(temp2>=48 && temp2<=57){
		if(temp1==temp2){
			return true;
		}
		else{
			return false;
		}
	}
	if(temp1>=97) temp1=temp1-97;
	else if(temp1>=65) temp1=temp1-65;

	if(temp2>=97) temp2=temp2-97;
	else if(temp2>=65) temp2=temp2-65;

	if(temp1==temp2) return true;
	else return false;
}

int isPalindrome(string A) {
	if(A.size()==0) return 1;
	int start=0,end=A.size()-1;
	while(start<=end){
		if(isalphanumeric(A[start])==false){
			start++;
			continue;
		}
		else if(isalphanumeric(A[end])==false){
			end--;
			continue;
		}
		if(comparechar(A[start],A[end])==false){
			return 0;

		}
		start++;
		end--;
	}
	return 1;
}


int main(){
	string x;
	x="race a car";
	cout<<isPalindrome(x)<<endl;
	return 0;
}