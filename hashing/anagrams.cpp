#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Hint: Anagrams will map to the same string if the characters in the string are sorted


void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

vector<vector<int> > anagrams(const vector<string> &A){	
	unordered_map <string,vector<int>> umap;
	for(int i=0;i<A.size();i++){
		string temp=A[i];
		sort(temp.begin(),temp.end());
		if(umap.find(temp)==umap.end()){
			vector <int> x;
			x.push_back(i+1);
			umap[temp]=x;
		}
		else{
			umap[temp].push_back(i+1);
		}
	}
	vector<vector<int>> ans;
	for(auto x:umap){
		ans.push_back(x.second);
	}
	return ans;
}

int main(){
	vector <string> A={"rasp","dog","luna","god","ogd","nula","sarp"};
	vector<vector<int>> ans=anagrams(A);
	for(int i=0;i<ans.size();i++){
		print_vector(ans[i]);
	}
	return 0;
}