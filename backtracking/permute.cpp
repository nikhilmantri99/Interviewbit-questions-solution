#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void update_answer(vector<vector<int>> &ans, vector <int> &temp, vector <bool> &status, vector <int> &A){
	//cout<<"called"<<endl;
	if(temp.size()==A.size()){
		//cout<<"one done"<<endl;
		//cout<<"Pushing this in:"<<endl;
		//print_vector(temp);
		ans.push_back(temp);
		return;
	}
	int i;
	for(i=0;i<A.size();i++){
		//cout<<A[i]<<" ";
		if(status[i]==false){
			//cout<<"used"<<endl;
			continue;
		}
		else{
			//cout<<"available and recursing"<<endl;
			temp.push_back(A[i]);
			//cout<<"temp: ";
			//print_vector(temp);
			status[i]=false;
			update_answer(ans,temp,status,A);
			temp.erase(temp.end()-1);
			status[i]=true;
		}
	}
}

vector <vector<int> > permute(vector<int> &A){
	int i,j,k;
	vector <bool> status;
	for(i=0;i<A.size();i++){
		status.push_back(true);
	}
	vector<vector<int>> ans;
	vector<int> temp;
	if(A.size()==0) return ans;
	if(A.size()==1) {
		temp.push_back(A[0]);
		ans.push_back(temp);
		return ans;
	}
	update_answer(ans,temp,status,A);
	return ans;
}

int main(){
	vector <int> A={1};
	vector <vector <int>>ans=permute(A);
	cout<<"final_answer:"<<endl;
	cout<<"ans.size():"<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		print_vector(ans[i]);
	}
	return 0;
}