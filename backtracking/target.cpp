#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void update_answer(vector<vector<int>> &ans, vector <int> &temp,vector <int> &A,int lowerlim, int upperlim, int target){
	if(target<0){
		return;
	}
	if(target==0){
		ans.push_back(temp);
		return;
	}
	if(lowerlim>=upperlim) return;
	for(int i=lowerlim;i<upperlim;i++){
		if(i>lowerlim && A[i]==A[i-1]){
			continue;
		}
		if(A[i]<=target){
			temp.push_back(A[i]);
			update_answer(ans,temp,A,i+1,upperlim,target-A[i]);
			temp.erase(temp.end()-1);
		}
		else{
			break;
		}
	}
	return;
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
	sort(A.begin(),A.end());
	//print_vector(A);
	vector<vector<int>>ans;
	vector <int> temp;
	int i=0,j;
	while(i<A.size()){
		if(A[i]<=B){
			i++;
		}
		else{
			break;
		}
	}
	update_answer(ans,temp,A,0,i,B);
	return ans;
}


int main(){
	vector <int> A={10,1,2,7,8,6,1,5};
	int B=8;
	vector <vector <int>>ans=combinationSum(A,B);
	cout<<"final_answer:"<<endl;
	cout<<"ans.size():"<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		print_vector(ans[i]);
	}
	return 0;
}