#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string longestCommonPrefix(vector<string> &A) {
	  
}

int main(){
	int n;
	cin>>n;
	vector <string> A;
	int i;
	for(i=0;i<n;i++){
		string temp;
		cin>>temp;
		A.push_back(temp);
	}
	cout<<longestCommonPrefix(A)<<endl;
	return 0;
}