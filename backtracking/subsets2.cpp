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

void update_answer( vector<vector<int>> &ans, vector <int> &temp, vector <int> &A,int lowerlim, int upperlim ){
	ans.push_back(temp);
	if(lowerlim>=upperlim){
		return;
	}
	if(temp.size()==A.size()){
		return;
	}
	for(int i=lowerlim;i<upperlim;i++){
		if(i>lowerlim && A[i]==A[i-1]){
			continue;
		}
		else{
			temp.push_back(A[i]);
			update_answer(ans,temp,A,i+1,upperlim);
			temp.erase(temp.end()-1);
		}
	}
	return;
}

vector <vector<int>> subsetsWithDup(vector<int> &A) {
    vector <vector<int>> ans;
    vector <int> temp;
    sort(A.begin(),A.end());
    update_answer(ans,temp,A,0,A.size());
    return ans;
}

int main(){
	vector <int> A={1,2,2};
	vector <vector <int>>ans=subsetsWithDup(A);
	cout<<"final_answer:"<<endl;
	cout<<"ans.size():"<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		print_vector(ans[i]);
	}
	return 0;
}
