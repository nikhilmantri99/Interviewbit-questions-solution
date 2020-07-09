// Given an string A. The only operation allowed is to insert characters in the beginning of the string.
// Find how many minimum characters are needed to be inserted to make the string a palindrome string.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(string A) {
	string rev;
	rev.clear();
	int i,j,k,n=A.size();
	for(i=n-1;i>=0;i--){
		rev=rev+A[i];
	}
	cout<<"original : "<<A<<endl;
	cout<<"reverse : "<<rev<<endl;
	for(i=0;i<n;i++){
		if(A[0]==rev[i]){
			cout<<"new"<<endl;
			int matches=0;
			for(j=i;j<n;j++){
				if(A[j-i]==rev[j]){
					cout<<"j-i: "<<j-i<<" j: "<<j<<endl;
					matches++;
				}
				else{
					break;
				}
			}
			cout<<"matches:"<<matches<<endl;
			cout<<"--------"<<endl;
			if((i+matches)==n){
				return (n-matches);
			}
			else{
				i=i+matches-1;
			}
		}
	}
	return n-1;
}

int main(){
	string X="CDEDCBA";
	string Y="AACECAAAA";
	string Z="XYZ";
	string T="aaaaa";
	string G="mmtatbdzqsoemuvnpppsu";
	cout<<solve(G)<<endl;
	return 0;
}
