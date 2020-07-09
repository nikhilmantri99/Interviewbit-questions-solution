#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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

void update_answer(vector<vector<int>> &ans, vector <int> &temp, int lowerlim, int upperlim, int k){
	if(temp.size()==k){
		ans.push_back(temp);
	}
	if(lowerlim>=upperlim){
		return;
	}
	for(int i=lowerlim;i<upperlim;i++){
		temp.push_back(i);
		update_answer(ans,temp,i+1,upperlim,k);
		temp.erase(temp.end()-1);
	}
	return;
}

vector <vector<int>> combine(int A, int B) {
	vector <vector<int>> ans;
	vector <int> temp;
	update_answer(ans,temp,1,A+1,B);
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector <vector <int>>ans=combine(n,k);
	cout<<"final_answer:"<<endl;
	cout<<"ans.size():"<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		print_vector(ans[i]);
	}
	return 0;

}
