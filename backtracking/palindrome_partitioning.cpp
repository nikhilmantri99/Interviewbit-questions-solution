#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <string> &x){
	if(x.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

bool is_palindrome(string &A, int i,int j){
	if(i>=j){
		return true;
	}
	else if(A[i]!=A[j]) return false;
	else{
		return is_palindrome(A,i+1,j-1);
	}
}

void update_partitions(vector<vector<string>> &ans,vector <string> &temp, string &A,int lowerlim, int upperlim){
	if(lowerlim>upperlim){
		ans.push_back(temp);
		return;
	}
	for(int j=lowerlim;j<=upperlim;j++){
		if(is_palindrome(A,lowerlim,j)==true){
			temp.push_back(A.substr(lowerlim,j-lowerlim+1));
			update_partitions(ans,temp,A,j+1,upperlim);
			temp.erase(temp.end()-1);
		}
	}
	return;
}

vector<vector<string>> partition(string A) {
	vector <vector<string>>ans;
	vector <string> temp;
	update_partitions(ans,temp,A,0,A.size()-1);
	return ans;
}

int main(){
	string A="aabbaa";
	vector <vector<string>> ans=partition(A);
	for(int i=0;i<ans.size();i++){
		print_vector(ans[i]);
	}
	return 0;
}