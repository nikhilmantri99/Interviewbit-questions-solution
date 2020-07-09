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

void update_answer(vector<vector<int>> &ans, vector <int> &temp,vector <int> &A,int lowerlim, int upperlim, int target){
	if(target==0){
		ans.push_back(temp);
		return;
	}
	else if(lowerlim>=upperlim){
		return;
	}
	else{
		for(int i=lowerlim;i<upperlim;i++){
			if(i>lowerlim && A[i]==A[i-1]){
				continue;
			}
			if(A[i]<=target){
				temp.push_back(A[i]);
				update_answer(ans,temp,A,i,upperlim,target-A[i]);
				temp.erase(temp.end()-1);
			}
			else{
				break;
			}
		}
	}
	return;
}

vector<vector<int>> combinationSum(vector<int> &A, int B) {
	vector <vector<int>> ans;
	vector <int> temp;
	sort(A.begin(),A.end());
	update_answer(ans,temp,A,0,A.size(),B);
	return ans;
}

int main(){
	vector <int> A={2,2,2,3,6,7};
	int target=7;
	vector <vector <int>>ans=combinationSum(A,target);
	cout<<"final_answer:"<<endl;
	cout<<"ans.size():"<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		print_vector(ans[i]);
	}
	return 0;

}