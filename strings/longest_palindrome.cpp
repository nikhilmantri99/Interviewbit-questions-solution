#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool ispalindrome(string &A,int &i,int &j){
	int start=i;
	int end=j;
	if(start>end){
		return false;
	}
	while(start<=end){
		if(A[start]!=A[end]){
			return false;
		}
		start++;
		end--;
	}
	return true;
}

string longestPalindrome(string &A) {
	bool allsame;
	bool wasprevpalindrome;
	int i,j,n=A.size();
	int start=0, length=1;
	for(i=0;i<n;i++){
		allsame=true;
		wasprevpalindrome=true;
		for(j=i+1;j<n;j++){
			cout<<"checking string === "<<A.substr(i,j-i+1)<<":"<<endl;
			if(allsame==true && A[j]!=A[j-1]){
				cout<<"here1"<<endl;
				allsame=false;
				wasprevpalindrome=false;
			}
			else if(allsame==true && A[j]==A[j-1]){
				cout<<"here2"<<endl;
				if(j-i+1>length){
					cout<<"here3"<<endl;
					length=j-i+1;
					start=i;
					wasprevpalindrome=true;
				}
			}
			else if(allsame==false){
				cout<<"here4"<<endl;
				if(wasprevpalindrome==true){
					cout<<"here5"<<endl;
					wasprevpalindrome=false;
				}
				else if(wasprevpalindrome==false){
					cout<<"here6"<<endl;
					if(ispalindrome(A,i,j)==true){
						cout<<"here7"<<endl;
						if(j-i+1>length){
							cout<<"here8"<<endl;
							length=j-i+1;
							start=i;
							wasprevpalindrome=true;
						}
					}
				}
			}

		}
	}
	string ans;
	cout<<"start: "<<start<<" length: "<<length<<endl;
	ans=A.substr(start,length);
	return ans;
}

int main(){
	string x="100100";
	cout<<longestPalindrome(x)<<endl;
	return 0;
}
