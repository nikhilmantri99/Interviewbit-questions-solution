#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_vector (vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void print_grid(vector <vector <int>> &t){
	for(int i=0;i<t.size();i++){
		print_vector(t[i]);
	}
	cout<<endl;
}

void update_ans(vector <vector <int>> &ans,vector <int> &temp, int start, vector <int> &A){
	if(start>=A.size()){
		return;
	}
	int i,j,k;
	for(i=start;i<A.size();i++){
		if(i>start && A[i]==A[i-1]){
			continue;
		}
		temp.push_back(A[i]);
		ans.push_back(temp);
		update_ans(ans,temp,i+1,A);
		temp.erase(temp.end()-1);
	}
	return;
}


vector<vector<int> > subsetsWithDup(vector<int> &A) {
	sort(A.begin(),A.end());
	vector <vector <int>> ans;
	vector <int> temp;
	ans.push_back(temp);
	update_ans(ans,temp,0,A);
	return ans;
}

int main(){
	vector <int> A={1,2,2};
	vector <vector <int>> ans=subsetsWithDup(A);
	print_grid(ans);
	return 0;
}