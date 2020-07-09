#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//QUESTION:
// Generate n-bit Gray Codes
// Given a number n, generate bit patterns from 0 to 2^n-1 such that successive patterns differ by one bit. 

// //ANSWER:
// n-bit Gray Codes can be generated from list of (n-1)-bit Gray codes using following steps.
// 1) Let the list of (n-1)-bit Gray codes be L1. Create another list L2 which is reverse of L1.
// 2) Modify the list L1 by prefixing a ‘0’ in all codes of L1.
// 3) Modify the list L2 by prefixing a ‘1’ in all codes of L2.
// 4) Concatenate L1 and L2. The concatenated list is required list of n-bit Gray codes.



void print_vector(vector <int> &x){
	if(x.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int binary_to_int(string &x){
	int temp=0;
	for(int i=x.size()-1;i>=0;i--){
		temp+=pow(2,x.size()-1-i)*(x[i]-'0');
	}
	return temp;
}

void update_Graycode(int A, vector <string> &ans){
	if(A==1){
		string temp;
		temp.push_back('0');
		ans.push_back(temp);
		temp.clear();
		temp.push_back('1');
		ans.push_back(temp);
		temp.clear();
		return;
	}
	else{
		update_Graycode(A-1,ans);
		int n=ans.size();
		int j=n-1;
		while(j>=0){
			ans.push_back(ans[j]);
			j--;
		}
		for(j=0;j<n;j++){
			ans[j]="0"+ans[j];
		}
		for(j=n;j<2*n;j++){
			ans[j]="1"+ans[j];
		}
		return;
	}
}

vector <int> grayCode(int A) {
    vector <string> ans;
    update_Graycode(A,ans);
    cout<<"binary:"<<endl;
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<endl;
    }
    vector <int> answer;
    for(int i=0;i<ans.size();i++){
    	answer.push_back(binary_to_int(ans[i]));
    }
    return answer;
}

int main(){
	int A;
	cin>>A;
	vector <int> ans=grayCode(A);
	print_vector(ans);
	return 0;
}